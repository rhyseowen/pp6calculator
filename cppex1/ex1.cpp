#include <iostream>
#include <string>
#include <climits>
#include <vector>

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

std::vector<double> readInNumbers(int numbers)
{
	std::vector<double> in_numbers;

	for (int i = 0; i < numbers; ++i)
	{
		double number;
		std::cout << "Set number " << i+1 << std::endl << ": ";
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


		std::cout << "Which Operation would you like to perform (+,-,/,*)" << std::endl;
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

		switch(opperation)
		{
			case "+":
				//addtion
				std::cout << "a + b = ?" << std::endl;
				std::vector<double> number = readInNumbers(2);
				std::cout << number[0] << " + " << number[1] << " = " << addition(number[0],number[1]) <<std::endl;
				break;
			case "-":
				//subtraction
				std::cout << "a - b = ?" std::endl; 
				std::vector<double> number = readInNumbers(2);
				std::cout << number[0] << " - " << number[1] << " = " << subtraction(number[0],number[1]) <<std::endl;
				break;
			case "/":
				//division
				std::cout << "a / b = ?"
				std::vector<double> number = readInNumbers(2);
				if (number[1] == 0)
				{
					std::cout << "Cannot divide by 0!" << std::endl;
					err = 3;
					break;
				}
				std::cout << number[0] << " / " << number[1] << " = " << divide(number[0],number[1]) <<std::endl;
				break;
			case "*":
				//multiplication
				std::cout << "a * b = ?"
				std::vector<double> number = readInNumbers(2);
				std::cout << number[0] << " * " << number[1] << " = " << multiply(number[0],number[1]) <<std::endl;
				break;
			default:
				std::cout << "Operator not recognised"<<std::endl;
				err = 2;
				break;
		}

	}

	return 0;
}