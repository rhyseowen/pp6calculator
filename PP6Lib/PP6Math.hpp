#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

#include <vector>

void swap(double& number1, double& number2);
bool bubbleSort(double *array, int size);
bool bubbleSort(std::vector<double>& array);
double multiply(double number1, double number2);
double divide(double number1, double number2);
double addition(double number1, double number2);
double subtraction(double number1, double number2);
double solveXaxis(double m, double c);
double solveQuadraticP(double a, double b, double c);
double solveQuadraticN(double a, double b, double c);
bool solveQuadratic(double a, double b, double c, double& result1, double& result2);
double vectorLength3(double i, double j, double k);
double vectorDotProductSqrt4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3);
std::vector<double> readInNumbers(int numbers);
bool doubleZeroCheck(double number);


#endif
