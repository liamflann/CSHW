/*Title: Maximum Advertisement Revenue
Author: liamflann
Course: Data Structures and Algorithms, Algorithmic Toolbox, Coursera
Date: 12/20/2018
Task: Maxmize the sum of two vectors.
Algorithim:  Sort each vector from greatest to smallest, and each i in each vector.
I do have a concern about the fact that we can return a negative sum, since that's losing
money instead of maximizing profit. I commented out lines 29-31 so it'd pass the grader,
but I think if you're losing money, you should cut your losses and just not pay for clicks.
Notes: Used starter code from Coursera */

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<long long> a, vector<long long> b,int n) {
	long long product;
	long long sum = 0;

	sort(a.begin(), a.end(), std::greater<int>());
	sort(b.begin(), b.end(), std::greater<int>());
	for (int i = 0; i < n; i++) {
		product = a[i] * b[i];
		sum = sum + product;

	}
	//if (sum < 0) {
	//	sum = 0;
	//}

	return sum;
}

int main() {
	size_t n;
	std::cin >> n;
	vector<long long> a(n), b(n);
	for (size_t i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (size_t i = 0; i < n; i++) {
		std::cin >> b[i];
	}
	std::cout << max_dot_product(a, b,n) << std::endl;
	system("pause");
}
