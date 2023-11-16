/* part5.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * Extra Credit: The Famous Triangle */
#include <iostream>
using namespace std;

string triangle(int width, int height, int row);
int spaceoutside(int height, int row);
int spaceinside(int width, int strlen, int row);
string repeat(string s, int n);

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
    cout << triangle(width, height, row) << endl;
  }

  return 0;
}

string triangle(int width, int height, int row)
{
  if(height == 1 && row == 0)
    return "▲";
  else if (width == (2*height-1))
  {
    string blocks = triangle(width, height/2, row % (height/2));
    string spaceLR = repeat(" ", spaceoutside(height, row));
    //int blocksize = height - row;
    string spaceMid = repeat(".", spaceinside(width, blocks.length(), row));
    if(spaceMid.size() > 0)
      return spaceLR + blocks + spaceMid + blocks;
    else
      return spaceLR + blocks;
  }
  else
  {
    string blocks = triangle(width, height/2, row % (height/2));
    //int blocksize = height - row;
    string spaceMid = repeat(".", spaceinside(width, blocks.length(), row));
    if(spaceMid.size() > 0) 
      return blocks + spaceMid + blocks;
    else
      return blocks;
  }
}

int spaceoutside(int height, int row)
{
  return (height - 0.5) - row;
}

int spaceinside(int width, int strlen, int row)
{
  int height = (width+1)/2;
  return width - 2*(spaceoutside(height, row) + strlen);
}

string repeat(string s, int n)
{
  if(n <= 0)
    return "";
  else if(n == 1)
    return s;
  else
    return s + repeat(s, n-1);
}
