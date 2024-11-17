#include <iostream>     
#include <sstream>
#include <fstream>
#include <string>
#include "pch.h" 
#include "CppUnitTest.h"
#include "E:\Portfolio\visual-studio\se_labs\lab3\calculateFunction\calculateFunction.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace NativeUnitTest
{
	void redirectCin(const std::string& input)
	{
		std::istringstream iss(input);
		std::cin.rdbuf(iss.rdbuf());
	}

	TEST_CLASS(calculateFunctionTests)
	{
	public:

		TEST_METHOD(calculateFunction_get3and6_returned6_85)
		{
			int x = 3;
			int n = 6;
			double expected = 6.85; 

			double actual = calculateFunction(x, n);

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(calculateFunction_getMinus2and5_returned0)
		{
			int x = -2;
			int n = 5;
			double expected = 0;

			double actual = calculateFunction(x, n);

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(calculateFunction_get18and6_returned41_1)
		{
			int x = 18;
			int n = 6;
			double expected = 41.1;

			double actual = calculateFunction(x, n);

			Assert::AreEqual(expected, actual);
		}
	};

	TEST_CLASS(askPermissionToSaveDataTests)
	{
	public:
		TEST_METHOD(askPermissionToSaveData_streamGot1_trueReturned)
		{
			std::istringstream input("1");
			std::cin.rdbuf(input.rdbuf());

			int expected = 1;
			int actual = askPermissionToSaveData();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(askPermissionToSaveData_streamGot0_falseReturned)
		{
			std::istringstream input("0");
			std::cin.rdbuf(input.rdbuf());  

			int expected = 0;
			int actual = askPermissionToSaveData();

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD(askPermissionToSaveData_streamGot2_exeptionThrown)
		{
			redirectCin("2");

			try
			{
				askPermissionToSaveData();
				Assert::Fail(L"Expected an exception to be thrown for invalid input.");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(askPermissionToSaveData_streamGotNonNumericValue_exeptionThrown)
		{
			redirectCin("abc");
			try
			{
				askPermissionToSaveData();
				Assert::Fail(L"Expected an exception to be thrown for non-numeric input.");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};

	TEST_CLASS(checkValidInputTests)
	{
	public:
		TEST_METHOD(checkValidInput_validInput_noExeptionThrown)
		{
			redirectCin("1");

			try
			{
				checkValidInput();
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail(L"Expected no exception to be thrown for valid input.");
			}
		}
		TEST_METHOD(checkValidInput_streamFailure_exceptionThrown)
		{
			std::cin.setstate(std::ios::failbit);

			try
			{
				checkValidInput();
				Assert::Fail(L"Expected an exception to be thrown for stream failure.");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}

			std::cin.clear();
		}
	};

	TEST_CLASS(chechValidIntervalTests)
	{
	public:
		TEST_METHOD(checkValidInterval_get3and6_noExeptionThrown)
		{
			int a = 3;
			int b = 6;

			try
			{
				checkValidInterval(a, b);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail(L"Expected no exeption to be thrown for valid interval");
			}
		}
		TEST_METHOD(checkValidInterval_get3and3_ExeptionThrown)
		{
			int a = 3;
			int b = 3; 

			try
			{
				checkValidInterval(a, b);
				Assert::Fail(L"Expected an exeption to be thrown for invalid interval");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
		TEST_METHOD(checkValidInterval_get10and3_ExeptionThrown)
		{
			int a = 10;
			int b = 3;

			try
			{
				checkValidInterval(a, b);
				Assert::Fail(L"Expected an exeption to be thrown for invalid interval");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};

	TEST_CLASS(checkValidStepTests)
	{
	public:
		TEST_METHOD(checkValidStep_get1_noExeptionThrown)
		{
			int h = 1;

			try
			{
				checkValidStep(h);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail(L"Expected no exeption to be thrown for valid step");
			}
		}
		TEST_METHOD(checkValidInterval_get0_ExeptionThrown)
		{
			int h = 0;

			try
			{
				checkValidStep(h);
				Assert::Fail(L"Expected an exeption to be thrown for invalid step");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};

	TEST_CLASS(checkValidParameterTests)
	{
	public:
		TEST_METHOD(checkValidParameter_get4_noExeptionThrown)
		{
			int n = 4; 

			try
			{
				checkValidParameter(n);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail(L"Expected no exeption to be thrown for valid parameter");
			}
		}
		TEST_METHOD(checkValidInterval_get2_ExeptionThrown)
		{
			int n = 2;

			try
			{
				checkValidParameter(n);
				Assert::Fail(L"Expected an exeption to be thrown for invalid parameter");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};

	TEST_CLASS(checkPermissionInputTests)
	{
	public:
		TEST_METHOD(checkPermissionInput_get1_noExeptionThrown)
		{
			int permission = 1;

			try
			{
				checkPermissionInput(permission);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail(L"Expected no exeption to be thrown for valid permission input");
			}
		}
		TEST_METHOD(checkPermissionInput_get0_noExeptionThrown)
		{
			int permission = 0;

			try
			{
				checkPermissionInput(permission);
				Assert::IsTrue(true);
			}
			catch (...)
			{
				Assert::Fail(L"Expected no exeption to be thrown for valid permission input");
			}
		}
		TEST_METHOD(checkPermissionInput_get2_ExeptionThrown)
		{
			int permission = 2; 

			try
			{
				checkPermissionInput(permission);
				Assert::Fail(L"Expected an exeption to be thrown for invalid numeric permission input");
			}
			catch (...)
			{
				Assert::IsTrue(true);
			}
		}
	};

	TEST_CLASS(writeDataTests)
	{
	public:
		std::string readFileData(const std::string& filename)
		{
			std::ifstream file(filename);
			std::ostringstream ss;
			ss << file.rdbuf();
			return ss.str();
		}

		TEST_METHOD(writeData_dataSaved)
		{
			std::ofstream clearFile("test.txt", std::ios::trunc);
			clearFile.close();

			writeData(3, 6.85, 6); 

			std::string expected = "x = 3, y = 6.85, n = 6\n";
			std::string actual = readFileData("test.txt");

			Assert::AreEqual(expected, actual);
		}
		TEST_METHOD_CLEANUP(Cleanup)
		{
			std::remove("test.txt");
		}
	};
}
