/*
 * Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Prints out a rectangle with a width, height, and offset
 */

#include <iostream>

using namespace std;

int main()
{
  // get height, width, and offset
  int height, width, offset;
  cout << "Enter height (greater than 2): ";
  cin >> height;

  cout << "Enter width  (greater than 2): ";
  cin >> width;

  cout << "Enter offset: ";
  cin >> offset;

  // loop through height
  for(int row = 0; row < height; row++)
  {
      // print the offset
      for(int i = 0; i < offset; i++)
          cout << ' ';

      // loop through the width
      for(int col = 0; col < width; col++)
      {
        if(row == 0 || row == height-1 || col == 0 || col == width-1)
            cout << '*';
        else
            cout << ' ';
      }

      // move to the next line
      cout << endl;
  }

  return 0;
}
