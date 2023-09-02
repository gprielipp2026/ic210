// practice problem: see if a character is a letter
#include <iostream>
using namespace std;

int main()
{
  // vars
  char c;

  // input
  cout << "Enter a char: ";
  cin >> c;

  //report
  if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
    cout << "letter" << endl;
  else 
    cout << "not letter" << endl;

  return 0;
}
