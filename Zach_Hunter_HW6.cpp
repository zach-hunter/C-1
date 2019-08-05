// Zach_Hunter_HW6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

double sq(double n) { //squaring function
	return n * n;
}

double cube(double n) {  //cubing function
	return n * n * n;
}

string oddeven(double n) {  //determines if odd, even, or fraction
	int i = n;
	if (n != i) {
		return "N/A";
	}
	if (i % 2 == 0) {
		return "Even";
	}
	else {
		return "Odd";
	}
	
}

string isitprime(double n) {
	int i = n;
	if (n != i) {
		return "N/A";
	}
	int counter = 2;
	double answer = 100;
	if (i % 2 == 0 && i != 2 || i == 1) {
		return "False";
	}
	else {
		while (counter < answer) {
			answer = n / counter;
			if (i % counter == 0 && i != 2) {
				return "False";
				break;
			}
			counter++;
		}

		return "True";
	}
}

int main()
{
	int tablesize = 0;
	double startnum = 0.0;
	double incrementnum = 0.0;
	const int tablemax = 25;
	while(true) {
		cout << "How many values do you want in the table?(1 to 25; 0 to exit) ";
		cin >> tablesize;
		if (tablesize == 0) {
			break;
		}
		while (tablesize < 1 || tablesize > 25 || cin.fail()) {	//loop for validation 
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Please enter a valid table size between 1 and 25: ";
			cin >> tablesize;
		}
		cout << "What will be the first value in the table?(-1000 to +1000) ";
		cin >> startnum;
		while (startnum < -1000 || startnum > 1000 || cin.fail()) {	//loop for validation 
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Please enter a valid starting number between -1000 and 1000: ";
			cin >> startnum;
		}
		cout  << "What will be the increment between values in the table?(1 to 20) ";
		cin >> incrementnum;
		while (incrementnum < 1 || incrementnum > 20 || cin.fail()) {	//loop for validation 
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Please enter a valid increment between 1 and 20: ";
			cin >> incrementnum;
		}
		double defaulttable[tablemax];	//making all the tables
		double squaretable[tablemax];
		double sqrttable[tablemax];
		double cubetable[tablemax];
		double cuberttable[tablemax];
		string evenoddtable[tablemax];
		string primetable[tablemax];
		string result;
		ostringstream convert;
		defaulttable[0] = startnum;
		for (int i = 0; i < tablesize; i++) {  //iterating all the arrays
			if (i == 0) {
				defaulttable[i] = startnum;
			}
			else {
				defaulttable[i] = defaulttable[i-1] + incrementnum;
			}
			squaretable[i] = sq(defaulttable[i]); //square table
			//if (defaulttable[i] < 0) {
			//	sqrttable[i] = "N/A"; //square root table
			//	cuberttable[i] = "N/A";  //cube root table
			//}
			//else {	

			//}
			sqrttable[i] = sqrt(defaulttable[i]);
			cuberttable[i] = pow(defaulttable[i], 1/3.);
			cubetable[i] = cube(defaulttable[i]);  //cube table
			evenoddtable[i] = oddeven(defaulttable[i]);  //even/odd table
			primetable[i] = isitprime(defaulttable[i]);  //prime table

		}
		string sepertator = "";
		for (int i = 0; i < 83; i++) {
			sepertator = sepertator + "-";
		}

		cout << setw(11) << "User Table" << "|" << setw(11) << "Squared  " << "|" << setw(11) << "Square Root" << "|" << setw(11) << "Cubed  " << " |" << setw(11) << "Cube Root " << "|" << setw(11) << "Even or Odd" << "|" << setw(11) << "Prime?" << endl;
		cout << sepertator << endl;
		for (int i = 0; i < tablesize; i++) {
			cout << "  " << setw(9) << setprecision(9) << defaulttable[i] << "|  " << setw(9) << setprecision(9) << squaretable[i] << "|  ";
			if (defaulttable[i] < 0) {
				cout << setw(9) << setprecision(8) << "N/A" << "| " << setw(11) << setprecision(16) << cubetable[i] << "|  ";
			}
			else {
				cout << setw(9) << setprecision(8) << sqrttable[i] << "| " << setw(11) << setprecision(16) << cubetable[i] << "|  ";
			}
			if (defaulttable[i] < 0) {
				cout << setw(9) << setprecision(7) << "N/A" << "|  " << setw(9) << evenoddtable[i] << "|  " << setw(9) << primetable[i] << endl;
			}
			else {
				cout << setw(9) << setprecision(7) << cuberttable[i] << "|  " << setw(9) << evenoddtable[i] << "|  " << setw(9) << primetable[i] << endl;
			}
	}

	}
	system("pause");
    return 0;
}

