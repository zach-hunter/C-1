// Zach_Hunter_HW5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "math.h"
#include <iomanip>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void primedisplay(int primepos, int actualprime) { //prints the prime number and it's position
	if (primepos <= 20) {
		cout << "Prime #" << primepos << " = " << actualprime << endl;
	}
	ofstream primesfile;
	primesfile.open("primes.txt", std::fstream::app);
	primesfile << "Prime #" << primepos << " = " << actualprime << endl;
	primesfile.close();
	
	return;
}

char isitprime(int num) { //tests if a number is prime
	int counter = 2;
	double answer = 100;
	if (num%2 == 0 && num != 2) {
		return 'F';
	}
	else {
		while (counter < answer) {
			answer = num / counter;
			if (num % counter == 0) {
				return 'F';
				break;
				}
			counter++;
		}
		
		return 'T';
	}
	
}


int main()
{
	int primeswanted = 0;

	cout << "How many primes do you want?(Between 30 and 2000): ";
	cin >> primeswanted;
	while (primeswanted < 30 || primeswanted > 2000 || cin.fail()) {
		cin.clear();
		cin.ignore(1000000, '\n');
		cout << "Invalid input." << endl << "How many primes do you want?(Between 30 and 2000): ";
		cin >> primeswanted;
	}
	ofstream primesfile;
	primesfile.open("primes.txt");
	int currentnum = 1;
	int counter = primeswanted;

	while (counter != 0) {	//loop to keep generating primes until primeswanted is reached
		currentnum ++;
		char primeanswer = isitprime(currentnum);
		if (primeanswer != 'F') { //will display prime numbers
			counter--;
			primedisplay(primeswanted - counter, currentnum);
			
			
		}
		
	}
	

	system("pause");
    return 0;
}

