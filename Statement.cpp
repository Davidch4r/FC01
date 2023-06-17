//
// Created by David Pidugu on 6/16/23.
//

#include "Statement.h"

Statement::Statement(std::vector<Equation*>* variables, std::vector<Equation*>* equations) {
    this->variables = variables;
    this->equations = equations;
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
