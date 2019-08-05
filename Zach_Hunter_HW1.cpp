// ConsoleApplication3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	cout << "What are the prices of your 3 items?" << endl;
	double item1 = 0;
	double item2 = 0;
	double item3 = 0;
	cout << fixed << setprecision(2);
	
	cout << "Item 1: $";
	cin >> item1;
	cout << "Item 2: $";
	cin >> item2;
	cout << "Item 3: $";
	cin >> item3;
	double itemTotal = item1 + item2 + item3;

	cout << "Thank you for shopping at StuffMart" << endl << "Item 1: $" << item1 << endl << "Item 2: $" << item2 << endl << "Item 3: $" << item3 << endl << "Total: $" << itemTotal << endl;

	system("pause");

	return 0;
}

