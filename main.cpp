#include <iostream>
#include "Grapher.h"

typedef std::vector<Equation*> eq;

int main() {
    // Circle 1
    auto* X1 = new Variable(new eq({new Constant(0)}));
    auto* Y1 = new Variable(new eq({new Constant(0)}));
    auto* H = new Constant(0);
    auto* K = new Constant(7);
    auto* R = new Constant(1);
    auto* fx = new Add(new eq({
        new Exponential(new eq({new Subtract(new eq({X1, H})), new Constant(2)})),
        new Exponential(new eq({new Subtract(new eq({Y1, K})), new Constant(2)}))
    }));
    auto* gx = new Exponential(new eq({R, new Constant(2)}));
    auto* statement1 = new Statement(new eq({X1, Y1}), new eq({fx, gx}));

    // Squiggly Sin
    auto* X2 = new Variable(new eq({new Constant(0)}));
    auto* Y2 = new Variable(new eq({new Constant(0)}));
    auto* A = new Constant(2);
    auto* B = new Constant(5);
    auto* C = new Constant(1);
    auto* D = new Constant(1);
    auto* fx2 = new Add(new eq({
        new Multiply(new eq({A, new Sin(new eq({new Multiply(new eq({B, X2}))}))})),
        new Multiply(new eq({C, X2})),
        D
    }));
    auto* gx2 = Y2;
    auto* statement2 = new Statement(new eq({X2, Y2}), new eq({fx2, gx2}));

    // Inverse Squiggly Sin
    auto* X3 = new Variable(new eq({new Constant(0)}));
    auto* Y3 = new Variable(new eq({new Constant(0)}));
    auto* A2 = new Constant(2);
    auto* B2 = new Constant(2);
    auto* C2 = new Constant(-1);
    auto* D2 = new Constant(1);
    auto* fx3 = new Add(new eq({
        new Multiply(new eq({A2, new Sin(new eq({new Multiply(new eq({B2, X3}))}))})),
        new Multiply(new eq({C2, X3})),
        D2
    }));
    auto* gx3 = Y3;
    auto* statement3 = new Statement(new eq({X3, Y3}), new eq({fx3, gx3}));

    // Circle 2
    auto* X4 = new Variable(new eq({new Constant(0)}));
    auto* Y4 = new Variable(new eq({new Constant(0)}));
    auto* H2 = new Constant(0);
    auto* K2 = new Constant(-7);
    auto* R2 = new Constant(1);
    auto* fx4 = new Add(new eq({
        new Exponential(new eq({new Subtract(new eq({X4, H2})), new Constant(2)})),
        new Exponential(new eq({new Subtract(new eq({Y4, K2})), new Constant(2)}))
    }));
    auto* gx4 = new Exponential(new eq({R2, new Constant(2)}));
    auto* statement4 = new Statement(new eq({X4, Y4}), new eq({fx4, gx4}));

    // 0.5 * x^3 = y
    auto* X5 = new Variable(new eq({new Constant(0)}));
    auto* Y5 = new Variable(new eq({new Constant(0)}));
    auto* fx5 = new Multiply(new eq({new Constant(0.2), new Exponential(new eq({X5, new Constant(3)}))}));
    auto* gx5 = Y5;
    auto* statement5 = new Statement(new eq({X5, Y5}), new eq({fx5, gx5}));


    std::vector<Statement*> statements = {statement1, statement2, statement3, statement4, statement5};
    std::vector<sf::Color> lineColors = {sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Yellow, sf::Color::Magenta};

    Grapher grapher(&statements);
    grapher.displayGraph(800, &lineColors, sf::Color(0, 0, 20), sf::Color::White, -15, 15, -15, 15, 0.01, 1000, 5);
    return 0;
}
