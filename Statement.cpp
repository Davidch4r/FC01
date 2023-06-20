//
// Created by David Pidugu on 6/16/23.
//

#include <sstream>
#include "Statement.h"

Statement::Statement(std::vector<Equation*>* variables, std::vector<Equation*>* equations) {
    this->variables = variables;
    this->equations = equations;
}

// Assume for just X and Y with 2 equations
Statement::Statement(const std::string& statement) {
    auto* X = new Variable(new eq({new Constant(0)}));
    auto* Y = new Variable(new eq({new Constant(0)}));
    X->setName("X");
    Y->setName("Y");
    this->variables = new std::vector<Equation*>({X, Y});
    std::string equation1 = statement.substr(0, statement.find('='));
    std::string equation2 = statement.substr(statement.find('=') + 1);
    std::vector<std::string> tokensEq1;
    std::vector<std::string> tokensEq2;
    std::string token;
    std::istringstream tokenStream(equation1);
    while (std::getline(tokenStream, token, ' ')) {
        tokensEq1.push_back(token);
    }
    tokenStream = std::istringstream(equation2);
    while (std::getline(tokenStream, token, ' ')) {
        tokensEq2.push_back(token);
    }
    this->equations = new std::vector<Equation*>({
         AtoE(&tokensEq1, X, Y),
         AtoE(&tokensEq2, X, Y)
    });
}

bool Statement::isSolved(float step) {
    float value = round(this->equations->at(0)->getValue() / step) * step;
    for (int i = 1; i < this->equations->size(); i++) {
        float temp = round(this->equations->at(i)->getValue() / step) * step;
        if (temp != value) {
            return false;
        }
    }
    return true;
}

bool Statement::isSolved(std::vector<float>* permutation, float step) {
    for (int i = 0; i < this->variables->size(); i++) {
        this->variables->at(i)->setValue(permutation->at(i));
    }
    return this->isSolved(step);
}

std::vector<std::vector<float>*> Statement::generatePermutations(unsigned n, float min, float max, float step) {
    std::vector<std::vector<float>*> permutations;
    std::vector<float> currentPermutation(n, round(min / step) * step);

    while (true) {
        permutations.push_back(new std::vector<float>(currentPermutation));
        int index = n - 1;
        while (index >= 0 && currentPermutation[index] >= max - step) {
            index--;
        }
        if (index < 0) {
            break;
        }
        currentPermutation[index] += step;
        currentPermutation[index] = round(currentPermutation[index] / step) * step;
        for (int i = index + 1; i < n; i++) {
            currentPermutation[i] = round(min / step) * step;
        }
    }

    return permutations;
}
/**
 * Example AtoE's:
 * String: "ADD ( X Y 2)"
 * Result: Equation* result = new Equation(new Add(new Variable(X), new Variable(Y), new Constant(2)));
 * Math Expression: X + Y + 2
 *
 * String: "ADD ( EXP ( X 2 ) EXP ( Y 2 ) )"
 * Result: Equation* result = new Equation(new Add(new Exp(new Variable(X), new Constant(2)), new Exp(new Variable(Y), new Constant(2))));
 * Math Expression: X^2 + Y^2
 *
 * String: "SQRT ( X )"
 * Result: Equation* result = new Equation(new Sqrt(new Variable(X)));
 * Math Expression: sqrt(X)
 */
Equation* Statement::AtoE(std::vector<std::string>* tokens, Variable* X, Variable* Y) {
    auto* equation = new Equation(new eq());
    std::stack <Equation*> queue;
    queue.push(equation);
    for (const auto& token : *tokens) {
        if (token == " " || token == "(" || token.empty()) {
            continue;
        }
        if (token == ")") {
            queue.pop();
        } else if (token == "X") {
            queue.top()->addVariable(X);
        } else if (token == "Y") {
            queue.top()->addVariable(Y);
        } else if (isNumber(token)){
            queue.top()->addVariable(new Constant(std::stof(token)));
        } else {
            if (token == "PI") {
                queue.top()->addVariable(new Constant(M_PI));
                continue;
            } else if (token == "E") {
                queue.top()->addVariable(new Constant(M_E));
                continue;
            }
            auto* newEq = new Equation(new eq());
            if (token == "ADD") {
                newEq = new Add(new eq());
            } else if (token == "SUB") {
                newEq = new Subtract(new eq());
            } else if (token == "MUL") {
                newEq = new Multiply(new eq());
            } else if (token == "DIV") {
                newEq = new Divide(new eq());
            } else if (token == "EXP") {
                newEq = new Exponential(new eq());
            } else if (token == "LOG") {
                newEq = new Logarithm(new eq());
            } else if (token == "SIN") {
                newEq = new Sin(new eq());
            } else if (token == "COS") {
                newEq = new Cos(new eq());
            } else if (token == "TAN") {
                newEq = new Tan(new eq());
            } else if (token == "CSC") {
                newEq = new Csc(new eq());
            } else if (token == "SEC") {
                newEq = new Sec(new eq());
            } else if (token == "COT") {
                newEq = new Cot(new eq());
            } else if (token == "ASIN") {
                newEq = new ArcSin(new eq());
            } else if (token == "ACOS") {
                newEq = new ArcCos(new eq());
            } else if (token == "ATAN") {
                newEq = new ArcTan(new eq());
            } else if (token == "ACSC") {
                newEq = new ArcCsc(new eq());
            } else if (token == "ASEC") {
                newEq = new ArcSec(new eq());
            } else if (token == "ACOT") {
                newEq = new ArcCot(new eq());
            } else if (token == "SINH") {
                newEq = new Sinh(new eq());
            } else if (token == "COSH") {
                newEq = new Cosh(new eq());
            } else if (token == "TANH") {
                newEq = new Tanh(new eq());
            } else if (token == "CSCH") {
                newEq = new Csch(new eq());
            } else if (token == "SECH") {
                newEq = new Sech(new eq());
            } else if (token == "COTH") {
                newEq = new Coth(new eq());
            } else if (token == "ASINH") {
                newEq = new ArcSinh(new eq());
            } else if (token == "ACOSH") {
                newEq = new ArcCosh(new eq());
            } else if (token == "ASECH") {
                newEq = new ArcSech(new eq());
            } else if (token == "ACOTH") {
                newEq = new ArcCoth(new eq());
            } else if (token == "ABS") {
                newEq = new AbsoluteValue(new eq());
            } else if (token == "SQRT") {
                newEq = new SquareRoot(new eq());
            } else {
                std::cout << "Invalid token: =>" << token  << "<= " << std::endl;
                continue;
            }
            queue.top()->addVariable(newEq);
            queue.push(newEq);
        }

    }
    return equation;
}

bool Statement::isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


