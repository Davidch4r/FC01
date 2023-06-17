//
// Created by David Pidugu on 6/16/23.
//

#include "Equation.h"

// Base class
Equation::Equation(std::vector<Equation*>* vars) {
    this->variables = vars;
    if (vars != nullptr) {
        this->size = vars->size();
    } else {
        this->size = 0;
    }
}

float Equation::getValue() {
    return variables->at(0)->getValue();
}

void Equation::setValue(float value) {
    for (int i = 0; i < this->size; i++) {
        if (!this->variables->at(i)->isConstant() || isVariable())
            this->variables->at(i)->setValue(value);
    }
}

bool Equation::isConstant() {
    return false;
}

bool Equation::isVariable() {
    return false;
}

// Constant
Constant::Constant(float value) : Equation({}) {
    this->value = value;
}

float Constant::getValue() {
    return value;
}

void Constant::setValue(float val) {
    this->value = val;
}

bool Constant::isConstant() {
    return true;
}

// Variable
float Variable::getValue() {
    return this->variables->at(0)->getValue();
}

bool Variable::isVariable() {
    return true;
}

// Add
float Add::getValue() {
    float sum = this->variables->at(0)->getValue();
    for (int i = 1; i < this->size; i++) {
        sum += this->variables->at(i)->getValue();
    }
    return sum;
}

// Subtract
float Subtract::getValue() {
    float sum = this->variables->at(0)->getValue();
    for (int i = 1; i < this->size; i++) {
        sum -= this->variables->at(i)->getValue();
    }
    return sum;
}

// Multiply
float Multiply::getValue() {
    float sum = this->variables->at(0)->getValue();
    for (int i = 1; i < this->size; i++) {
        sum *= this->variables->at(i)->getValue();
    }
    return sum;
}

// Divide
float Divide::getValue() {
    float sum = this->variables->at(0)->getValue();
    for (int i = 1; i < this->size; i++) {
        sum /= this->variables->at(i)->getValue();
    }
    return sum;
}

// Exponential
float Exponential::getValue() {
    float sum = this->variables->at(0)->getValue();
    for (int i = 1; i < this->size; i++) {
        sum = pow(sum, this->variables->at(i)->getValue());
    }
    return sum;
}

// Logarithm
float Logarithm::getValue() {
    float sum = this->variables->at(0)->getValue();
    for (int i = 1; i < this->size; i++) {
        sum = log(sum) / log(this->variables->at(i)->getValue());
    }
    return sum;
}

// Sin
float Sin::getValue() {
    return sin(this->variables->at(0)->getValue());
}

// Cos
float Cos::getValue() {
    return cos(this->variables->at(0)->getValue());
}

// Tan
float Tan::getValue() {
    return tan(this->variables->at(0)->getValue());
}

// Csc
float Csc::getValue() {
    return 1 / sin(this->variables->at(0)->getValue());
}

// Sec
float Sec::getValue() {
    return 1 / cos(this->variables->at(0)->getValue());
}

// Cot
float Cot::getValue() {
    return 1 / tan(this->variables->at(0)->getValue());
}

// ArcSin
float ArcSin::getValue() {
    return asin(this->variables->at(0)->getValue());
}

// ArcCos
float ArcCos::getValue() {
    return acos(this->variables->at(0)->getValue());
}

// ArcTan
float ArcTan::getValue() {
    return atan(this->variables->at(0)->getValue());
}

// ArcCsc
float ArcCsc::getValue() {
    return asin(1 / this->variables->at(0)->getValue());
}

// ArcSec
float ArcSec::getValue() {
    return acos(1 / this->variables->at(0)->getValue());
}

// ArcCot
float ArcCot::getValue() {
    return atan(1 / this->variables->at(0)->getValue());
}

// Sinh
float Sinh::getValue() {
    return sinh(this->variables->at(0)->getValue());
}

// Cosh
float Cosh::getValue() {
    return cosh(this->variables->at(0)->getValue());
}

// Tanh
float Tanh::getValue() {
    return tanh(this->variables->at(0)->getValue());
}

// Csch
float Csch::getValue() {
    return 1 / sinh(this->variables->at(0)->getValue());
}

// Sech
float Sech::getValue() {
    return 1 / cosh(this->variables->at(0)->getValue());
}

// Coth
float Coth::getValue() {
    return 1 / tanh(this->variables->at(0)->getValue());
}

// ArcSinh
float ArcSinh::getValue() {
    return asinh(this->variables->at(0)->getValue());
}

// ArcCosh
float ArcCosh::getValue() {
    return acosh(this->variables->at(0)->getValue());
}

// ArcTanh
float ArcTanh::getValue() {
    return atanh(this->variables->at(0)->getValue());
}

// ArcCsch
float ArcCsch::getValue() {
    return asinh(1 / this->variables->at(0)->getValue());
}

// ArcSech
float ArcSech::getValue() {
    return acosh(1 / this->variables->at(0)->getValue());
}

// ArcCoth
float ArcCoth::getValue() {
    return atanh(1 / this->variables->at(0)->getValue());
}

// Absolute Value
float AbsoluteValue::getValue() {
    return abs(this->variables->at(0)->getValue());
}

// Square Root
float SquareRoot::getValue() {
    return sqrt(this->variables->at(0)->getValue());
}
