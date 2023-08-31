/*
 * Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Binary to decimal conversion
 * */

#include <iostream>
using namespace std;

int main()
{
	// variables
	string binInput;
	int decimal = 0; // only every positive

	// get input in binary
	cout << "Enter a 4-bit binary number: ";
	cin >> binInput;

	// process (convert binary to decimal)
	decimal += (binInput[3] == '1') * 1;
	decimal += (binInput[2] == '1') * 2;
	decimal += (binInput[1] == '1') * 4;
	decimal += (binInput[0] == '1') * 8;
	
	// report decimal number
	cout << "In decimal " << binInput << " = " << decimal << endl;

	return 0;
}
