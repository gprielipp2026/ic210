/*
  MIDN George Prielipp (265112)
  filename: hw.cpp
  HW03
 */
#include <iostream>

using namespace std;

int main() {
  // declare variables
  int feet1;
  int inches1;
  int feet2;
  int inches2;
  int difference;
  int dif_feet, dif_inches;
  char inputjunk;

  // prompt the user
  cout << "Enter two lengths in feet and inches (larger first!)" << endl;

  // collect data
  cin >> feet1 >> inputjunk >> inches1 >> inputjunk >> inputjunk;
  cin >> feet2 >> inputjunk >> inches2 >> inputjunk >> inputjunk;

  // calculate difference
  inches1 += feet1 * 12; // convert feet to inches then store the total in inches1
  inches2 += feet2 * 12; // same thing for feet2 -> inches2
  difference = inches1 - inches2;

  // convert back to feet and inches
  dif_feet = difference / 12;
  dif_inches = difference % 12;

  // report the difference
  cout << "Difference is " << dif_feet << "\' " << dif_inches << "\'\'" << endl;

  return 0;
}
