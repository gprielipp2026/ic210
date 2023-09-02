/*
Filename: hw.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Takes a command (add or square) and 1-2 numbers comma separated and performs command 
 */

#include <iostream>

using namespace std;

int main()
{
  // variables
  float a, b, num;
  string cmd, junk, var;
  bool useA;

  // get input
  cout << "Values for a and b? ";
  cin >> a >> junk >> b;
  
  cout << "What do you want? ";
  cin >> cmd >> num >> junk >> var;
  
  // determine which variable is being used
  useA = var == "a"; // last index is going to be the variable

  // process the command and execute
  if (cmd == "add")
  {
    if (useA) a += num;
    else b += num;
  } 
  else if (cmd == "square")
  {
    if (useA) a *= a;
    else b *= b;
  }

  // report a and b
  cout << "a = " << a << " and b = " << b << endl;

  return 0;
}

  
