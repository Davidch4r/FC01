//
// Created by David Pidugu on 6/16/23.
//

#ifndef FC01_GRAPHER_H
#define FC01_GRAPHER_H

#include <iostream>
#include "Equation.h"
#include "SFML/Graphics.hpp"
#include "Statement.h"
#include <queue>


class Grapher {
public:
    Grapher(std::vector<Statement*>* statements);
    void displayGraph(float size, std::vector<sf::Color>* lineColors, sf::Color backgroundColor, sf::Color axisColor, float xMin, float xMax, float yMin, float yMax, float step, int SUB_STEPS, float PIXELS_PER_UNIT);
    void clearGraph();
    void clearStatement(int index);
    void addStatement(Statement* statement);
    Statement atoiStatement(std::string statement);
private:
    std::vector<Statement*>* statements;
    sf::RenderTexture renderTexture;
    sf::Color backgroundColor;
    std::vector<sf::Color>* lineColors;
};


#endif //FC01_GRAPHER_H
