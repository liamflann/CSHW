//*****************************************************************************
// Liam Flannagan 01/25/2018 Programming Assignment 1
//Given three real numbers, this C++ program computes and ouputs their average
//*****************************************************************************

#include <iostream>
using namespace std;

int main()
{
	//Declaring the variables as integer values and describing what this program does.
	int num1 =115;
	int num2 = 29;
	int num3 = -15;
	int average;

	cout << "Program to compute the average of three numbers." << endl;

	//Setting a value to each variable defined above.
	//This then uses these values to determine their average.
	//num1 = 115;
	//num2 = 29;
	//num3 = -15;
	average = (num1 + num2 + num3) / 3;

	
	//Tells the user the values of the three numbers and their average.
	cout << "The three input numbers are: " << num1 <<", " << num2 <<", " << num3 << endl;
	cout << "Their average is " << average << endl;

	//Pauses the system so that the user can actually see the output.
	system("pause");
	return 0;





}