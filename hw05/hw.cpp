/*
Filename: hw.cpp
Name: MIDN George Prielipp (265112)
Determines if a given year is a leapyear
*/

#include <iostream>
using namespace std;

int main()
{
  // variables
  int year;

  // prompt and get user input
  cout << "Enter year: ";
  cin >> year;

  // determine if its a leapyear and report
  if (year % 4 == 0)
  {
    if (year % 400 == 0)
    {
      cout << "Is Leap Year" << endl;
    } 
    // make sure it isn't a weird %100 year
    else if (year % 100 > 0)
    {
      cout << "Is Leap Year" << endl;
    } 
    // it was a weird %100 year
    else
    {
      cout << "Is Not Leap Year" << endl;
    }
  }  

  if (year % 4 > 0)
  {
    cout << "Is Not Leap Year" << endl;
  }

  return 0;
}
