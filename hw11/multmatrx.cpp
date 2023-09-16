/*
  Filename: multmatrx.cpp
  Name: MIDN GEORGE PRIELPP (265112)
  Take in a number < 30 and output the multiplication matrix 
*/

#include <iostream>
using namespace std;

int main()
{
  // get N from the user
  int N;
  do {
      cout << "Please enter the table size: ";
      cin >> N;
  } while (N > 30 || N < 0);

  // loop through the rows
  for(int row = 1; row <= N; row++)
  {
      // loop throught the cols
      for(int col = 1; col <= N; col++)
      {
          // value at this location
          int val = row * col;

          // padding in the matrix
          if(val < 10) cout << ' ';
          if(val < 100) cout << ' ';
          
          cout << val << ' ';
      }
      cout << endl;
  }

  return 0;  
}
