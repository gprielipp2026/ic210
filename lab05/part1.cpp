/*
 * Filename: part1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * plays a simple game
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // get the input file and open it
  string inFN;
  cin >> inFN;
  ifstream board(inFN);

  // make sure its open
  if(!board) {
    cout << "File not found!" << endl;
    return 1;
  }

  // get width of board
  int width;
  string strwid;
  char eq;
  board >> strwid >> eq >> width;

  // get user input
  int col;
  cout << "Enter position between 1 and " << width << ": ";
  cin >> col;
  
  // make sure input is valid
  if(col > width || col < 1)
  {
    cout << "Invalid position!" << endl;
    return 1;
  }


  // start reading from the file
  int diedAt = -1;
  int numRows = 0;
  char curChar;

  while(board >> curChar)
  {
    // skip edge of board
    if(curChar == '@') continue;
    
    // advance curChar to user's guess
    for(int i = 1; i < col; i++)
      board >> curChar;

    // check user's guess
    if (curChar == 'X' && diedAt == -1) diedAt = numRows;

    // advance to end of row
    for(int i = col; i <= width; i++)
      board >> curChar;

    numRows++;
  }

  // did the user survive?
  if (diedAt == -1) 
  {
    cout << "You survived!" << endl;
  } 
  // calculate output for user
  else
  {
    cout << "You died on step " << (diedAt+1) << endl;
  }

  return 0;
}
