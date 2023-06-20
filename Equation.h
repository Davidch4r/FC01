//
// Created by David Pidugu on 6/16/23.
//

#ifndef FC01_EQUATION_H
#define FC01_EQUATION_H

#include <iostream>


class Equation {
public:
    explicit Equation(std::vector<Equation*>* variables);
    virtual ~Equation() = default;
    virtual float getValue();
    virtual void setValue(float value);
    virtual bool isConstant();
    virtual bool isVariable();
    virtual void addVariable(Equation* variable);
    virtual void print();
    virtual std::string getName();
protected:
    std::vector<Equation*>* variables;
    unsigned long size;
    std::string name = "EQU";
};
// Constant
class Constant : public Equation {
public:
    explicit Constant(float value);
    float getValue() override;
    void setValue(float value) override;
    bool isConstant() override;
    void print() override;
private:
    float value;
};

// Variable
class Variable : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    bool isVariable() override;
    void setName(const std::string& name);
    void print() override;
};

// Operations
class Add : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ADD"; }
};

class Subtract : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "SUB"; }
};

class Multiply : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "MUL"; }
};

class Divide : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "DIV"; }
};

// Exponential
class Exponential : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "EXP"; }
};

// Logarithm
class Logarithm : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "LOG"; }
};

// Trigonometric
class Sin : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "SIN"; }
};

class Cos : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "COS"; }
};

class Tan : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "TAN"; }
};

class Csc : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "CSC"; }
};

class Sec : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "SEC"; }
};

class Cot : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "COT"; }
};

// Inverse Trigonometric
class ArcSin : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ASIN"; }
};

class ArcCos : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ACOS"; }
};

class ArcTan : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ATAN"; }
};

class ArcCsc : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ACSC"; }
};

class ArcSec : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ASEC"; }
};

class ArcCot : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ACOT"; }
};

// Hyperbolic
class Sinh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "SINH"; }
};

class Cosh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "COSH"; }
};

class Tanh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "TANH"; }
};

class Csch : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "CSCH"; }
};

class Sech : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "SECH"; }
};

class Coth : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "COTH"; }
};

// Inverse Hyperbolic
class ArcSinh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ASINH"; }
};

class ArcCosh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ACOSH"; }
};

class ArcTanh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ATANH"; }
};

class ArcCsch : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ACSCH"; }
};

class ArcSech : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ASECH"; }
};

class ArcCoth : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ACOTH"; }
};

// Other
class AbsoluteValue : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "ABS"; }
};

class SquareRoot : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    std::string getName() override { return "SQRT"; }
};



#endif //FC01_EQUATION_H
