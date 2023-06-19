#include <iostream>
#include "Grapher.h"

typedef std::vector<Equation*> eq;

int main() {
    // Circle 1
    auto* X1 = new Variable(new eq({new Constant(0)}));
    auto* Y1 = new Variable(new eq({new Constant(0)}));
    auto* H = new Constant(0);
    auto* K = new Constant(0);
    auto* R = new Constant(5);
    auto* fx = new Add(new eq({
        new Exponential(new eq({new Subtract(new eq({X1, H})), new Constant(2)})),
        new Exponential(new eq({new Subtract(new eq({Y1, K})), new Constant(2)}))
    }));
    auto* gx = new Exponential(new eq({R, new Constant(2)}));
    auto* statement1 = new Statement(new eq({X1, Y1}), new eq({fx, gx}));


    std::vector<Statement*> statements = {statement1};
    std::vector<sf::Color> lineColors = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta};

    Grapher grapher(&statements);
    grapher.displayGraph(800, &lineColors, sf::Color(0, 0, 20), sf::Color::Color::White, sf::Color::Color::White, -15, 15, -15, 15, 0.01, 1000, 5);
    return 0;
}
