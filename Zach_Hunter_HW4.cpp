// Zach_Hunter_HW4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	double deposit = 0.0;
	double intrate = 0.0;
	double balance = 0.0;
	int months = 0;
	int asternum = 0;
	string asterisk1;
	int monthcount = 1;
	double astercalc = 0.0;


	cout << "Enter a deposit amount between $100 and $10000." << endl << "$";
	cin >> deposit;
	while (deposit < 100 || deposit > 10000 || cin.fail()) {	//loop for validation checking on deposit
		cin.clear();	//nifty trick I found to use cin.fail in validation check to throw out anything that isnt a number
		cin.ignore(1000000, '\n');
		cout << "Please enter a valid deposit between $100 and $10,000." << endl << "$";
		cin >> deposit;
	}

	cout << endl << "Enter the number of months. (Between 12 and 60)" << endl;
	cin >> months;
	while (months < 12 || months > 60 || cin.fail()) { //loop for validation checking on months
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Please enter a valid number of months. (Between 12 and 60)" << endl;
		cin >> months;
	}

	cout << endl << "Enter an interest rate between 2.0 and 8.0 percent." << endl;
	cin >> intrate;
	while (intrate < 2 || intrate > 8 || cin.fail()) { //loop for validation checking on interest rate
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Please enter a valid interest rate between 2.0 and 8.0 percent." << endl;
		cin >> intrate;
	}
	
	ofstream savingsfile;	//beginning common outputs
	savingsfile.open("savings.txt");
	cout << "Thank you for banking at TheBigVault" << endl;		//line 1
	savingsfile << "Thank you for banking at TheBigVault" << endl;
	cout << left << setw(21) << "Deposit" << "$" << right << setw(13) << fixed << setprecision(2) << deposit << endl;	//line 2
	savingsfile << left << setw(21) << "Deposit" << "$" << right << setw(13) << fixed << setprecision(2) << deposit << endl;
	cout << left << setw(21) << "Interest Rate" << " " << right << setw(13) << intrate << "%" << endl;		//line 3
	savingsfile << left << setw(21) << "Interest Rate" << " " << right << setw(13) << intrate << "%" << endl;
	cout << left << setw(21) << "Month" << " " << right << setw(13) << "Balance" << endl;	//line 4
	savingsfile << left << setw(21) << "Month" << " " << right << setw(13) << "Balance" << endl;
	cout << "------------------------------------" << endl;		//line 5
	savingsfile << "------------------------------------" << endl; 
	intrate = intrate / 100;	//convert intrate to usable number after it has been displayed

	for (monthcount = 1, asterisk1 = ""; monthcount <= 12 ; monthcount++) {		//loop for console display, limited to 12 months
		astercalc = deposit * 0.1;
		balance = deposit*pow((1.0 + (intrate / 12)), monthcount);	//balance formula
		asternum = balance / astercalc;		//bonus 1, calculates how many asterisks are needed
		for (int astercount = asternum; astercount > 0; astercount--) {		//adds asterisks to string depending on how many it needs
			asterisk1 = asterisk1 + "*";
		}
		cout << left << setw(21) << monthcount << "$" << right << setw(13) << balance << " " << asterisk1 << endl; 
		asterisk1 = "";
	}
	cout << endl << "Full readout available in savings.txt" << endl << "5 year (60 month) projection available in balance.txt" << endl;
	for (monthcount = 1, asterisk1 = ""; monthcount <= months; monthcount++) {	//loop for file display equal to number of months
		astercalc = deposit * 0.1;
		balance = deposit*pow((1.0 + (intrate / 12)), monthcount);
		asternum = balance / astercalc;
		for (int astercount = asternum; astercount > 0; astercount--) {
			asterisk1 = asterisk1 + "*";
		}
		savingsfile << left << setw(21) << monthcount << "$" << right << setw(13) << balance << " " << asterisk1 << endl;
		asterisk1 = "";
	}
	savingsfile.close();

	ofstream balancefile;	//bonus 2, outputs all 60 months of data
	balancefile.open("balance.txt");
	balancefile << "5 Year (60 Month) Balance Projection" << endl << left << setw(17) << "Month" << right << setw(18) << "Balance" << endl << "-----------------------------------" << endl;
	for (monthcount = 1, asterisk1 = ""; monthcount <= 60; monthcount++) {	//loop for file display, always continues for 60 months
		astercalc = deposit * 0.1;
		balance = deposit*pow((1.0 + (intrate / 12)), monthcount);
		asternum = balance / astercalc;
		for (int astercount = asternum; astercount > 0; astercount--) {
			asterisk1 = asterisk1 + "*";
		}
		balancefile << left << setw(21) << monthcount << "$" << right << setw(13) << fixed << setprecision(2) << balance << " " << asterisk1 << endl;
		asterisk1 = "";
	}
	balancefile.close();


	system("pause");
	return 0;
}

