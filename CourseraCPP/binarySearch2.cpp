/*Title: Binary Search
Author: liamflann
Course: Data Structures and Algorithms, Algorithmic Toolbox, Coursera
Date: 02/19/2019
Task: Find a requested value in a vector of values.
Algorithim:  Calculate the midPoint, compare the lookFor value and the midPoint, if they are
the same then return the midPoint ELSE if the lookFor is greater than the midPoint shift the 
left index to the midPoint +1 and recalculate the midPoint ELSE if the lookFor is less than the 
midPoint, shift the right index to the midPoint -1 and recalculate the midPoint
Assistance: used Geeks for Geeks for general help with the code since I couldnt' get my
initial algorithim to pass all cases, also consulted with the boards on Coursera
to improve performance time since the program timed out on case 32.*/

#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

static int binary_search(const vector<int> &a, int lookFor) {
	


	//for (size_t i = 0; i < a.size(); i++) {
		int left = 0, right = (int)a.size()-1;
		while (left <= right) {
			int midPoint = (left + (right - left) / 2);
			if (a[midPoint] == lookFor) {
				return midPoint;
			}
			else if (a[midPoint] < lookFor) {
				left = midPoint + 1;
			}
			else {
				right = midPoint - 1;

			}
		}
	//}




	return -1;
}


int main() {
	int n;

	std::cin >> n;
	vector<int> a(n);

	//Entering the array of numbers that we are going to search
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}

	//Entering the array of numbers that we want to find
	int m;
	std::cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; ++i) {
		std::cin >> b[i];
	}

	
	//Going to the binary search algorithm
	for (int i = 0; i < m; ++i) {
		std::cout << binary_search(a, b[i]) << ' ';
	}

	system("pause");
}
