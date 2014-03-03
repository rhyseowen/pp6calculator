#include <iostream>
#include <string>
#include <climits>

int main()
{
	// comment
	/* This is a 
	   Multiline comment*/

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


		float a = 12;
		float b = 10;

		std::cout << "Set first number" << std::endl << ": ";
		std::cin >> a;

		if (!std::cin)
		{
			std::cout << "Number not recognised" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n'); 
			err = 1;
			continue;
		}

		std::cout << "Set second number" << std::endl << ": ";
		std::cin >> b;
		
		if (!std::cin)
		{
			std::cout << "Number not recognised" << std::endl;
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			err = 1; 
			continue;
		}


		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;

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

		if (opperation == "+")
		{
			//addition
			std::cout << "a + b = " << a+b <<std::endl;  
		}else if (opperation == "-")
		{
			//subtraction
			std::cout << "a - b = " << a-b <<std::endl; 
		}else if (opperation == "/")
		{
			//division
			if (b == 0)
			{
				std::cout << "Cannot divide by 0!" << std::endl;
				err = 3;
				continue;
			}
			std::cout << "a / b = " << a/b <<std::endl; 	
		}else if (opperation == "*")
		{
			//multiplication
			std::cout << "a * b = " << a*b <<std::endl; 
		}else{
			std::cout << "Operator not recognised"<<std::endl;
			err = 2;
			continue;
		}

	}

	return 0;
}