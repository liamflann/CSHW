/*Title: Financial Fractional Napsack
Author: liamflann
Course: Data Structures and Algorithms, Algorithmic Toolbox, Coursera
Date: 11/30/2018
Task: Find the most valuebale combination of items assuming any fraction of an item can
be placed into a bag.
Algorithim: 1) after receiving user input in stored in a vector, calculate the per unit price
and store that in a vector as well; 2) create another vector holding the indices so that the per
unit price can be matched up with the value and weight vectors after sorting; 3) Definite work around, 
for this first step, but if there is only one item and it's weight is less than the capacity, 
output the entire value; 4) while the weight added to the bag is less than the capacity: 4a) find the
index of the highest price per unit; 4a1) if the weight at that index is less than the capacity then
add the weight to the weightAdded and the value to cashAdded; 4a2) else multiply the capacity by the
per unit price and add any previous cashAdded to this value; 5) zero out the per unit price for the used
index so that it is not selected in the next loop.
Notes: Used starter code from Coursera;
also commented out the cout lines for submission to Coursera, but kept in for debugging purposes*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values, double n) {
	double value = 0.0;
	double x = 0;
	double pUnitValueA = 0;
	double pUnitValueB = 0;
	double maxPerUnit = 0;
	double maxPerUnitIndex = 0;
	double valueIndex = 0;
	double weightIndex = 0;
	double weightAdded = 0;
	double cashAdded = 0;

	vector<double> perUnit;
	vector<double> perUnitIndex;
	/*cout << capacity << endl;*/
	for (int i = 0; i < n; i++) {
		//cout << "Step: " << i << endl;
		pUnitValueA = values[i] / weights[i];

		perUnit.push_back(pUnitValueA);
		//cout << "Index: " << i << " Weight: " << weights[i] << " Values: " << values[i] << " pkg: " << perUnit[i] << endl;


		
		maxPerUnitIndex = distance(perUnit.begin(), max_element(perUnit.begin(), perUnit.end()));
		//maxPerUnit = values[maxPerUnitIndex] / weights[maxPerUnitIndex];
		
	}
	double capacity2 = capacity;

	if (n < 2 && weights[0] < capacity2) {
		weightAdded = capacity2;
		cashAdded = values[0];
	}
	
	while (weightAdded < capacity2) {
		maxPerUnitIndex = distance(perUnit.begin(), max_element(perUnit.begin(), perUnit.end()));

		if (weights[maxPerUnitIndex] < capacity) {
			weightAdded = weightAdded + weights[maxPerUnitIndex];
			cashAdded = cashAdded + values[maxPerUnitIndex];
			//cout << cashAdded << " cash" << endl;
			//cout << weightAdded << " weight" << endl;
			//cout << capacity << " capacity" << endl;
			
		}
		else {
			cashAdded = capacity*perUnit[maxPerUnitIndex]+cashAdded;
			weightAdded = weightAdded + capacity;
		}
		capacity = capacity2 - weightAdded;
		perUnit[maxPerUnitIndex] = 0;
	}
	

	return cashAdded;
}



int main() {
	double n;
	double capacity;
	//cout << "Please enter the number of items and the capacity of the nap sack" << endl;
	cin >> n >> capacity;
	vector<double> values(n);
	vector<double> weights(n);
	//cout << "For each item, please enter the value and the weight of the item." << endl;
	for (int i = 0; i < n; i++) {
		cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values, n);

	cout.precision(10);
	cout << optimal_value << endl;
	system("pause");
	return 0;
}