/*
Filename: lec11.cpp
Name: MIDN GEORGE PRIELIPP (265112)

Integration of f(x) by simple end-point approximation - 
Simple end-point integration approximates the area under 
a curve between x = 1 and x = b by the sum of n evenly 
spaced rectangles whose hieghts are the function values 
at x-values given by the left endpoints of the bases.

*/

#include <iostream>
using namespace std;

double f(double x)
{
  return x;
}

int main()
{
  double integrated = 0;
  double b;
  int n;

  // get upper bound (has to be greater than 1)
  do {
    cout << "Max x value: ";
    cin >> b;
  } while (b <= 1); 

  // get number of subdivisions
  do {
    cout << "# subdivisions: ";
    cin >> n;
  } while (n <= 0);

  // "integrate"
  double width = (b - 1.0) / n;
  for(double x = 1.0; x < b; x += width)
  {
    integrated += f(x) * width;
  }

  cout << "Integral of f(x) from 1 to " << b << " is " << integrated << endl;

  return 0;
}
