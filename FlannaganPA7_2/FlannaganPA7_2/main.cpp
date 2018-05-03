//Liam Flannagan Programming Assignment 7 03/26/2018

/*Problem Analysis:

This program reads a line from user input that has a student's first and last name,
their social security number, user ID, and password. It then outputs these lines with
the student's name, x's over the student's social security number, their student ID,
and then x's over their password.

Algorithm:
1) Ask the user for their name, SS number, user ID (including S), and password. 2) Find
the first number of the social security number, subtract one from that index, and then
output the name from 0 to that point. 3) Find the beginning of the "s" number, to find the
number of characters of the the social. Replace those characters with x's. 4) Find the end of
the s number, and output the characters from the end of the ss number to the end of the
s number (student ID). 5) Take the string length and subtract all of the characters
calculated to this point, output x's reflecting the number of characters in the password
string.

*/

#include <iostream>
#include <string>
#include <array>

using namespace std;

int main()
{
	//Ask the user for info
	string sInfo;
	cout << "Please enter a student's name, social security number, user ID (including the 'S' of your S number), and password on one line: " << endl;
	getline(cin, sInfo);

	//Find the beginnings and endings of each component in the string.
	int ssStart = sInfo.find_first_of("0123456789", 0);
	int nameEnd = ssStart - 1;
	int ssEnd = sInfo.find_first_of("sS", ssStart) - 1;
	int ssLength = ssEnd - ssStart;
	int idStart = sInfo.find_first_of("sS", ssStart) + 2;
	int idEnd = sInfo.find_first_of(" ", idStart);
	int idLength = (idEnd - idStart) + 2;
	int stringLength = sInfo.length();
	int passLength = (stringLength - idEnd) - 1;

	//Account for if the user enters dashes for his/her social security number.
	if (ssLength < 10)
	{
		ssEnd = ssStart + 8;
	}
	else
	{
		int ssEnd = ssStart + 10;
	}
	//Replace the social with the masked social.	
	sInfo.replace(ssStart, 9, "xxx-xx-xxxx");

	//Output the name, masked social, student ID number.
	cout << sInfo.substr(0, nameEnd) << " ";
	cout << sInfo.substr(ssStart, 11) << " ";
	cout << sInfo.substr(idStart, idLength) << " ";
	//Output the x's reflecting the length of the password.
	int x = 0;
	while (x < passLength) {
		cout << "x";
		x++;
	}
	cout << "" << endl;

	system("pause");
	return 0;
}