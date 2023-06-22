# Important Notes
- The language is not case-sensitive but it is space sensitives. Therefore, whenever you want to add a new Element, you press space
- The program is formated as such: OPERATOR ( VAR CONST ) = OPERATOR (VAR CONST
)
- Operators must always have parenthesis to enclose the parameters (Remember, the parameters can be as long as you like) while variables can just be X and Y and Constants can be any number
- Given no '=', the equation is assumed to equal Y

# VARIABLES

Though the graphing calculator can handle any amount of variables, I specifically made this a 2d grapher. As such the variales are only X and Y
- X => The variables responsible for the X values
- Y => The variables responsible for the Y values

Example: X = Y

# CONSTANTS

Constants can be any float number

- ANY FLOAT => Any float number for Constants
- PI => The constant PI
- E => The constant E

Example: X = 2

# OPERATORS
Operators are the functions that are used to calculate the values of the variables and must have enclosing parenthesis and as many parameters as you like in it. They can be any of the following:
- ADD => Addition
- SUB => Subtraction
- MUL => Multiplication
- DIV => Division
- EXP => Exponentiation (For example EXP ( X 2 ) is X^2 or EXP (X Y 2) is X^Y^2)
- LOG => Logarithm (Base e)
- SIN => Sine
- COS => Cosine
- TAN => Tangent
- SEC => Secant
- CSC => Cosecant
- COT => Cotangent
- ASIN => Arcsine
- ACOS => Arccosine
- ATAN => Arctangent
- ASEC => Arcsecant
- ACSC => Arccosecant
- ACOT => Arccotangent
- SINH => Hyperbolic Sine
- COSH => Hyperbolic Cosine
- TANH => Hyperbolic Tangent
- SECH => Hyperbolic Secant
- CSCH => Hyperbolic Cosecant
- COTH => Hyperbolic Cotangent
- ASINH => Hyperbolic Arcsine
- ACOSH => Hyperbolic Arccosine
- ATANH => Hyperbolic Arctangent
- ASECH => Hyperbolic Arcsecant
- ACSCH => Hyperbolic Arccosecant
- ACOTH => Hyperbolic Arccotangent
- ABS => Absolute Value
- SQRT => Square Root

I am planning to add more operators in the future

# COMMANDS
These are currently the only commands but I plan on adding way more in the future
- QUIT => Quits the program
- CLEAR COLORS => Clears all the colors
- CLEAR ALL => Clears all the equations
- CLEAR [NUM] => Clears the equation at the specified index (For example: CLEAR 1 will clear the first equation)
- SIZE [NUM] => Changes the size of the window (For example: CHANGESIZE 1000 will change the size of the window to 1000 pixels)
- STEP [NUM] => Changes the step size of the graph (For example: SETSTEP 0.1 will change the step size to 0.1)
- XMIN [NUM] => Changes the minimum value of the X axis (For example: XMIN -10 will change the minimum value of the X axis to -10)
- XMAX [NUM] => Changes the maximum value of the X axis (For example: XMAX 10 will change the maximum value of the X axis to 10)
- YMIN [NUM] => Changes the minimum value of the Y axis (For example: YMIN -10 will change the minimum value of the Y axis to -10)
- YMAX [NUM] => Changes the maximum value of the Y axis (For example: YMAX 10 will change the maximum value of the Y axis to 10)
- BOUND [NUM] => Sets a square bound for the graph (For example: SETBOUND 10 will set the x axis to go from -10 to 10 and the y axis to go from -10 to 10)
- RIGHT [NUM] => Moves the graph to the right (For example: RIGHT 10 will move the graph 10 units to the right)
- LEFT [NUM] => Moves the graph to the left (For example: LEFT 10 will move the graph 10 units to the left)
- UP [NUM] => Moves the graph up (For example: UP 10 will move the graph 10 units up)
- DOWN [NUM] => Moves the graph down (For example: DOWN 10 will move the graph 10 units down)
- ADDCOLOR [NUM] [NUM] [NUM] => Adds a color to the graph (For example: ADDCOLOR 255 0 0 will add the color red to the graph)

# EXAMPLES

## QUADRATIC
- EXP ( X 2 )

## Circle
- ADD ( EXP ( X 2 ) EXP ( Y 2 ) ) = 1

## Straight line
- Y = X
- Y = ADD ( X 1 )
- 5
- X = 5

## Pendelum
- Y = MUL ( 5 COS ( MUL ( 2 PI X)))

# Future Plans
- Add more operators
- ADD More Commands