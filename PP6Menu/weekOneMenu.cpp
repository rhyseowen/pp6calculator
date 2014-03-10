#include <iostream>
#include <climits>
#include <cmath>
#include <vector>

#include "weekOneMenu.hpp"
#include "PP6Math.hpp"

int weekOneMenu()
{
	int err = 0;
	while (true)
	{

		std::cout << "Which Operation would you like to perform " << std::endl;
		std::cout << ": ";

		std::string opperation;
		std::cin >> opperation;

		//fail in input is broken
		if (!std::cin)
		{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n'); 
			err = 2;
			continue;
		}

		if (opperation == "+")
		{
			//addition
			err = wk1_addition();
  
		}else if (opperation == "-")
		{
			//subtraction
			err = wk1_subtraction();
		}else if (opperation == "/")
		{
			//division
			err = wk1_division();

		}else if (opperation == "*")
		{
			//multiplication
			err = wk1_multiplication();

		}else if (opperation == "solveAxis")
		{
			err = wk1_solveAxis();

		}else if (opperation == "solveQuadratic")
		{
			err = wk1_solveQuadratic();

		}else if (opperation == "3VectorLength")
		{
			err = wk1_3VectorLength();

		}else if (opperation == "4VectorLength")
		{
			err = wk1_4VectorLength();

		}else if (opperation == "invarientMass")
		{
			err = wk1_invarientMass();

		}else if (opperation == "help")
		{
			//help statement
			weekOnePrintHelp();
		}else if (opperation == "quit" || opperation == "q")
		{
			return err;
		}else{
			std::cout << "Operator not recognised"<<std::endl;
			err = 2;
			continue;
		}

	}
}

void weekOnePrintHelp()
{
	std::cout << "Available operations: " << std::endl;
	std::cout << "+ : Simple addition of two numbers" << std::endl;
	std::cout << "- : Simple subtraction of two numbers" << std::endl;
	std::cout << "/ : Simple division of two numbers" << std::endl;
	std::cout << "* : Simple multiplication of two numbers" << std::endl;
	std::cout << "solveAxis : Find the x-intercept of a straigt line" << std::endl;
	std::cout << "solveQuadratic : find the real roots of a quadratic equation" << std::endl;
	std::cout << "3VectorLength : find the length of a 3 vector" << std::endl;
	std::cout << "4VectorLength : find the length of a 4 vector" << std::endl;
	std::cout << "invarientMass : find the invarient mass of a momentum 4 vector" << std::endl;
	std::cout << "quit : exit the calculator" << std::endl;
}

int wk1_addition()
{
	std::cout << "a + b = ?" << std::endl;
	std::vector<double> number = readInNumbers(2);
	std::cout << number[0] << " + " << number[1] << " = " << addition(number[0],number[1]) <<std::endl;

	return 0;
}
int wk1_subtraction()
{
	std::cout << "a - b = ?" << std::endl;
	std::vector<double> number = readInNumbers(2);
	std::cout << number[0] << " - " << number[1] << " = " << subtraction(number[0],number[1]) <<std::endl; 
	return 0;
}
int wk1_division()
{
	std::cout << "a / b = ?" << std::endl;
	std::vector<double> number = readInNumbers(2);
	if (doubleZeroCheck(number[1]))
	{
		std::cout << "Cannot divide by 0!" << std::endl;
		return 3;
		
	}
	std::cout << number[0] <<  " / " << number[1] << " = " << divide(number[0],number[1]) <<std::endl; 	

	return 0;
}
int wk1_multiplication()
{
	std::cout << "a * b = ?" <<std::endl;
	std::vector<double> number = readInNumbers(2);
	std::cout << number[0] << " * " << number[1] << " = " << multiply(number[0],number[1]) <<std::endl;

	return 0;
}
int wk1_solveAxis()
{
	std::cout << " y = ax + b: find x intercept" << std::endl;
	std::vector<double> number = readInNumbers(2);

	if (doubleZeroCheck(number[0]))
	{
		std::cout << "a cannot be 0" << std::endl;
		return 3;
	}

	std::cout << " y = " << number[0] << "x + " << number[1] << ": x intercept = " << solveXaxis(number[0], number[1]) << std::endl;

	return 0;
}
int wk1_solveQuadratic()
{
	std::cout << "0 = ax^2 + bx +c: solve for x" << std::endl;
	std::vector<double> number = readInNumbers(3);

	//check a isnt 0 to prevent divide 0 errors

	if (doubleZeroCheck(number[0]))	
	{
		std::cout << "a cannot be 0" << std::endl;
		return 3;
	}

	double solution1 = 0;
	double solution2 = 0;

	if (solveQuadratic(number[0],number[1],number[2],solution1,solution2))
	{
		std::cout << "0 = " <<  number[0] << "x^2 + " << number[1] << "x + " << number[2] << " : x = " << solution1 << " or " << solution2 << std::endl;
	}else{
		std::cout << "No real roots try again!" << std::endl;
		return 4;
	}

	return 0;
}
int wk1_3VectorLength()
{
	std::cout << "v = ai + bj + ck : calculate |v|" << std::endl;
	std::vector<double> number = readInNumbers(3);
	std::cout << "v = " << number[0] << "i + " << number[1] << "j + " << number[2] << "k : |v| = " << vectorLength3(number[0], number[1], number[2]) << std::endl; 

	return 0;
}
int wk1_4VectorLength()
{

	std::cout << "A = (a,b,c,d) : find |A|" << std::endl;
	std::vector<double> number = readInNumbers(4);
	std::cout << "A = (" << number[0] << "," << number[1] << "," << number[2] << "," << number[3] << ") : |A| = " << vectorDotProductSqrt4(number[0],number[1],number[2],number[3],number[0],number[1],number[2],number[3]) <<std::endl;
	return 0;
}
int wk1_invarientMass()
{
	std::cout << "m^2 = (A1+A2)^2 = ((a,b,c,d)+(e,f,g,h))^2 : find |m|" << std::endl;
	std::vector<double> number = readInNumbers(8);
	std::cout << "A1 = (" << number[0] << "," << number[1] << "," << number[2] << "," << number[3] << ")" << std::endl;
	std::cout << "A2 = (" << number[4] << "," << number[5] << "," << number[6] << "," << number[7] << ")" << std::endl;
	std::cout << "m = " << vectorDotProductSqrt4(number[0]+number[4],number[1]+number[5],number[2]+number[6],number[3]+number[7],number[0]+number[4],number[1]+number[5],number[2]+number[6],number[3]+number[7]) << std::endl;

	// std::cout << "m = " << sqrt(invarientMass(number[0],number[1],number[2],number[3],number[4],number[5],number[6],number[7])) << std::endl;

	return 0;
}
