#include <iostream>
#include "dataValidation.h"

int getInteger()
{
	int value;
	std::cin >> value;
	checkValidInput();
	return value;
}

// gets integer and compares it to expected values in range from min to max
int getInteger(int expectedMin, int expectedMax)
{
	int value = getInteger();
	compareValueWithExpectedValues(value, expectedMin, expectedMax);
	return value;
}

double getDouble()
{
	double value;
	std::cin >> value;
	checkValidInput();
	return value;
}