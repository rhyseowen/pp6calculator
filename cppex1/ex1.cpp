#include <iostream>
#include <string>

int main()
{
	// comment
	/* This is a 
	   Multiline comment*/
	float a = 12;
	float b = 10;

	std::cout << "Set first number" << std::endl << ": ";
	std::cin >> a;

	if (!std::cin)
	{
		std::cout << "Number not recognised" << std::endl;
		return 1;
	}

	std::cout << "Set second number" << std::endl << ": ";
	std::cin >> b;
	
	if (!std::cin)
	{
		std::cout << "Number not recognised" << std::endl;
		return 1;
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
		return 1;
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
			return 3;
		}
		std::cout << "a / b = " << a/b <<std::endl; 	
	}else if (opperation == "*")
	{
		//multiplication
		std::cout << "a * b = " << a*b <<std::endl; 
	}else{
		std::cout << "Operator not recognised"<<std::endl;
		return 2;
	}


	return 0;
}