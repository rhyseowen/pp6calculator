#include <iostream>
#include <string>

int main()
{
	// comment
	/* This is a 
	   Multiline comment*/

	float a = 12;
	float b = 10;

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
		std::cout << "a / b = " << a/b <<std::endl; 	
	}else if (opperation == "*")
	{
		//multiplication
		std::cout << "a * b = " << a*b <<std::endl; 
	}else{
		std::cout << "Operator not recognised"<<std::endl;
		return 1;
	}


	return 0;
}