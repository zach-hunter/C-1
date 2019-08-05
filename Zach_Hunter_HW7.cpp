// Zach_Hunter_HW7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;

string longroman(int number) { //longform roman numeral conversion
	string roman = "";
	int numpart;
	if (number >= 1000) {  //thousandths place
		numpart = (number / 1000);
		for (int i = 0; i < numpart; i++) {
			roman += 'M';
		}
		number %= 1000;
	}
	if (number >= 100) { //hundredths place
		numpart = (number / 100);
		if (numpart >= 5) {
			roman += 'D';
			for (int i = 0; i < numpart - 5; i++) {
				roman += 'C';
			}
		}
		else {
			for (int i = 0; i < numpart; i++) {
				roman += 'C';
			}
		}
		number %= 100;
	}
	if (number >= 10) { //tenths place
		numpart = (number / 10);
		if (numpart >= 5) {
			roman += 'L';
			for (int i = 0; i < numpart - 5; i++) {
				roman += 'X';
			}
		}
		else {
			for (int i = 0; i < numpart; i++) {
				roman += 'X';
			}
		}
		number %= 10;
	}
	numpart = number; //ones place
	if (numpart >= 5) {
		roman += 'V';
		for (int i = 0; i < numpart - 5; i++) {
			roman += 'I';
		}
	}
	else {
		for (int i = 0; i < numpart; i++) {
			roman += 'I';
		}
	}
	return roman;
}

string shortroman(int number) { //shortform roman numeral conversion
	string roman = "";
	int numpart;
	if (number >= 1000) { //thousandths place
		numpart = (number / 1000);
		for (int i = 0; i < numpart; i++) {
			roman += 'M';
		}
		number %= 1000;
	}
	if (number >= 100) { //hundredths place
		numpart = (number / 100);
		if (numpart == 9) {
			roman += "CM";
		}
		else if (numpart >= 5) {
			roman += 'D';
			for (int i = 0; i < numpart - 5; i++) {
				roman += 'C';
			}
		}
		else if (numpart == 4) {
			roman += "CD";
		}
		else {
			for (int i = 0; i < numpart; i++) {
				roman += 'C';
			}
		}
		number %= 100;
	}
	if (number >= 10) { //tenths place
		numpart = (number / 10);
		if (numpart == 9) {
			roman += "XC";
		}
		else if (numpart >= 5) {
			roman += 'L';
			for (int i = 0; i < numpart - 5; i++) {
				roman += 'X';
			}
		}
		else if (numpart == 4) {
			roman += "XL";
		}
		else {
			for (int i = 0; i < numpart; i++) {
				roman += 'X';
			}
		}
		number %= 10;
	}
	numpart = number; //ones place
	if (numpart == 9) {
		roman += "IX";
	}
	else if (numpart >= 5) {
		roman += 'V';
		for (int i = 0; i < numpart - 5; i++) {
			roman += 'I';
		}
	}
	else if (numpart == 4) {
		roman += "IV";
	}
	else {
		for (int i = 0; i < numpart; i++) {
			roman += 'I';
		}
	}
	return roman;
}

string lowercase(string convert) { //converts to lowercase, anything not originally an uppercase character remains the same
	string lowerstring = "";
	int stringlength = convert.length();
	for (int i = 0; i < stringlength; i++) {
		switch (convert[i]) {
		case 'A':
			lowerstring += "a";
			break;
		case 'B':
			lowerstring += "b";
			break;
		case 'C':
			lowerstring += "c";
			break;
		case 'D':
			lowerstring += "d";
			break;
		case 'E':
			lowerstring += "e";
			break;
		case 'F':
			lowerstring += "f";
			break;
		case 'G':
			lowerstring += "g";
			break;
		case 'H':
			lowerstring += "h";
			break;
		case 'I':
			lowerstring += "i";
			break;
		case 'J':
			lowerstring += "j";
			break;
		case 'K':
			lowerstring += "k";
			break;
		case 'L':
			lowerstring += "l";
			break;
		case 'M':
			lowerstring += "m";
			break;
		case 'N':
			lowerstring += "n";
			break;
		case 'O':
			lowerstring += "o";
			break;
		case 'P':
			lowerstring += "p";
			break;
		case 'Q':
			lowerstring += "q";
			break;
		case 'R':
			lowerstring += "r";
			break;
		case 'S':
			lowerstring += "s";
			break;
		case 'T':
			lowerstring += "t";
			break;
		case 'U':
			lowerstring += "u";
			break;
		case 'V':
			lowerstring += "v";
			break;
		case 'W':
			lowerstring += "w";
			break;
		case 'X':
			lowerstring += "x";
			break;
		case 'Y':
			lowerstring += "y";
			break;
		case 'Z':
			lowerstring += "z";
			break;
		default: //leaves anything not an uppercase character unmodified 
			lowerstring += convert[i];
		}
	}
	return lowerstring;
}

int main()
{
	int startnum;
	while (true) {
		cout << "Enter a whole number between 1 and 5000 to convert to a Roman Numeral (0 to exit): ";
		cin >> startnum;

		while (startnum < 0 || startnum > 5000 || cin.fail()) { //input validation check
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Please enter a valid whole number between 1 and 5000 (0 to exit): " << endl;
			cin >> startnum;
		}
		if (startnum == 0) { //break for exit
			break;
		}
		int decimalvalue[250];
		string longform[250][2];
		string shortform[250][2];
		for (int i = 0; i < 250; i++) { //building each array, size=250 for bonus
			decimalvalue[i] = startnum;
			longform[i][0] = longroman(startnum);
			longform[i][1] = lowercase(longform[i][0]);
			shortform[i][0] = shortroman(startnum);
			shortform[i][1] = lowercase(shortform[i][0]);
			startnum++;
		}
		ofstream romantable;
		romantable.open("roman.txt");
		cout << "|" << setw(6) << "Number" << "|" << setw(43) << "Long Form Roman Numerals         " << "|" << setw(29) << "Short Form Roman Numerals  " << "|" << endl;
		for (int i = 0; i < 82; i++) {
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < 250; i++) { //loop for display
			if (i < 20) {
				cout << "|" << setw(6) << decimalvalue[i] << "|" << setw(21) << longform[i][0] << "|" << setw(21) << longform[i][1] << "|" << setw(14) << shortform[i][0] << "|" << setw(14) << shortform[i][1] << "|" << endl;
				}
			romantable << "|" << setw(6) << decimalvalue[i] << "|" << setw(21) << longform[i][0] << "|" << setw(21) << longform[i][1] << "|" << setw(14) << shortform[i][0] << "|" << setw(14) << shortform[i][1] << "|" << endl;
		}
		romantable.close();
	}
	
    return 0;
}

