/*
Filename: hw01.cpp
Author:   MIDN George Prielipp (265112)
Homework 01
*/
#include <iostream>
#include <cmath>

int main() 
{
  // sides of the triangle
  double x;
  double y;
  double z;
  
  // get x
  std::cout << "Enter length x: ";
  std::cin >> x;
  
  // get y but it has to be less than x
  std::cout << "Enter length y (<" << x << "): ";
  std::cin >> y;
  
  // get z but is has to be less than sqrt(x^2-y^2)
  double AC = std::sqrt(x*x - y*y);// the bottom of the triangle
  std::cout << "Enter length z (<" << AC << "): ";
  std::cin >> z;

  // calculate DC
  double DC = AC - z;
  
  // calculate BD
  double BD = sqrt(DC*DC + y*y);

  // report the length of BD
  std::cout << "Length of BD is " << BD << std::endl;

  // no errors, exit success
  return 0;
}
