/*
Filename: hw.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Finds the adults and children from an age in a file
*/

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // get the filename and open the file
  string fn;
  cout << "Filename: ";
  cin >> fn;

  ifstream names(fn);

  // make sure file is open
  if (!names)
  {
    cout << "File not found!" << endl;
    return 1;
  }

  // read the data
  string name;
  char slash;
  int month, day, year;
  int adults = 0, kids = 0;

  while((names >> name >> month >> slash >> day >> slash >> year))
  {
    if(((year <= 19) && (year >= 1)) || ((year == 0) && (((month == 9) && (day > 27)) || (month > 9))))
    {
      kids++;
    } else
    {
      adults++;
    }
  }

  // report
  cout << adults << " adults and " << kids << " children" << endl;

  return 0;
}
