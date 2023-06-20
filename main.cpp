#include <iostream>
#include "Grapher.h"

typedef std::vector<Equation*> eq;

int main() {

    std::vector<sf::Color*> lineColors = {new sf::Color(255, 0, 0), new sf::Color(0, 255, 0), new sf::Color(0, 0, 255), new sf::Color(255, 255, 0), new sf::Color(0, 255, 255), new sf::Color(255, 0, 255), new sf::Color(255, 255, 255)};

    Grapher grapher(new std::vector<Statement*>());
    grapher.displayGraph(800, &lineColors, sf::Color(0, 0, 20), sf::Color::Color::White, sf::Color::Color::White, -15, 15, -15, 15, 0.01, 1000, 5);
    return 0;
}
