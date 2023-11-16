/* part5.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * Extra Credit: The Famous Triangle */
#include <iostream>
using namespace std;

string triangle(int width, int height, int row);
int spaceoutside(int height, int row);
int spaceinside(int width, int strlen, int row);
string repeat(string s, int n);
int length(string s);

int main()
{
  // get the height
  cout << "size: ";
  int height, width;
  cin >> height;
  width = 2*height - 1;
  cout << "Height-" << height << " Sierpinski triangle:" << endl;

  //string t = "\u25b2";
  //cout << "t.length() = " << t.length() << endl;
  //cout << "length(" << t << ") = " << length(t) << endl;
  //cout << length("\u25b2.\u25b2") << endl;

  // do the triangle row by row
  for(int row = 0; row < height; row++)
  {
    string spaceL = repeat(" ", spaceoutside(height, row));
    cout << spaceL << triangle(width, height, row) << endl;
  }

  return 0;
}

string triangle(int width, int height, int row)
{
  if(height == 1 && row == 0)
    return "\u25b2";
  else
  {
    string block = triangle(width, height/2, row % (height/2));
    int numblocks = length(block);
    string mid = repeat(".", spaceinside(width, numblocks, row) );
    if(mid.size() > 0)
      return block + mid + block;
    else
      return block;
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

int length(string s)
{
  int size = 0;
  
  // got this online (how to count unicode characters in a string)
  const char* p = s.c_str();
  while(*(p++) != 0)
    size += ((*p & 0xc0) != 0x80);


  return size;
}
