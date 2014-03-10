#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>
#include "PP6Math.hpp"

int main()
{

	int err = 0;

	while (true)
	{

		std::cout << "Which Operation would you like to perform ('help' for a list of suported opperations)" << std::endl;
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
			std::cout << "a + b = ?" << std::endl;
			std::vector<double> number = readInNumbers(2);
			std::cout << number[0] << " + " << number[1] << " = " << addition(number[0],number[1]) <<std::endl;  
		}else if (opperation == "-")
		{
			//subtraction
			std::cout << "a - b = ?" << std::endl;
			std::vector<double> number = readInNumbers(2);
			std::cout << number[0] << " - " << number[1] << " = " << subtraction(number[0],number[1]) <<std::endl; 
		}else if (opperation == "/")
		{
			//division
			std::cout << "a / b = ?" << std::endl;
			std::vector<double> number = readInNumbers(2);
			if (number[1] == 0)
			{
				std::cout << "Cannot divide by 0!" << std::endl;
				err = 3;
				continue;
			}
			std::cout << number[0] <<  " / " << number[1] << " = " << divide(number[0],number[1]) <<std::endl; 	
		}else if (opperation == "*")
		{
			//multiplication
			std::cout << "a * b = ?" <<std::endl;
			std::vector<double> number = readInNumbers(2);
			std::cout << number[0] << " * " << number[1] << " = " << multiply(number[0],number[1]) <<std::endl;
		}else if (opperation == "solveAxis")
		{
			std::cout << " y = ax + b: find x intercept" << std::endl;
			std::vector<double> number = readInNumbers(2);
			std::cout << " y = " << number[0] << "x + " << number[1] << ": x intercept = " << solveXaxis(number[0], number[1]) << std::endl;
		}else if (opperation == "solveQuadratic")
		{
			std::cout << "0 = ax^2 + bx +c: solve for x" << std::endl;
			std::vector<double> number = readInNumbers(3);

			double solution1 = 0;
			double solution2 = 0;

			if (solveQuadratic(number[0],number[1],number[2],solution1,solution2))
			{
				std::cout << "0 = " <<  number[0] << "x^2 + " << number[1] << "x + " << number[2] << " : x = " << solution1 << " or " << solution2 << std::endl;
			}else{
				std::cout << "No real roots try again!" << std::endl;
				err = 4;
			}
		}else if (opperation == "3VectorLength")
		{
			std::cout << "v = ai + bj + ck : calculate |v|" << std::endl;
			std::vector<double> number = readInNumbers(3);
			std::cout << "v = " << number[0] << "i + " << number[1] << "j + " << number[2] << "k : |v| = " << vectorLength3(number[0], number[1], number[2]) << std::endl; 
		}else if (opperation == "4VectorLength")
		{
			std::cout << "A = (a,b,c,d) : find |A|" << std::endl;
			std::vector<double> number = readInNumbers(4);
			std::cout << "A = (" << number[0] << "," << number[1] << "," << number[2] << "," << number[3] << ") : |A| = " << vectorDotProductSqrt4(number[0],number[1],number[2],number[3],number[0],number[1],number[2],number[3]) <<std::endl;
		}else if (opperation == "invarientMass")
		{
			std::cout << "m^2 = A1*A2 = (a,b,c,d)*(e,f,g,h) : find |m|" << std::endl;
			std::vector<double> number = readInNumbers(8);
			std::cout << "A1 = (" << number[0] << "," << number[1] << "," << number[2] << "," << number[3] << ")" << std::endl;
			std::cout << "A2 = (" << number[4] << "," << number[5] << "," << number[6] << "," << number[7] << ")" << std::endl;
			std::cout << "m = " << vectorDotProductSqrt4(number[0],number[1],number[2],number[3],number[4],number[5],number[6],number[7]) << std::endl;
		}else if (opperation == "swap")
		{
			std::cout << " swap a and b" << std::endl;
			std::vector<double> number = readInNumbers(2);
			std::cout << "Swap " << number[0] << " and " << number[1] << " -> ";
			swap(number[0],number[1]);
			std::cout << number[0] << " and " << number[1] << std::endl;
		}else if (opperation == "sort")
		{
			std::cout << "Sort 8 numbers" << std::endl;
			std::vector<double> number = readInNumbers(8);
			double *p_array = &number[0];
			bubbleSort(p_array,8);

			std::cout << "Sorted list: " ;

			for (int i = 0; i < 8; ++i)
			{
				std::cout << number[i] << ", ";
			}

			std::cout << std::endl;

		}else if (opperation == "vectorSort"){
			std::cout << "Sort 8 numbers" << std::endl;
			std::vector<double> number = readInNumbers(8);
			
			bubbleSort(number);

			std::cout << "Sorted list: " ;

			for (int i = 0; i < 8; ++i)
			{
				std::cout << number[i] << ", ";
			}

			std::cout << std::endl;

		}else if (opperation == "help")
		{
			//help statement
			printHelp();
		}else if (opperation == "quit" || opperation == "q")
		{
			return err;
		}else{
			std::cout << "Operator not recognised"<<std::endl;
			err = 2;
			continue;
		}

	}

	return 0;
}



