#include <iostream>
#include <vector>
using namespace std;


int fibseqFast(int &n) {

	vector<int> fibnum(n);
	int n2;
	int s = fibnum.size();


	//cout << fibnum[0,1,2,3,4,5] << endl;
	if (s <= 1) {
		n2 = n;
	}
	else if (s == 2) {
		n2 = 1;
	}
	else {
		fibnum[0] = 0;
		fibnum[1] = 1;
		for (int i = 2; i < s; i++) {
			fibnum[i] = (fibnum[i - 1] + fibnum[i - 2]) % 10;
			n = fibnum[i];
		}

		n2 = (n + fibnum[s - 2]) % 10;
	}



	return n2;
}

int main() {
	int n;
	cin >> n;

	int answer = fibseqFast(n);

	cout << answer << endl;


	system("pause");
	return 0;
}