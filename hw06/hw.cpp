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

  // get input
  cout << "Values for a and b? ";
  cin >> a >> junk >> b;
  
  cout << "What do you want? ";
  cin >> cmd; 
  
  // process the command and execute
  if (cmd == "add")
  {
    cin >> num >> junk >> var;
    if (var == "a") a += num;
    else b += num;
  } 
  else if (cmd == "square")
  {
    cin >> var;
    if (var == "a") a *= a;
    else b *= b;
  }

  // report a and b
  cout << "a = " << a << " and b = " << b << endl;

  return 0;
}

  
