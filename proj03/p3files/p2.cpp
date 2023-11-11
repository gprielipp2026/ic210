/* p2.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * implement the player! */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "board.h"
#include "list.h"
using namespace std;

void win(int iters);

int main()
{
  // get the filename
  string fn;
  cout << "board file: ";
  cin >> fn;

  // open the file
  ifstream file(fn);
  if(!file)
  {
    cerr << "Could not open \'" << fn << "\'" << endl;
    exit(1);
  }

  // create the board
  Board b;
  file >> b;
  file.close();

  startCurses();
 
  // make sure the window is big enough
  int rows,cols;
  getWindowDimensions(rows, cols);
  if(b.ROWS > rows || b.COLS > cols)
  {
    cerr << "The terminal is not big enough for the board!" << endl;
    endCurses();
    free(b);
    exit(1);
  }

  // the game loop
  char kc;
  int iters = 0;
  while ((kc = inputChar()) != 'y' && !b.isWin)
  {
    b.playerdir = dir(b, kc);

    // if I'm not stopped, move
    if(!b.isStopped)
      move(b);

    // display the board
    display(b);
    
    usleep(150000);
    iters++;
  }

  endCurses();

  if (b.isWin)
    win(iters);

  // free memory
  free(b);

  return 0;
}

void win(int iters)
{
  cout << "You won, high score = " << (500-iters) << endl;
}
