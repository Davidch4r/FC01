//
// Created by David Pidugu on 6/16/23.
//

#ifndef FC01_STATEMENT_H
#define FC01_STATEMENT_H

#include "Equation.h"
#include <iostream>
#include <stack>

typedef std::vector<Equation*> eq;

class Statement {
public:
    Statement(std::vector<Equation*>* variables, std::vector<Equation*>* equations);
    Statement(const std::string& statement);
    ~Statement() = default;
    std::vector<std::vector<float>*>* solve(float min, float max, float step);
    bool isSolved(float step);
    bool isSolved(std::vector<float>* permutation, float step);
    static std::vector<std::vector<float>*> generatePermutations(unsigned n, float min, float max, float step);
private:
    std::vector<Equation*>* variables;
    std::vector<Equation*>* equations;

    static Equation* AtoE(std::vector<std::string>* tokens, Variable* X, Variable* Y);
    static bool isNumber(const std::string& s);

};


#endif //FC01_STATEMENT_H
