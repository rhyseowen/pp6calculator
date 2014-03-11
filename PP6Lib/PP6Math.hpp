/** \file PP6Math.hpp 
 *	\brief PP6 Maths Library
 *	
 * 	A Library to provide mathamatical functions for the pp6calculator
 */
#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

#include <vector>

/**
 * @brief Swap Two Numbers
 * @details Sipmle swap algorithm to swap two numbers
 * 
 * @param number1 
 * @param number2 
 */
void swap(double& number1, double& number2);

/**
 * @brief Swap two ints
 * 
 * 
 * @param number1 
 * @param number2 
 */
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

/**
 * @brief Bubble sort for std::vector
 * @details Sort vector passed by refference
 * 
 * @param array Input vector
 * @return Success boolean
 */
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

/**
 * @brief Divide two numbers
 * @details 
 * 
 * @param number1 
 * @param number2 
 * 
 * @return Divided number
 */
double divide(double number1, double number2);

/**
 * @brief Add two numbers
 * @details 
 * 
 * @param number1 
 * @param number2 
 * 
 * @return summation result
 */
double addition(double number1, double number2);

/**
 * @brief Subtract two Numbers
 * @details 
 * 
 * @param number1 
 * @param number2 
 * 
 * @return subtraction result
 */
double subtraction(double number1, double number2);

/**
 * @brief Solve x axis
 * @details Find the point where a given line, characterised by the equation \f$y = mx + c\f$ crosses the x axis 
 * 
 * @param m Gradient
 * @param c Y intercept
 * 
 * @return X intercept
 */
double solveXaxis(double m, double c);

/**
 * @brief Solve Quadratic equation with positive descriminant
 * @details used the equation \f$ \frac{-b + \sqrt{b^2 - 4ac}}{2a} \f$
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return solution
 */
double solveQuadraticP(double a, double b, double c);

/**
 * @brief Solve Quadratic equation with negetive descriminant
 * @details uses the equation \f$ \frac{-b - \sqrt{b^2 - 4ac}}{2a} \f$
 * 
 * @param a 
 * @param b 
 * @param c 
 * @return solution
 */
double solveQuadraticN(double a, double b, double c);

/**
 * @brief Solve Quadratic
 * @details Apply the quadratic formular to solve a quadratic equation of the for \f$ y = ax^2 + bx + c \f$
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

/**
 * @brief Calculate the length of a 3 vector
 * @details returns the modulus of a 3 vector
 * 
 * @param i 
 * @param j 
 * @param k 
 * @return length
 */
double vectorLength3(double i, double j, double k);

/**
 * @brief Madnitude of two four vectors
 * @details Returns the sqrt of the dot product of two 4-vectors
 * 
 * @param a0 
 * @param a1 
 * @param a2 
 * @param a3 
 * @param b0 
 * @param b1 
 * @param b2 
 * @param b3 
 * @return length
 */
double vectorDotProductSqrt4(double a0, double a1, double a2, double a3, double b0, double b1, double b2, double b3);

/**
 * @brief Check if a double is zero
 * @details Performs a sensible check if a double is zero
 * 
 * @param number number to check
 * @return true if zero, false otherwise
 */
bool doubleZeroCheck(double number);

/**
 * @brief Calculate invarient mass squared
 * @details Calculates \f$ m^2 \f$ for the momentum 4-vectors of two particles
 * 
 * @param E1 
 * @param px1 
 * @param py1 
 * @param pz1 
 * @param E2 
 * @param px2 
 * @param py2 
 * @param pz2 
 * @return m^2
 */
double invarientMass(double E1, double px1, double py1, double pz1, double E2, double px2, double py2, double pz2);

/**
 * @brief Generate Muons
 * @details Generates a list of muons with random momenta and an energy based on the random momenta and the muon mass
 * 
 * @param numberOfMuons Number of muons to generate
 * @param E Array to fill with energies
 * @param px Array to fill with px
 * @param py Array to fill with py
 * @param pz Array to fill with pz
 * @return Success code (0 = success)
 */
int generateMuons(int numberOfMuons, double *E, double *px, double *py, double *pz);


#endif
