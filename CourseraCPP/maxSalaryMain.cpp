/*Title: Maximum Salary
Author: liamflann
Course: Data Structures and Algorithms, Algorithmic Toolbox, Coursera
Date: 12/14/2018
Task: Compose the largest number out of a set of integers.
Algorithim:  I didn't read the instructions properly, so this program dices up the vector
and sorts the numbers. For example: 45, 2, 93 would print as: 95432, but this is not the point
of the exercise. Instead, it should print 93452. This program correctly prints 21 2 as 221
Notes: Used starter code from Coursera */

#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <functional>
using namespace std;
using std::vector;
using std::string;

string largest_number(vector<int> a, int n) {

	int max;
	string newString;
	string newString2;
	string longString2;
	string longString3;
	vector<int> shortString(a.begin(), a.end());
	vector<int> longString(shortString.begin(), shortString.end());
	std::sort(longString.begin(), longString.end(), std::greater<int>());


	//std::sort(a.begin(), a.end(), std::greater<int>());
	for (int i = 0; i < n; i++) {
		max = longString[i];
		newString = std::to_string(max);
		longString2.append(newString);
	}
	int stringLen = longString2.length();
	vector<char> charList(longString2.begin(),longString2.end());

	vector<int>digits(stringLen);

	for (int i = 0; i < stringLen; i++) {
		int num = charList[i] - '0';
		digits[i] = num;
	}
	std::sort(digits.begin(), digits.end(), std::greater<int>());
	for (int i = 0; i < stringLen; i++) {
		max = digits[i];
		newString2 = std::to_string(max);
		longString3.append(newString2);
	}
	

	return longString3;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::cout << largest_number(a, n);
	system("pause");
}