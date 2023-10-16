/* Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Takes in a 2d array and figures out what sums of rows/cols are multiples of 3
 */
#include <iostream>
using namespace std;

string int2string(int n);

int main()
{
  // get the size
  int rows, cols;
  char x;
  cout << "What size? ";
  cin >> rows >> x >> cols;

  // keep track of the columns
  int* colsums = new int[cols];
  for(int col = 0; col < cols; col++)
    colsums[col] = 0;

  // loop through rows and cols
  int rowsum;
  int num;
  string rowstr = "";
  for(int row = 0; row < rows; row++)
  {
    rowsum = 0;
    for(int col = 0; col < cols; col++)
    {
      cin >> num;
      rowsum += num;
      colsums[col] += num;
    }
    if(rowsum % 3 == 0)
      rowstr += int2string(row) + " ";
  }
  cout << "rows: " << rowstr << endl;

  // go through the cols
  cout << "cols: ";
  for(int col = 0; col < cols; col++)
  {
    if(colsums[col] % 3 == 0)
      cout << col << " ";
  }
  cout << endl;

  return 0;
}

string int2string(int n)
{
  if (n == 0) return "0";
  
  string out = "";

  while(n>0)
  {
    char c = n%10 + '0';
    out = c + out;
    n/=10;
  }

  return out;
}
