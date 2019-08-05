// Zach_Hunter_HW8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

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
	while (true) {
		string wordarray[100] = { "" };  //initiating all variables
		int wordcountarray[100] = { 0 };
		double wordfreqarray[100] = { 0 };
		string longestword = "";
		string shortestword = "abcdefghijklmnopqrstuvwxyz";
		int bonusarray[31] = { 0 };
		double totalcount = 0;
		int numlines = 0;
		string linetest;
		ifstream selectwords;
		selectwords.open("SelectWords.txt");
		while (getline(selectwords, linetest)) {  //checks number of lines in the text file. Not needed but thought it'd scale well
			numlines++;
			if (linetest == "") {
				numlines--;
			}
		}
		selectwords.clear();				//
		selectwords.seekg(selectwords.beg); // clears end of file flag and returns to beginning

		for (int i = 0; i < numlines; i++) { //inputs into array
			selectwords >> wordarray[i];
		}
		char choice;
		string textread = "";
		while (textread == "") {  //loop to choose file or exit
			cout << "Enter the associated letter for the file you would like to open:" << endl << "A: Swift's \"A Modest Proposal\"" << endl << "B: Plato's \"Apology\"" << endl << "C: Baum's \"The Wonderful Wizard of Oz\"" << endl << "D: Twain's \"Adventures of Tome Sawyer\"" << endl << "E: Exit" << endl;
			cin >> choice;
			switch (choice) {
			case 'A':
				textread = "ModestProposal.txt";
				break;
			case 'a':
				textread = "ModestProposal.txt";
				break;
			case 'B':
				textread = "Apology.txt";
				break;
			case 'b':
				textread = "Apology.txt";
				break;
			case 'C':
				textread = "WizardOfOz.txt";
			case 'c':
				textread = "WizardOfOz.txt";
				break;
			case 'D':
				textread = "The Adventures of Tom Sawyer.txt";
				break;
			case 'd':
				textread = "The Adventures of Tom Sawyer.txt";
				break;
			case 'E':
				textread = "Exit";
				break;
			case 'e':
				textread = "Exit";
				break;
			default:
				textread = "";
				cout << "Invalid Entry!" << endl;;
				break;
			}
		}
		if (textread == "Exit") {
			break;
		}
		ifstream processtext;
		processtext.open(textread);
		string words;
		char inspectchar;
		int stringlength = 0;
		while (processtext >> words) {  //starts to input and count each word
			totalcount++;
			stringlength = words.length();
			while (ispunct(words[0])) {  //gets rid of leading punctuation
				stringlength--;
				if (stringlength == 0) {
					break;
				}
				words = words.substr(1, stringlength);
			}

			if (stringlength > 0) {  //gets rid of trailing punctuation
				while (ispunct(words.at(stringlength - 1))) {
					stringlength--;
					if (stringlength == 0) {
						break;
					}
					words = words.substr(0, stringlength);
				}
			}
			if (stringlength > 0) {  //only proceeds if word exists
				words = lowercase(words);  //converts to lowercase
				if (words.length() < shortestword.length()) {  //replaces shortest word if current one is shorter
					shortestword = words;
				}
				if (words.length() > longestword.length()) {  //replaces longest word if current one is longer
					longestword = words;
				}
				for (int i = 0; i < numlines; i++) {  //compares word to the SelectWords and counts it's occurance
					if (words == wordarray[i]) {
						wordcountarray[i]++;
					}
				}
				bonusarray[stringlength]++;  //bonus array counter
			}
			for (int i = 0; i < numlines; i++) {  //calculates the frequency of the SelectWords
				wordfreqarray[i] = wordcountarray[i] / totalcount;
			}

		} //display loops start
		cout << "File read: " << textread << endl << "Shortest Word: " << shortestword << endl << "Longest Word: " << longestword << endl << "Total Word Count: " << totalcount << endl;
		cout << "|" << setw(14) << "Selected Words" << "|" << setw(10) << "Occurances" << "|" << setw(9) << "Frequency" << "|" << endl;
		for (int i = 0; i < 37; i++) {
			cout << "-";
		}
		cout << endl;
		for (int i = 0; i < numlines; i++) {
			cout << "|" << setw(14) << wordarray[i] << "|" << setw(10) << wordcountarray[i] << "|" << setw(9) << setprecision(4) << wordfreqarray[i] << "|" << endl;
		}
		for (int i = 1; i <= 30; i++) {
			cout << bonusarray[i] << " words of length " << i << endl;
		}
	}

	
	system("pause");
    return 0;
}

