/** \file PP6Math.hpp 
 *	\brief PP6 Maths Library
 *	
 * 	A Library to provide mathamatical functions for the pp6calculator
 */
#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

#include <vector>

/**
 * @brief Swap Two Number
 * @details Sipmle swap algorithm to swap two numbers
 * 
 * @param number1 
 * @param number2 
 */
void swap(double& number1, double& number2);

void swap(int& number1, int& number2);

/**
 * @brief Simple bubble sort
 * @details Sorts the given array highest to lowest
 * 
 * @param array Array to sort
 * @param size length of the array
 * 
 * @return Success boolean
 */
bool bubbleSort(double *array, int size);

/**
 * @brief Bubble sort with sepperate results
 * @details Provides a sort of the given array but records the result in the results array leaving the origonal array untouched.
 * 
 *  The results array wil be filled with the index of the element from unsorted array which should be at this position. 
 *  i.e. the sorted result is @code array[results[i]] @endcode
 *  
 * @param array Array to be sorted
 * @param results Array to fill with the results.
 * @param size length of the array
 * @return Success boolean
 */
bool bubbleSort(double *array, int *results, int size);

bool bubbleSort(std::vector<double>& array);

/**
 * @brief Multiply two doubles
 * 
 * 
 * @param number1 
 * @param number2 
 * 
 * @return result of multiplication
 */
double multiply(double number1, double number2);
double divide(double number1, double number2);
double addition(double number1, double number2);
double subtraction(double number1, double number2);

/**
 * @brief Solve x axis
 * @details Find the point where a given line, characterised by the equation y = m*x + c crosses the x axis 
 * 
 * @param m Gradient
 * @param c Y intercept
 * 
 * @return X intercept
 */
double solveXaxis(double m, double c);

double solveQuadraticP(double a, double b, double c);

double solveQuadraticN(double a, double b, double c);

/**
 * @brief Solve Quadratic
 * @details Apply the quadratic formular to solve a quadratic equation of the for y = a*x^2 + b*x + c
 * 
 * In general there are two parameters to such equations which are atributed to the two result variables passed by refference.
 * 
 * @param a a parameter
 * @param b b parameter
 * @param c c parameter
 * @param result1 First solution
 * @param result2 Second solution
 * @return Success boolean
 */
bool solveQuadratic(double a, double b, double c, double& result1, double& result2);
double vectorLength3(double i, double j, double k);
double vectorDotProductSqrt4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3);
bool doubleZeroCheck(double number);
double invarientMass(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2);

int generateMuons(int numberOfMuons, double *E, double *px, double *py, double *pz);


#endif
