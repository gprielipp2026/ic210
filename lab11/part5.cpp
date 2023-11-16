/* part5.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * Extra Credit: The Famous Triangle */
#include <iostream>
using namespace std;

string triangle(int width, int rowid);

int main()
{
  // get the height
  cout << "size: ";
  int height, width;
  cin >> height;
  width = 2*height - 1;
  cout << "Height-" << height << " Sierpinski triangle:" << endl;

  // do the triangle row by row
  for(int row = 0; row < height; row++)
  {
    cout << triangle(width, row) << endl;
  }

  return 0;
}

string triangle(int width, int rowid)
{
  return "\u25b2";
}
