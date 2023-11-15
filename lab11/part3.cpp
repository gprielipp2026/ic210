/* part3.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * The full Cantor Set */

#include <iostream>
#include <string>
using namespace std;

string repeat(string s, int count);
string cantor(string ch, int width, int level);
int log3(int x);
int pow(int base, int exp);

int main() {
  // get the size
  int size;
  cout << "size: ";
  cin >> size;
  
  for(int l = 0; l < log3(size); l++)
  {
    cout << l << ": " << cantor("X", size, l) << endl;
  }

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

string cantor(string ch, int width, int level)
{
  if(level == 0)
  {
    return repeat(ch, width);
  }

  string side = cantor(ch, width/3, level-1);
  side = repeat(side, (width/3)/side.length());
  return side + repeat("_", width/3) + side;
}

int log3(int x)
{
  if(x == 1)
    return 1;
  return 1 + log3(x/3);
}

int pow(int base, int exp)
{
  if(exp <= 0) // custom hack to pow
    return 1;
  return base * pow(base, exp-1);
}
