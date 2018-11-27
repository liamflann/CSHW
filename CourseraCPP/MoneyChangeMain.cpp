/*Title: Money Change
Author: liamflann
Course: Data Structures and Algorithms, Algorithmic Toolbox, Coursera
Date: 11/27/2018
Task: Find the minimum  number of coins needed to change the integer input value
into coins with denominations 1, 5, 10.
Algorithim: 1) Find the number of times 10 goes into the value and save it.
2) Calculate the remainder after dividing by 10
3) Divide remainder by 5 and save that value
4) Calculate the remainder after dividing by 5 and save that as the ones value.
5) Add the values together and return the solution.*/

#include <iostream>
using namespace std;

int calculateChange(int money) {
	int tens;
	int fives;
	int remainder;

	//Calculate number of 10s
	tens = money / 10;
	remainder = money % 10;

	//Calculate number of 5s
	fives = (money-(tens*10)) / 5;
	remainder = (money-((tens*10-fives*5))) % 5;
	
	int soln = tens + fives + remainder;

	return soln;

}


int main() {
	int money;

	cin >> money;

	int soln = calculateChange(money);
	cout << soln << endl;
	system("pause");
	return 0;
}