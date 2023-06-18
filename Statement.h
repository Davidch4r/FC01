//
// Created by David Pidugu on 6/16/23.
//

#ifndef FC01_STATEMENT_H
#define FC01_STATEMENT_H

#include "Equation.h"
#include <iostream>

typedef std::vector<Equation*> eq;

class Statement {
public:
    Statement(std::vector<Equation*>* variables, std::vector<Equation*>* equations);
    Statement(std::string statement);
    ~Statement() = default;
    std::vector<std::vector<float>*>* solve(float min, float max, float step);
    bool isSolved(float step);
    bool isSolved(std::vector<float>* permutation, float step);
    static std::vector<std::vector<float>*> generatePermutations(unsigned n, float min, float max, float step);
private:
    std::vector<Equation*>* variables;
    std::vector<Equation*>* equations;

    Equation* atoiEquation(std::string* str, Variable* X, Variable* Y);
};


#endif //FC01_STATEMENT_H
