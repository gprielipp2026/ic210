/* part4.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * Going further, Carpet */
#include <iostream>
using namespace std;

string carpet(string str, int width, int row);
string repeat(string str, int num);

int main()
{
  // get the size
  int size;
  cout << "size: ";
  cin >> size;
  cout << "Width-" << size << " Sierpinski carpet:" << endl;

  // go row by row
  int rows = size;
  for(int row = 0; row < rows; row++)
  {
    cout << carpet("\u2666", size, row) << endl;
  }
  

  return 0;
}

string repeat(string str, int num)
{
  if(num == 1)
    return str;
  return str + repeat(str, num-1);
}

string carpet(string str, int width, int row)
{
  if(width == 1)
  {
    return str;
  }
  if(row % width >= width/3 && row % width < 2*width/3)
  {
    // it's the middle cell
    string side = carpet(str, width/3, row % (width/3));
    return side + repeat(" ", width/3) + side;
  }
  else
  {
    string side = carpet(str, width/3, row % (width/3));
    return repeat(side, 3);
  }
}
