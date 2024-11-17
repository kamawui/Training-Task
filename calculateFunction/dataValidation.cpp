#include <iostream>
#include <string>

// checks if cin function failed, clears unnecessary input
void checkValidInput()
{
	if (std::cin.fail())
	{
		throw std::invalid_argument("Invalid input value."); // a type from snandart library was given to exeption
	}
	std::cin.ignore(32767, '\n'); 
}

// throws error if a >= b
void checkValidInterval(double a, double b)
{
	if (a >= b)
	{
		throw std::invalid_argument("Invalid interval values: start value can`t be bigger than end value or equal to that."); // a type from snandart library was given to exeption
	}
}

// throws error if h < 1
void checkValidStep(double h)
{
	if (h <= 0)
	{
		throw std::invalid_argument("Invalid step value: step must be bigger than 0."); // a type from snandart library was given to exeption
	}
}

// throws error if n < 3
void checkValidIterator(int n)
{
	if (n <= 0)
	{
		throw std::invalid_argument("Invalid iterator n value: parameter must be bigger than 0."); // a type from snandart library was given to exeption
	}
}

// throws error if value is not in range from min to max
void compareValueWithExpectedValues(int value, int expectedMin, int excpectedMax)
{
	if (value < expectedMin || value > excpectedMax)
	{
		throw std::logic_error("Invalid input value: expected values from "
			+ std::to_string(expectedMin)
			+ " to "
			+ std::to_string(excpectedMax));
	}
}