/* p1.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * read the board! */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "p1board.h"
#include "list.h"
using namespace std;

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

  // display the board
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

  display(b);

  char c;
  do {
    usleep(150000);
    c = inputChar();
  } while(c != 'y');

  endCurses();

  // display the start pos and spawn points
  cout << "Player start: " << b.player << endl;

  // if I wanted a better fix, I'd reverse the linked list after I make it
  // spawn points
  Node* spawnpt = b.spawnpts;
  cout << "Spawn spots: "; 
  Pos* pts = new Pos[b.numspawnpts];
  for(int i = 0; i < b.numspawnpts; i++)
  {
    pts[b.numspawnpts - (i+1)] = spawnpt->pos;
    spawnpt = spawnpt->next;
  }
  for(int i = 0; i < b.numspawnpts; i++)
  {
    cout << pts[i];
    if(i < b.numspawnpts - 1)
      cout << " ";
  }

  cout << endl;

  // free memory
  free(b);
  delete[] pts;

  return 0;
}

