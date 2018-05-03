//Liam Flannagan Programming Assignment 9 04/21/2018

/*Problem Analysis:
This program reads a file of students names' followed by their test scores. 
Then It outputs the name followed by grade. It also finds the highest test 
scores, and prints the scores and the student's name.

Algorithm:
1) Declare the structure of name, testscore, and grade under studentTYpe
2) Set up functions to call for loading the students, printing the students
and their letter grades, and determining the higest scores
3) Call the functions in the appropriate order in the main function
4) Open the file and store the names in the appropriate variables
5) Determine the grades based on a standar scoring system (10 points)
6) Open the output file, print the students' names, scores, and letter
grades.
7) Calculate the highest grade
8) Print the names of the students with the highest grades
9) Terminate the program.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <array>

using namespace std;

//Setting up struct
struct studentType
{
	string studentFName;
	string studentLName;
	int testScore;
	char grade;
};

//Declaring the functions to be used in the program
const int MaxStudents = 20;
void getStudents(studentType[], int&);
void printStudents(const studentType[], const int);
void gradeStudents(studentType[], int&);

//Setting up main function where we call the three void functions declared
//above.
int main()
{
	studentType students[MaxStudents];
	int numStudents = 0;

	getStudents(students, numStudents);
	gradeStudents(students, numStudents);
	printStudents(students, numStudents);

	cout << "See GradedStudents.txt file" << endl;
	
	system("pause");
	return 0;
}
//Open the file and get the load the students' information into the 
//appropriate variable by looping through the names.

void getStudents(studentType s[], int& count)
{
	count = 0;
	ifstream inFile; //input file stream variable
	inFile.open("students.txt");

	while (inFile && count < MaxStudents) {

		// load the First name
		inFile >> s[count].studentFName;
		inFile >> s[count].studentLName;
		inFile >> s[count].testScore;

		count++;
	}

	inFile.close();
}

//Loop through all the students and assign grades.
void gradeStudents(studentType s[], int& count)
{
	for (int i = 0; i < count; i++) {
		if (s[i].testScore >= 90)
			s[i].grade = 'A';
		else if (s[i].testScore >= 80)
			s[i].grade = 'B';
		else if (s[i].testScore >= 70)
			s[i].grade = 'C';
		else if (s[i].testScore >= 60)
			s[i].grade = 'D';
		else
			s[i].grade = 'F';

	}
}

//Open the output file and print the names and grades of students
//Then calculate the highest grade by looping through
//Then output highest grade and all students who have highest grade.
void printStudents(const studentType s[], const int count)
{
	ofstream outFile; //output file stream variable
	outFile.open("GradedStudents.txt");
	outFile << setw(10) << "Student Name" << setw(22) << "Score" << setw(10) << "Grade"<< endl;
	outFile << setw(35) << setfill(' ') << endl;

	for (int i = 0; i < count; i++) {
		outFile << left
			<< setw(10) << s[i].studentLName
			<<  ", "
			<< setw(10) << s[i].studentFName
			<< right
			<< setw(10) << s[i].testScore
			<< setw(10) << s[i].grade
			<< endl;
	}

	int i = 0;
	int best = s[0].testScore;

	for (i = 0; i < count; i++)
	{
		if (best<s[i].testScore)
			best = s[i].testScore;
	}
	outFile << " " << endl;
	outFile << "The highest grade is: " << best << endl;
	outFile << "" << endl;
	outFile << "The following students had the highest grade:" << endl;

	for (i = 0; i < count; i++)
	{
		if (s[i].testScore == best)
		{
			outFile << s[i].studentLName << ", " << s[i].studentFName << endl;
		}
	}

	outFile.close();
}

