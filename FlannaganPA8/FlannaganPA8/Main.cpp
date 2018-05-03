//Liam Flannagan Programming Assignment 8 04/07/2018

/*Problem Analysis:

This program asks the user to enter the last names of 5 candidates in an
election, and the number of votes received by each candidate. It then outputs the
number of votes received, and the percentage of the total votes received by the
candidate. It will output the winner of the election. Data is from user input, 
the output will be combination of strings and numbers in table format.

Algorithm:
1) Ask the user for the last names of the candidates and the number of votes they
received.
2) Indexing over the 5 names, store the names and the values.
3) Indexing over the 5 numbers of votes, sum the votes.
4) Indexing over the 5 entries, output the names, number of votes, and % of the vote.
5) Indexing over the 5 votes, find the largest:
	a) If the vote is greater than the largest vote, then store vote in largest
	b) move to next vote total.
6) Output the results.
7) Terminate the program.


*/

#include <iostream>
#include <iomanip>
#include <string>
#include <array>

using namespace std;

int main()
{
	//Ask the user for info
	string names[5];
	double votes[5];
	double largest = 0.0;
	int totalvotes = 0;
	int i;
	string winner;

	cout << "Enter the names of the 5 candidates and the number of votes for each: " << endl;
	
	//Accept user input into the array for both names and votes.
	for (i = 0; i < 5; i++)
	{
		cin >> names[i] >> votes[i];
	}
	//Output table headers
	cout << left << setw(15) << "Candidate" << right << setw(10) << "Number of Votes" << 
		right<< setw(20) << "Percentage of Vote" << endl;
	//Sum the total votes
	for (i = 0; i < 5; i++) {
		totalvotes += votes[i];
	}
	//Output the candidate name, number of votes, and percentage of the vote
	for (i = 0; i < 5; i++) {
		cout << left << setw(15) << fixed << noshowpoint << setprecision(0) <<
			names[i] << right << setw(10) << votes[i] << right  << setw(20)
			<< fixed << showpoint << setprecision(2) << ((votes[i]/totalvotes)*100)<<"%"<< endl;
	}
	//Determine the candidate with the largest number of votes.
	for (i = 0; i < 5; i++) {
		if (largest < votes[i]) {
			largest = votes[i];
			winner = names[i];
		}
	}
	//Output the total number of votes, nd the winner of the election.
	cout << " " << endl;
	cout << "Total number of votes: " << totalvotes << endl;
	cout << "The winner of the election is: " << winner << endl;

	system("pause");
	return 0;
}


