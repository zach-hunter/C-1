// Zach_Hunter_HW3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


int main()
{

	cout << fixed << setprecision(2);

	ifstream itemfile;
	string itemname;
	double itemprice = 0.0;
	char taxable;
	double subtotal = 0.0;
	double total = 0.0;
	double taxtotal = 0.0;
	double taxprice = 0.0;


		itemfile.open("HW3_Data.txt");
		cout << "Thank you for shopping at StuffMart" << endl;
		cout << left << setw(21) << "Item" << setw(10) << "Unit Price" << left << setw(4) << " Tax" << endl << "-----------------------------------" << endl;
		if (itemfile.is_open()) {


			while (!itemfile.eof()) {


				getline(itemfile, itemname);
				itemfile >> itemprice >> taxable;
				subtotal += itemprice;
				if (taxable == 'Y') {
					taxprice = itemprice*0.085;
				}
				else {
					taxprice = 0.0;
				}
				taxtotal += taxprice;
				cout << left << setw(21) << itemname << "$" << right << setw(9) << itemprice << right << setw(3) << taxable << endl;
				getline(itemfile, itemname); //I have no idea why this second getline is needed for the loop to not error and continuously run

			}

			itemfile.close();
		}
		else {
			cout << "File did not open" << endl;
		}




	
	
	total = subtotal + taxtotal;
	cout << right << setw(35) << "--------------" << endl;
	cout << right << setw(18) << "Subtotal" << setw(4) << "$" << right << setw(9) << subtotal << endl;
	cout << right << setw(18) << "Tax (8.5%)" << setw(4) << "$" << right << setw(9) << taxtotal << endl;
	cout << right << setw(18) << "Total" << setw(4) << "$" << right << setw(9) << total << endl;




	system("pause");
	return 0;
}

