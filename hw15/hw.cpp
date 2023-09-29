/*
 * Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP
 * factors a number
 */

#include <iostream>
using namespace std;

int firstfactor(int n);

int main()
{
    // Get integer n, n > 1, from user
    int n;
    cout << "Enter an integer larger than 1: ";
    cin >> n;

    // Print out factorization
    cout << "The factorization of " << n << " is ";
    while(n > 1)
    {
        // get & print next prime factor
        int f = firstfactor(n);
        cout << '(' << f << ')';
        n = n / f;
    }
    cout << endl;

    return 0;
}

int firstfactor(int n)
{
  int i;
  for(i = 2; i < n; i++)
  {
      if(n % i == 0) break;
  }
  return (i == n-1 ? 1 : i);
}
