/*
 * Filename: p3.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Read in a chmod triple and output the flags and their status
 *
 * */

#include <iostream>

using namespace std;

int main()
{
	// variables
	int user, group, other;
	char u  ,   g  ,   o  ;

	// get input
	cout << "Permissions: ";
	cin >> u >> g >> o;
	cout << endl;

	// break input into user, group, other
	user = u - '0';
	group = g - '0';
	other = o - '0';

	// report user flags
	cout << "User:\n";
	cout << "read\t" << (int)(user % 8 > 3) << endl;
	cout << "write\t" << (int)(user % 4 > 1) << endl;
	cout << "execute\t" << (int)(user % 2 > 0) << endl;

	// report group flags
	cout << "Group:\n";
	cout << "read\t" << (int)(group % 8 > 3) << endl;
	cout << "write\t" << (int)(group % 4 > 1) << endl;
	cout << "execute\t" << (int)(group % 2 > 0) << endl;
	

	// report other flags
	cout << "Other:\n";
	cout << "read\t" << (int)(other % 8 > 3) << endl;
	cout << "write\t" << (int)(other % 4 > 1) << endl;
	cout << "execute\t" << (int)(other % 2 > 0) << endl;


	return 0;
}
