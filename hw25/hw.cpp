/* Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * writes calcspaces as a recursive function 
*/

#include <iostream>
using namespace std;

int calspace(int num);

int main()
{
  int n;
  cout << "Integer? ";
  cin >> n;

  cout << "#spaces= " << calspace(n) << endl;
  return 0;
}

int calspace(int num)
{
  if (num == 0) return 1;
  
  bool isNeg = false;
  if(num < 0)
  {
    num = -num;
    isNeg = true;
  }

  // make sure I don't count 0 as a number
  // otherwise I end up 1 over the actual count (so I stop before)  
  if (num/10 == 0 && num != 0) return 1 + int(isNeg);
  
  // +1 to account for the last digit. 
  // For example, calspace(2) should return 1
  return (isNeg ? 1 : 0) + 1 + calspace(num/10);
}
