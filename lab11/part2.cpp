/* part2.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * Cantor Set */

#include <iostream>
#include <string>
using namespace std;

string repeat(string s, int count);
string cantor(string ch, int size);

int main() {
  // get the size
  int size;
  cout << "size: ";
  cin >> size;

  cout << cantor("X", size) << endl;

  return 0;
}

string repeat(string s, int count)
{
  if(count == 1)
  {
    return s;
  }
  return s + repeat(s, count-1);
}

string cantor(string ch, int size)
{
  if(size == 1)
  {
    return ch;
  }
  string middle = repeat("_", size/3);
  string side = cantor(ch, size/3);
  return side + middle + side;
}
