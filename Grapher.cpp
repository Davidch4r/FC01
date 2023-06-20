//
// Created by David Pidugu on 6/16/23.
//

#include "Grapher.h"

Grapher::Grapher(std::vector<Statement*>* statements) {
    this->statements = statements;
    this->statementColors = new std::vector<sf::Color*>();
}

void Grapher::displayGraph(float size, std::vector<sf::Color*>* lineColors, sf::Color backgroundColor, sf::Color axisColor, sf::Color fontColor, float xMin, float xMax, float yMin, float yMax, float step, int SUB_STEPS, float PIXELS_PER_UNIT) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    int fontSize = 50;

    sf::RenderWindow window(sf::VideoMode(size, size + 3 * fontSize / 2), "Graph", sf::Style::Titlebar | sf::Style::Close);
    std::string textBox;
    sf::Font font;
    if (!font.loadFromFile("Fonts/BebasNeue-Regular.ttf"))
        std::cout << "Error loading font" << std::endl;

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(fontSize);
    text.setFillColor(fontColor);
    text.setPosition(0, size);

    this->backgroundColor = backgroundColor;
    this->lineColors = lineColors;

    float xIn = xMin;
    float yIn = yMax;

    renderTexture = new sf::RenderTexture();

    renderTexture->create(size, size);
    renderTexture->clear(sf::Color::Transparent);

    drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
            } else if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == 8) {
                    if (!textBox.empty())
                        textBox.pop_back();
                } else if (event.text.unicode == 10) {
                    if (!textBox.empty()) {
                        if (textBox.substr(0, textBox.find(' ')) == "CLEAR") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount == "ALL") {
                                this->clearGraph();
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            } else if (amount != " "){
                                int index = std::stoi(amount) - 1;
                                if (index < statements->size()) {
                                    this->clearStatement(index);
                                    drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                    xIn = xMin;
                                    yIn = yMin;
                                }
                            }
                        } else {
                            AtoS(textBox);
                            xIn = xMin;
                            yIn = yMin;
                        }
                        textBox.clear();
                    }
                } else {
                    textBox += toupper(static_cast<char>(event.text.unicode));
                }
                text.setString(textBox + "_");
                if (text.getLocalBounds().width > size) {
                    fontSize *= 0.9;
                    text.setCharacterSize(fontSize);
                }


            }
        }
        window.clear(backgroundColor);
        if (xIn <= xMax)
            // Draw points
            for (int j = 0; j < SUB_STEPS; j++) {
                auto* point = new std::vector<float>({xIn, yIn});
                for (int k = 0; k < statements->size(); k++) {
                    Statement* statement = statements->at(k);
                    if (statement->isSolved(point, step)) {
                        float x = (point->at(0) - xMin) / (xMax - xMin) * size;
                        float y = (point->at(1) - yMin) / (yMax - yMin) * size;
                        sf::RectangleShape pointShape(sf::Vector2f(PIXELS_PER_UNIT, PIXELS_PER_UNIT));
                        pointShape.setPosition(x, y);
                        pointShape.setFillColor(*statementColors->at(k));
                        renderTexture->draw(pointShape);
                    }
                }
                if (yIn < yMax) {
                    yIn += step;
                } else {
                    yIn = yMin;
                    xIn += step;
                }
                // Fix floating point
                xIn = roundf(xIn / step) * step;
                yIn = roundf(yIn / step) * step;

            } else {
                xIn = xMin;
                yIn = yMax;
            }
        window.draw(sf::Sprite(renderTexture->getTexture()));
        window.draw(text);
        window.display();
    }
}

void Grapher::clearGraph() {
    statements->clear();
    statementColors->clear();
}

void Grapher::clearStatement(int index) {
    statements->erase(statements->begin() + index);
    statementColors->erase(statementColors->begin() + index);
}

void Grapher::addStatement(Statement* statement) {
    statements->emplace_back(statement);
    statementColors->emplace_back(lineColors->at(colorCounter % lineColors->size()));
    colorCounter++;
}

void Grapher::AtoS(const std::string& statement) {
    addStatement(new Statement(statement));
}

void Grapher::drawGraphAxis(float xMin, float xMax, float yMin, float yMax, float size, sf::Color axisColor, float PIXELS_PER_UNIT) const {
    float xAxisOffset = -xMin / (xMax - xMin) * size;
    float yAxisOffset = -yMin / (yMax - yMin) * size;

    renderTexture->clear(sf::Color::Transparent);

    // Draw axis
    sf::RectangleShape xAxis(sf::Vector2f(size, PIXELS_PER_UNIT));
    xAxis.setPosition(0, xAxisOffset);
    xAxis.setFillColor(axisColor);
    renderTexture->draw(xAxis);
    sf::RectangleShape yAxis(sf::Vector2f(PIXELS_PER_UNIT, size));
    yAxis.setPosition(yAxisOffset, 0);
    yAxis.setFillColor(axisColor);
    renderTexture->draw(yAxis);

    // Draw integer markers
    for (float i = xMin; i < xMax; i++) {
        sf::RectangleShape marker(sf::Vector2f(1, size));
        marker.setPosition((i - xMin) / (xMax - xMin) * size, 0);
        marker.setFillColor(sf::Color(axisColor.r, axisColor.g, axisColor.b, 100));
        renderTexture->draw(marker);
    }
    for (float i = yMin; i < yMax; i++) {
        sf::RectangleShape marker(sf::Vector2f(size, 1));
        marker.setPosition(0, size - (i - yMin) / (yMax - yMin) * size);
        marker.setFillColor(sf::Color(axisColor.r, axisColor.g, axisColor.b, 100));
        renderTexture->draw(marker);
    }
}






