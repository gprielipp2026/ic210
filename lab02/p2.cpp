/*
 * Filename: p2.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Convert a decimal number between 0 and 15 into binary
 * */

#include <iostream>
using namespace std;

int main() 
{
	// variables
	string binary;
	int decimal, copy;

	// get input
	cout << "Enter a number between 0 and 15: ";
	cin >> decimal;
	copy = decimal;

	// convert to binary
	binary += '0' + decimal%2; // extract bit by bit
	decimal /= 2;

	binary += '0' + decimal%2;
	decimal /= 2;

	binary += '0' + decimal%2;
	decimal /= 2;

	binary += '0' + decimal%2;
	decimal /= 2;// full binary number available now, but it's in reverse order (LSB is first)
	
	// report binary number
	cout << copy << " in binary is " << binary[3] << binary[2] << binary[1] << binary[0] << endl;

	return 0;
}
