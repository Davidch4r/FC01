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
protected:
    std::vector<Equation*>* variables;
    unsigned long size;
};
// Constant
class Constant : public Equation {
public:
    explicit Constant(float value);
    float getValue() override;
    void setValue(float value) override;
    bool isConstant() override;
private:
    float value;
};

// Variable
class Variable : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
    bool isVariable() override;
};

// Operations
class Add : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Subtract : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Multiply : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Divide : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

// Exponential
class Exponential : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

// Logarithm
class Logarithm : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

// Trigonometric
class Sin : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Cos : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Tan : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Csc : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Sec : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Cot : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

// Inverse Trigonometric
class ArcSin : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcCos : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcTan : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcCsc : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcSec : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcCot : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

// Hyperbolic
class Sinh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Cosh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Tanh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Csch : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Sech : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class Coth : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

// Inverse Hyperbolic
class ArcSinh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcCosh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcTanh : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcCsch : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcSech : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class ArcCoth : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

// Other
class AbsoluteValue : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};

class SquareRoot : public Equation {
public:
    using Equation::Equation;
    float getValue() override;
};



#endif //FC01_EQUATION_H
