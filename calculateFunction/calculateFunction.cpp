#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include "json.hpp"
#include "parserJSON.h"
#include "dataValidation.h"
#include "getData.h"

// saves all calculations to a text file
void writeDataToTXT(double x, double y, int n)
{
	std::ofstream file("test.txt", std::ios::app);
	checkIfFileOpened(file);
	file << "x = " << x << ", n = " << n << ", y = " << y << std::endl;
}

// saves all calculations in csv format
void writeDataToCSV(double x, double y, int n)
{
	std::ofstream file("test.csv", std::ios::app);
	checkIfFileOpened(file);
	file << x << ";" << n << ";" << y << std::endl;
}

// calculates value with formula
double calculateFunction(double x, int n)
{
	if (x >= 0)
	{
		double sum = 0;

		for (int i = 1; i < n; i++)
		{
			sum += (double)x / i;
		}

		return sum;
	}
	else
	{
		double mult = 1;

		for (int i = 0; i < n; i++)
		{
			double sum = 0;

			for (int j = 1; j <= n; j++)
			{
				sum += ((double)x - i + j) * (x - i + j) * (x - i + j);
			}

			mult *= sum;
		}

		if (mult == -0.0)
		{
			mult = 0.0;
		}

		return mult;
	}
}

// gets a, b, h, n and sets their values with reference
void getParametersFromUser(double& a, double& b, double& h, int& n)
{
	std::cout << "Enter start value a: ";
	a = getDouble();
	std::cout << "Enter end value b: ";
	b = getDouble();
	checkValidInterval(a, b);

	std::cout << "Enter step value h: ";
	h = getDouble();
	checkValidStep(h);

	std::cout << "Enter iterator value n: ";
	n = getInteger();
	checkValidIterator(n);
}

// gets a, b, h, n from JSON config
void getParametersFromConfiguration(double& a, double& b, double& h, int& n)
{
	nlohmann::json config = parseJSON("config.json")["parameters"];
	a = config["start"];
	b = config["end"];
	checkValidInterval(a, b);
	h = config["step"];
	checkValidStep(h);
	n = config["iterator"];
	checkValidIterator(n);
}

// updates a, b, h, n in JSON config
void setParametersInConfiguration(double a, double b, double h, int n)
{
	nlohmann::json config = parseJSON("config.json");
	config["parameters"]["start"] = a;
	config["parameters"]["end"] = b;
	config["parameters"]["step"] = h;
	config["parameters"]["iterator"] = n;

	std::ofstream file("config.json");
	checkIfFileOpened(file);

	file << config.dump(4);
	file.close();
}

// calculates function and saves result depending on parameter
void performCalculations(double a, double b, double h, int n, int resultSavingWay) {
	for (double x = a; x < b; x += h) {
		double y = calculateFunction(x, n);

		if (resultSavingWay == 1) {
			std::cout << "If x = " << x << " and n = " << n << ", then y = " << y << "\n";
		}
		else if (resultSavingWay == 2) {
			writeDataToTXT(x, y, n);
		}
		else if (resultSavingWay == 3) {
			writeDataToCSV(x, y, n);
		}
	}
}

int main()
{
	double a, b, h;
	int n;

	std::cout << "Welcome to the function calculator.\n";

	try
	{
		std::cout << "Choose a way to set parameters for function.\n"
			<< "Enter \"1\" to use configuration file, enter \"2\" to set parameters yourself: ";
		int parametersSettingWay = getInteger(1, 2);

		if (parametersSettingWay == 1)
		{
			getParametersFromConfiguration(a, b, h, n);
		}
		else if (parametersSettingWay == 2)
		{
			getParametersFromUser(a, b, h, n);
			setParametersInConfiguration(a, b, h, n);
		}


		while (true)                                                     // restart 
		{
			std::cout << "Enter \"1\" to view results in console, " <<
				"enter \"2\" to save calculations in text file, " <<
				"enter \"3\" to save calculations in CSV format: ";
			int resultSavingWay = getInteger(1, 3);

			performCalculations(a, b, h, n, resultSavingWay);

			std::cout << "Enter \"1\" to restart program with same parameters, " <<
				"enter \"2\" to end program: ";
			int restartProgram = getInteger(1, 2);

			if (restartProgram == 2)
			{
				std::cout << "Program has finished its work.";
				break;
			}


			std::cout << "Restarting..\n\n";
		}
	}
	catch (const char* ex)
	{
		std::cerr << ex << std::endl;
		return -1;
	}
	catch (const std::runtime_error& e)
	{
		std::cerr << "Runtime error. " << e.what() << std::endl;
		return -2;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Wrong argument error. " << e.what() << std::endl;
		return -3;
	}
	catch (const std::logic_error& e)
	{
		std::cerr << "Logic error. " << e.what() << std::endl;
		return -4;
	}
	catch (...)
	{
		std::cerr << "Unknown error. " << std::endl;
		return -5;
	}

	return 0;
}


