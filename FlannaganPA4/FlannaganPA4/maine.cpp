//*****************************************************************************
/*Liam Flannagan 2/19/2018 Programming Assignment 4
This C++ program asks the user for a total number of cookies. It then outputs
the number of boxes required to store those cookies, and the number of leftover
cookies, if there are any. It also outputs the number of containers needed to 
store the boxes, and outputs the number of leftover boxes, if any.*/
//*****************************************************************************

#include <iostream>
using namespace std;

int main()
{
	//Setting up the variables
	int box, container, cookies, leftoversbox, leftoverscont;
	box = 24; //24 cookies per box
	container = 75; //75 boxes per container

	/*Requests user for number of cookies, and then evaluates if cookies < 24
	if there are any leftover, and outputs the number of boxes and leftovers
	where applicable*/
	cout << "Please enter the total number of cookies: ";
	cin >> cookies;
	if (cookies < 24)
	{
		cout << "You do not have enough cookies for a box." << endl;
	}
	else if (cookies % box == 0)
	{
		box = cookies / box;
		cout << "The total number of boxes needed is: " <<
			cookies / box << endl;
	}
	else
	{
		leftoversbox = cookies % box;
		box = cookies / box;
		cout << "The total number of boxes needed is: " << box << endl;
		cout << "You have " << leftoversbox << " cookies leftover" << endl;
	}

	/*Using the previous user input on cookies, this calculates if the user
	requires a container for his boxes, outputs the number of containers and
	the number of extra boxes, if applicable.*/
	if (box < container)
	{
		cout << "You do not need a container.";
	}
	else if (box % container == 0)
	{
		container = box / container;
		cout << "The total number of containers needed is: " << container << endl;
	}
	else
	{
		leftoverscont = box % container;
		container = box / container;
		cout << "The total number of containers needed is: " << container << endl;
		cout << "The total number of boxes left over is: " << leftoverscont << endl;
	}

	system("pause");
	return 0;
}
