/*********************************************************************************************************
Liam Flannagan, Programming Assignment 5, 3/10/2018
This program asks the user for two numbers, where the second number is greater than the first. It then
outputs the following information:
	-all odd numbers between first and second numbers. 
	-sum of all even numbers between first and second numbers.
	-numbers and their squares between 1 and 10.
	-sum of the square of the odd numbers between first and second numbers.
	-all uppercase letters.
* *******************************************************************************************************/

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


int main() {
	int firstNum;
	int secondNum;
	int nEvens1, nEvens2, nEvens;
	int n, s, m, se;
	int sum, sum2;
	int asciinumber;
	
	cout << "Please enter two integers, with your second number being greater than the first: " << endl;
	cout << "First Number: ";
	cin >> firstNum;
	cout << "Second number: ";
	cin >> secondNum;

	/*Count the number of evens between the two numbers. These lines are used repeatedly throughout
	the code, and are updated to ensure that the program is counting the correct number of 
	evens and/or odd numbers between the two integers.*/
	nEvens1 = (secondNum / 2);
	nEvens2 = (firstNum / 2);
	nEvens = nEvens1 - nEvens2 + 1;

	/*This block of code only addresses if the first number is even, so that we can count up
	from that number accordingly.*/
	if (firstNum % 2 == 0)
	{
		/*While our counter is less than or equal to the number of even numbers between firstNum
		and secondNum, the program calculates the sum of the even integers between firstNum and
		secondNum.*/
		n = 0;
		s = 0;
		sum = 0;
		while (n <= nEvens)
		{
			sum = s + sum;
			s = firstNum + 2 * n;
			n++;
		}

		/*Similar to immediately above, this calculates the sum of the squares of the odd numbers
		between firstNum and secondNum*/
		n = 1;
		s = 0;
		sum2 = 0;
		while (n <= nEvens)
		{
			sum2 = s + sum2;
			s = pow((2 * n + firstNum-1), 2);
			n++;
		}
		
		/*This outputs the odd numbers between firstNum and secondNum*/
		cout << "The odd numbers are:" << endl;
		while (firstNum <= secondNum-1)
		{
			cout << firstNum + 1 << endl;
			firstNum = firstNum + 2;
			
		}

		/*This portion outputs all the answers in the order listed on the programming assignment, 
		also outputs first ten numbers and their squares.*/
		cout << "The sum of even numbers is : " << sum << endl;
		cout << "Numbers 1 through 10 and their squares: " << endl;
		m = 0;
		cout << "Number" << "        " << "Square" << endl;

		for (m = 1; m <= 10; m++)
		{
			cout << m << "            " << pow(m,2)<< endl;
		}

		cout << "The sum of the squares of the odds is: " << sum2 << endl;
	}
	/*This block of code only addresses if the first number is odd, so that we can count up
	from that number accordingly.*/
	else
	{
		/*While our counter is less than or equal to the number of even numbers between firstNum
		and secondNum, the program calculates the sum of the even integers between firstNum and
		secondNum. The counter corrects for the fact that we do not have the same number of evens
		and odds since our first digit is odd.*/
		n = 0;
		s = 0;
		sum = 0;
		se = firstNum + 1;
		while (n <= nEvens-1)
		{
			sum = s + sum;
			s = se + 2 * n;
			n++;
		}

		/*Similar to above, but sums the square of the odds between firstNum and secondNum,
		accounting for the difference in number of even numbers vs number of odd numbers*/
		n = 1;
		s = 0;
		sum2 = 0;
		while (n <= nEvens + 1)
		{
			sum2 = s + sum2;
			s = pow((2 * n + firstNum - 2), 2);
			n++;
		}

		/*Outputs all the odd numbers between firstNum and secondNum, inclusive.*/
		cout << "The odd numbers are:" << endl;
		while (firstNum <= secondNum)
		{
			cout << firstNum << endl;
			firstNum = firstNum + 2;
		}

		/*Outputs the answers in the order requested on the programming assignment.
		Outputs the first 10 integers and their squares.*/
		cout << "The sum of even numbers is : " << sum << endl;
		cout << "Numbers 1 through 10 and their squares: " << endl;
		m = 0;
		cout << "Number" << "        " << "Square" << endl;

		for (m = 1; m <= 10; m++)
		{
			cout << m << "            " << pow(m, 2) << endl;
		}

		cout << "The sum of the squares of the odds is: " << sum2 << endl;
	}

	//Outputs all capital letters.
	for (asciinumber = 65; asciinumber < 91; asciinumber++)
	{
		cout << (char)asciinumber;
	}
	cout<< "" << endl;

	system("pause");
	return 0;
}