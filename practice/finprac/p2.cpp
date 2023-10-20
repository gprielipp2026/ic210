/* Filename: p2.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * creates infinite series and sees how many steps until it repeats */
#include <iostream>
using namespace std;

int main()
{
  // get a and b
  int a, b;
  cout << "> ";
  cin >> a >> b;

  int start = a;
  int xold, xnew;
  xnew = start;
  xold = a % b;
  int steps = 0;
  do
  {
    xnew = (xold * a) % b;
    xold = xnew;
    steps ++;
  } while(xnew != start);

  cout << "repeat after " << steps << " steps" << endl;

  return 0;
}
