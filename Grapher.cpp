//
// Created by David Pidugu on 6/16/23.
//

#include "Grapher.h"

Grapher::Grapher(std::vector<Statement*>* statements) {
    this->statements = statements;
}


void Grapher::displayGraph(int size, std::vector<sf::Color>* lineColors, sf::Color backgroundColor, sf::Color axisColor, float xMin, float xMax, float yMin, float yMax, float step, int SUB_STEPS, float PIXELS_PER_UNIT) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    sf::RenderWindow window(sf::VideoMode(size, size + size/10), "Graph");

    float xIn = xMin;
    float yIn = yMax;

    sf::RenderTexture renderTexture;
    renderTexture.create(size, size);
    renderTexture.clear(sf::Color::Transparent);

    float xAxisOffset = -xMin / (xMax - xMin) * size;
    float yAxisOffset = -yMin / (yMax - yMin) * size;

    // Draw axis
    sf::RectangleShape xAxis(sf::Vector2f(size, PIXELS_PER_UNIT));
    xAxis.setPosition(0, xAxisOffset);
    xAxis.setFillColor(axisColor);
    renderTexture.draw(xAxis);
    sf::RectangleShape yAxis(sf::Vector2f(PIXELS_PER_UNIT, size));
    yAxis.setPosition(yAxisOffset, 0);
    yAxis.setFillColor(axisColor);
    renderTexture.draw(yAxis);

    // Draw integer markers
    for (int i = xMin; i < xMax; i++) {
        sf::RectangleShape marker(sf::Vector2f(1, size));
        marker.setPosition((i - xMin) / (xMax - xMin) * size, 0);
        marker.setFillColor(sf::Color(axisColor.r, axisColor.g, axisColor.b, 100));
        renderTexture.draw(marker);
    }
    for (int i = yMin; i < yMax; i++) {
        sf::RectangleShape marker(sf::Vector2f(size, 1));
        marker.setPosition(0, size - (i - yMin) / (yMax - yMin) * size);
        marker.setFillColor(sf::Color(axisColor.r, axisColor.g, axisColor.b, 100));
        renderTexture.draw(marker);
    }


    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                break;
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
                        pointShape.setFillColor(lineColors->at(k));
                        renderTexture.draw(pointShape);
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
                statements->clear();
            }
        window.draw(sf::Sprite(renderTexture.getTexture()));
        window.display();
    }
}




