/* Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * recursively define pow
 */
#include <iostream>
using namespace std;

double pow(double, int);

int main()
{
    double x;
    int n;
    cout << "Enter x and n: ";
    cin >> x >> n;
    cout << "x^n is " << pow(x,n) << endl;
    return 0;
}

// Define pow: it must be recursive!
double pow(double base, int exp)
{
  if(exp == 0)
    return 1;
  if(exp < 0)
    return 1/pow(base,-exp);

  return base * pow(base, exp-1);
}
