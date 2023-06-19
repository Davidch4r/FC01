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
    Variable X(new eq({new Constant(0)}));
    Variable Y(new eq({new Constant(0)}));
    this->variables = new std::vector<Equation*>({&X, &Y});
    this->equations = new std::vector<Equation*>(2);
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
    this->equations->at(0) = AtoE(&tokensEq1, &X, &Y);;
    this->equations->at(1) = AtoE(&tokensEq2, &X, &Y);;
}

std::vector<std::vector<float>*>* Statement::solve(float min, float max, float step) {
    auto* results = new std::vector<std::vector<float>*>;
    std::vector<std::vector<float>*> permutations = generatePermutations(this->variables->size(), min, max, step);
    for (auto permutation : permutations) {
        for (int i = 0; i < this->variables->size(); i++) {
            this->variables->at(i)->setValue(permutation->at(i));
        }
        if (this->isSolved(step)) {

            results->push_back(permutation);
        }
    }
    return results;
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
        if (token == ")") {
            queue.pop();
        } if (token == "X") {
            queue.top()->addVariable(X);
        } else if (token == "Y") {
            queue.top()->addVariable(Y);
        } else if (token == "ADD") {
            auto* newEq = new Add(new eq());
            queue.top()->addVariable(newEq);
            queue.push(newEq);
        } else if (isNumber(token)){
            queue.top()->addVariable(new Constant(std::stof(token)));
        }

    }
    return equation;
}

bool Statement::isNumber(const std::string& s) {
    return !s.empty() && std::find_if(s.begin(),s.end(), [](unsigned char c) { return !std::isdigit(c); }) == s.end();
}


