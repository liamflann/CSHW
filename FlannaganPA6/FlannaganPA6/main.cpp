//Liam Flannagan Programming Assignment 6 03/15/2018

/*Problem Analysis:

This program asks the user to input a value for the temperature and the wind speed,
it then outputs the windchill based on the formula given in the homework problem.
According to the Wikipedia article, this formula has exponents in it, so this was
noted in the calculation (en.wikipedia.org/wiki/Wind_chill). This program uses
four modules: main function that outputs values, windchill function that calculates
windchill based on user input, and two void functions that prompt the user for input.
The data this program uses is the user input.

Algorithm:

1) Declare the functions to be used in the program: windchill, userinput1, userinput2,
invalidws. 2) Run first void function, userinput1, to prompt the user to enter the
temperature. 3) Run second void function to ask the user to enter a wind speed. 
3.a) If the windspeed in negative, tell the user that this is not a valid entry,
and ask again. 4) Declare the windchill function, and pass the user input for
speed and temperature to it. 5) Output the wind chill. 6) Terminate program.*/

#include <iostream>
#include <cmath>
#include <math.h> 
#include<iomanip>
using namespace std;

//Declare the functions.
double windchill(double speed, double temp);
void userinput1();
void userinput2();
void invalidws();

//Set up main function
int main()
{
	//Ask the user for input using the void function prompts, store tempterature in
	//t, and speed in s.
	double s, t;
	userinput1();
	cin >> t;
	userinput2();
	cin >> s;

	//Prevent user from entering a negative wind speed.
	while (s < 0) 
	{
		invalidws();
		userinput2();
		cin >> s;
	}
	
	//call the windchill function and output the results.
	cout << "The current temperature is " << t << "F" << endl;
	cout << "The windchill is " << windchill(s, t) << "F" << endl;
	system("pause");
	return 0;
	
}


double windchill(double speed, double temp)
{
	//Takes the user input from the main function, and runs it through this formula,
	//stores the windchill in wc to be output in the main function.
	double wc;
	wc = 35.74 + 0.6215 * temp - 35.75*pow(speed, 0.16) + 0.4275 * temp *pow(speed, 0.16);
	return wc;
}

//These three functions are called upon in the main function to prompt the user to
//input the temperature and windspeed, and to change their windspeed if they
//enter a negative value.
void userinput1()
{

	cout << "Please enter a temperature in Farenheit: " << endl;
}
void userinput2()
{
	cout << "Please enter the wind speed in miles per hour: " << endl;;

}
void invalidws()
{
	cout << "Wind speed cannot be negative. Please enter a postive value." << endl;
}
