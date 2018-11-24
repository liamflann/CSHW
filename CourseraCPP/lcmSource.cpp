/*Week 2 PA: Least Common Multiple. This program finds the LCM of any two
numbers using an efficent algorithm. It makes use of the property that
a * b = gcd(a,b)*lcm(a,b). Problem solves for gcd first, then finds lcm.*/

#include <iostream>
using namespace std;

long long gcdalgo(long long a, long long b) {
	long long gcd;
	long long lcm;
	long long x = a;
	long long y = b;
	long long product;
	long long remainder;

	if (b > a) {
		x == b;
		y == a;
	}

	while (y > 0) {
		remainder = x % y;
		x = y;
		y = remainder;
	}

	gcd = x;
	product = a * b;
	lcm = product / gcd;
	//lcm = long long ((a*b) / gcd);


	return lcm;
}

int main() {
	long long a, b;
	cin >> a;
	cin >> b;

	long long soln = gcdalgo(a, b);
	cout << soln << endl;

	system("pause");
	return 0;
}