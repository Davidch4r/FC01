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
                        std::string firstWord = textBox.substr(0, textBox.find(' '));
                        if (firstWord == "CLEAR") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount == "ALL") {
                                this->clearGraph();
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }else if (amount == "COLORS") {
                                this->statementColors->clear();
                                this->lineColors->clear();
                                colorCounter = 0;
                                xIn = xMin;
                                yIn = yMin;
                            } else if (amount == "LAST") {
                                if (!statements->empty()) {
                                    this->clearStatement(statements->size() - 1);
                                    drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                    xIn = xMin;
                                    yIn = yMin;
                                }
                            } else if (amount != " "){
                                int index = std::stoi(amount) - 1;
                                if (index < statements->size()) {
                                    this->clearStatement(index);
                                    drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                    xIn = xMin;
                                    yIn = yMin;
                                }
                            }
                        } else if (firstWord == "QUIT") {
                            window.close();
                            break;
                        } else if (firstWord == "SIZE")  {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                size = std::stof(amount);
                                window.setSize(sf::Vector2u(size, size + 3 * fontSize / 2));
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "STEP") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                step = std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "XMIN") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                xMin = std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "XMAX") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                xMax = std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "YMIN") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                yMin = std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "YMAX") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                yMax = std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "BOUND") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                float bound = std::stof(amount);
                                xMin = -bound;
                                xMax = bound;
                                yMin = -bound;
                                yMax = bound;
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "LEFT") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                xMin -= std::stof(amount);
                                xMax -= std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "RIGHT") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                xMin += std::stof(amount);
                                xMax += std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "DOWN") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                yMin -= std::stof(amount);
                                yMax -= std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "UP") {
                            std::string amount = textBox.substr(textBox.find(' ') + 1);
                            if (amount != " ") {
                                yMin += std::stof(amount);
                                yMax += std::stof(amount);
                                drawGraphAxis(xMin, xMax, yMin, yMax, size, axisColor, PIXELS_PER_UNIT);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else if (firstWord == "ADDCOLOR") {
                            std::string rgbVals = textBox.substr(textBox.find(' ') + 1);
                            if (rgbVals != " ") {
                                std::string r = rgbVals.substr(0, rgbVals.find(' '));
                                std::string g = rgbVals.substr(rgbVals.find(' ') + 1, rgbVals.find(' ', rgbVals.find(' ') + 1));
                                std::string b = rgbVals.substr(rgbVals.find(' ', rgbVals.find(' ') + 1) + 1);
                                auto* color = new sf::Color(std::stoi(r), std::stoi(g), std::stoi(b));
                                statementColors->emplace_back(color);
                                lineColors->emplace_back(color);
                                xIn = xMin;
                                yIn = yMin;
                            }
                        } else {
                            AtoS(textBox);
                            xIn = xMin;
                            yIn = yMin;
                        }
                        fontSize = 50;
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
                        sf::Color* color;
                        if (statementColors->size() <= k) {
                            color = new sf::Color(255, 255, 255);
                        } else {
                            color = statementColors->at(k);
                        }
                        pointShape.setPosition(x, y);
                        pointShape.setFillColor(*color);
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
    if (!lineColors->empty()) {
        statementColors->emplace_back(lineColors->at(colorCounter % lineColors->size()));
        colorCounter++;
    }
}

void Grapher::AtoS(const std::string& statement) {
    addStatement(new Statement(statement));
}

void Grapher::drawGraphAxis(float xMin, float xMax, float yMin, float yMax, float size, sf::Color axisColor, float PIXELS_PER_UNIT) const {
    float xAxisOffset = -xMin / (xMax - xMin) * size;
    float yAxisOffset = -yMin / (yMax - yMin) * size;

    renderTexture->setView(sf::View(sf::FloatRect(0, 0, size, size)));
    renderTexture->clear(sf::Color::Transparent);

    // Draw axis
    sf::RectangleShape xAxis(sf::Vector2f(size, PIXELS_PER_UNIT));
    xAxis.setPosition(0, yAxisOffset);
    xAxis.setFillColor(axisColor);
    renderTexture->draw(xAxis);
    sf::RectangleShape yAxis(sf::Vector2f(PIXELS_PER_UNIT, size));
    yAxis.setPosition(xAxisOffset, 0);
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






