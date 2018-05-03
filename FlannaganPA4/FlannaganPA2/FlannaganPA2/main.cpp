//*****************************************************************************
//Liam Flannagan 1/28/2018 Programming Assignment 2
//This C++ program asks the user for the size of the vehicle's tank in gallons
//and the vehicle's miles per gallon. It then outputs the total distance the
//vehicle can drive without refueling. It estimates to the lowest integer.
//*****************************************************************************

#include <iostream>
using namespace std;

int main()
{
	//Declares the variables used.
	int capacity;
	float mpg;
	int distance; //Because this is an integer data type, it will "round down."
	//Integer data types only keep the last whole number in the calculation.

	//This prompts the user for input
	cout << "Please enter the capacity of your vehicle's gas tank in gallons: ";
	cin >> capacity;
	cout << "Please enter the miles per gallon for your vehicle: ";
	cin >> mpg;
	
	//Now that the necessary variables have been initialized, we can write the formula
	distance = (capacity*mpg);

	//Outputs the users input as well as the total distance.
	cout << "Your vehilce's tank holds " << capacity << " gallons." << endl;
	cout << "Your vehicle's estimated miles per gallon is " << mpg << "." << endl;
	cout << "On one tank of gas, you can drive up to " << distance << " miles." << endl;

	system("pause");
	return 0;
}