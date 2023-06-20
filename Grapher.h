//
// Created by David Pidugu on 6/16/23.
//

#ifndef FC01_GRAPHER_H
#define FC01_GRAPHER_H

#include <iostream>
#include "Equation.h"
#include "SFML/Graphics.hpp"
#include "SFML/Graphics/Font.hpp"
#include "Statement.h"
#include <queue>



class Grapher {
public:
    Grapher(std::vector<Statement*>* statements);
    void displayGraph(float size, std::vector<sf::Color*>* lineColors, sf::Color backgroundColor, sf::Color axisColor, sf::Color fontColor, float xMin, float xMax, float yMin, float yMax, float step, int SUB_STEPS, float PIXELS_PER_UNIT);
    void clearGraph();
    void clearStatement(int index);
    void addStatement(Statement* statement);
    void AtoS(const std::string& statement);
private:
    std::vector<Statement*>* statements;
    std::vector<sf::Color*>* statementColors;
    sf::RenderTexture* renderTexture;
    sf::Color backgroundColor;
    std::vector<sf::Color*>* lineColors;
    int colorCounter = 0;

    void drawGraphAxis(float xMin, float xMax, float yMin, float yMax, float size, sf::Color axisColor, float PIXELS_PER_UNIT) const;
};


#endif //FC01_GRAPHER_H
