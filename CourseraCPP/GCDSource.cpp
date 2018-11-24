/*Week 2 PA: Greatest Common Divisor. This program finds the GCD of any two
numbers using an efficent algorithm. It makes use of the property that
if remainder = a mod b then gcd(a,b) = gcd(remainder, b)*/

#include <iostream>
using namespace std;

int gcdalgo(int a, int b) {
	int gcd;
	int remainder;

	if (b > a) {
		a == b;
		b == a;
	}

	while (b > 0) {
		remainder = a % b;
		a = b;
		b = remainder;
	}

	gcd = a;


	return gcd;
}

int main() {
	int a, b;
	cin >> a;
	cin >> b;

	int soln = gcdalgo(a, b);
	cout << soln << endl;

	system("pause");
	return 0;
}