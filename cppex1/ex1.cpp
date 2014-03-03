#include <iostream>
#include <string>
#include <climits>
#include <vector>
#include <cmath>

double multiply(double number1, double number2)
{
	return number1 * number2;
}

double divide(double number1, double number2)
{
	return number1 / number2;
}

double addition(double number1, double number2)
{
	return number1 + number2;
}

double subtraction(double number1, double number2)
{
	return number1 - number2;
}

double solveXaxis(double m, double c)
{
	// y = mc + c @y=0
	// x = -c/m
	return -c / m;
}

double solveQuadraticP(double a, double b, double c)
{
	//find the positive solution for a quadratic
	return (-b + sqrt(b*b - 4*a*c))/(2*a);
}

double solveQuadraticN(double a, double b, double c)
{
	//find the negetive solution for a quadratic
	return (-b - sqrt(b*b - 4*a*c))/(2*a);
}

double vectorLength3(double i, double j, double k)
{
	return sqrt(i*i+j*j+k*k);
}

std::vector<double> readInNumbers(int numbers)
{
	std::vector<double> in_numbers;

	for (int i = 0; i < numbers; ++i)
	{
		double number;
		char charlist[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
		std::cout << "Set variable " << charlist[i] << std::endl << ": ";
		std::cin >> number;

		if (!std::cin)
		{
			std::cout << "Number not recognised" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			--i;
			continue;
		}

		in_numbers.push_back(number);

	}
	return in_numbers;
}

void printHelp()
{
	std::cout << "Available operations: " << std::endl;
	std::cout << "+ : Simple addition of two numbers" << std::endl;
	std::cout << "- : Simple subtraction of two numbers" << std::endl;
	std::cout << "/ : Simple division of two numbers" << std::endl;
	std::cout << "* : Simple multiplication of two numbers" << std::endl;
	std::cout << "solveAxis : Find the x-intercept of a straigt line" << std::endl;
	std::cout << "solveQuadratic : find the real roots of a quadratic equation" << std::endl;
	std::cout << "3VectorLength : find the length of a 3 vector" << std::endl;
}

int main()
{

	bool first = true;
	int err = 0;

	while (true)
	{

		if (!first)
		{

			std::string repeat; 
			std::cout << "Would you like to continue? (y/n)" << std::endl << ": ";
			std::cin >> repeat;

			if (!std::cin)
			{
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n'); 
			std::cout << "Please answer y or n" << std::endl;
			continue;
			}

			if (repeat == "n" || repeat == "no" || repeat == "q")
			{
				return err;
			}else if (repeat == "y" || repeat == "yes")
			{
				//cary on with loop
				err =0;
			}else{
				std::cout << "Please answer y or n" << std::endl;
				continue;
			}

		}
		first =false;


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
			//check discriminant is positive
			if ((number[1]*number[1]-4*number[0]*number[2]) < 0)
			{
				std::cout << "No real roots try again!" << std::endl;
				err = 4;
				continue;
			}
			std::cout << "0 = " <<  number[0] << "x^2 + " << number[1] << "x + " << number[2] << " : x = " << solveQuadraticP(number[0], number[1], number[2]) << " or " << solveQuadraticN(number[0], number[1], number[2]) << std::endl;
		}else if (opperation == "3VectorLength")
		{
			std::cout << "v = ai + bj + ck : calculate |v|" << std::endl;
			std::vector<double> number = readInNumbers(3);
			std::cout << "v = " << number[0] << "i + " << number[1] << "j + " << number[2] << "k : |v| = " << vectorLength3(number[0], number[1], number[2]) << std::endl; 
		}else if (opperation == "help")
		{
			//help statement
			printHelp();
		}else{
			std::cout << "Operator not recognised"<<std::endl;
			err = 2;
			continue;
		}

	}

	return 0;
}