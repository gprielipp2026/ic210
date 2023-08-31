/*
Name: MIDN George Prielipp (265112)
File: hw.cpp
Proj: hw04
*/
#include <iostream>

using namespace std;

int main()
{
  // varialbes
  char c1,c2,c3;

  // prompt user and get input
  cout << "Input a 3-letter word in uppercase letters: ";
  cin >> c1 >> c2 >> c3;

  // convert the chars
  c1 = (c1 - 'A') + 'a';
  c2 = (c2 - 'A') + 'a';
  c3 = (c3 - 'A') + 'a';

  // report
  cout << "Output: " << c1 << c2 << c3 << endl;

  return 0;
}
