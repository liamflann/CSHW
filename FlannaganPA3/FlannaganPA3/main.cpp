//*****************************************************************************
/*Liam Flannagan 2/12/2018 Programming Assignment 3
This C++ program reads an input file containing information about ticket sales
to a football game. It then outputs a file containing total tickets sold, and
total revenue from that game.*/
//*****************************************************************************

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	double price, sold, box, sideline, premium, GA, rev, seats1, 
		seats2, seats3, seats4, seats;

	//Accesses file, and creates new file for export.
	inFile.open("football.txt");
	outFile.open("ticketsSold.txt");

	cout << "Processing" << endl;
	cout << "See ticketsSold.txt for the results." << endl;

	//Sets up the precision for the output values (to two decimal places).
	outFile << fixed << showpoint;
	outFile << setprecision(2);

	/*Ignores the text lines at beginning, stores the total revenue from 
	price * sold. Saves the number of seats sold per ticket price. */
	inFile.ignore(100, '\n');
	inFile >> price >> sold;
	box = price * sold;
	seats1 = sold;
	inFile >> price >> sold;
	sideline = price * sold;
	seats2 = sold;
	inFile >> price >> sold;
	premium = price * sold;
	seats3 = sold;
	inFile >> price >> sold;
	GA = price * sold;
	seats4 = sold;

	//Calculates the total revenue and seats sold.
	rev = box + sideline + premium + GA;
	seats = seats1 + seats2 + seats3 + seats4;
	
	//Changes the number of tickets sold to an integer value, outputs revenue. 
	outFile << "Number of tickets sold = " << static_cast<int>(seats) << endl;
	outFile << "Sale amount = $" << rev << endl;

	//Closes files.
	inFile.close();
	outFile.close();
	system("pause");
	return 0;
}

