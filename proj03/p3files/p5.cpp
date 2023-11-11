/* p2.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * implement the Hunters! */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <unistd.h>
#include "board.h"
#include "list.h"
using namespace std;

void win(int iters);
int game(int maxscore, string fn, int shipsPerSpawn, int huntersPerSpawn);

int main()
{
  // open the gameScript for reading
  ifstream file("gameScript.txt");
  if (!file)
  {
    cerr << "Failed to open \'gameScript.txt\'" << endl;
    exit(1);
  }

  // get the data to play and store the score
  string fn, pts, eq;
  int ships, hunters, maxscore, score = 0;

  while (file >> fn >> ships >> hunters >> pts >> eq >> maxscore)
  {
    int g = game(maxscore, fn, ships, hunters);
    if (g == -1)
    {
      break;
    }
    else
    {
      score += g;
    }
  }

  cout << "Total score: " << score << endl;

  return 0;
}

void win(int iters)
{
  cout << "You won, high score = " << (500 - iters) << endl;
}

int game(int maxscore, string fn, int shipsPerSpawn, int huntersPerSpawn)
{
  // get the filename
  // string fn;
  // cout << "board file: ";
  // cin >> fn;

  // open the file
  ifstream file(fn);
  if (!file)
  {
    cerr << "Could not open \'" << fn << "\'" << endl;
    exit(1);
  }

  // create the board
  Board b;
  b.huntersPerSpawn = huntersPerSpawn;
  b.shipsPerSpawn = shipsPerSpawn;
  file >> b;
  file.close();

  startCurses();

  // make sure the window is big enough
  int rows, cols;
  getWindowDimensions(rows, cols);
  if (b.ROWS > rows || b.COLS > cols)
  {
    cerr << "The terminal is not big enough for the board!" << endl;
    endCurses();
    free(b);
    exit(1);
  }

  // the game loop
  char kc;
  int iters = 0;
  b.isWin = false;
  b.collidedEnemy = false;
  while ((kc = inputChar()) != 'y' && !b.isWin && !b.collidedEnemy)
  {
    b.playerdir = dir(b, kc);

    // if I'm not stopped, move
    if (!b.isStopped)
      move(b);

    // move the ships
    moveships(b);

    // move the hunters
    movehunters(b);

    // display the board
    display(b);

    usleep(150000);
    iters++;
  }

  endCurses();

  if (b.isWin && !b.collidedEnemy)
  {
    win(iters);
    return maxscore;
  }
  else
  {
    cout << "You lost, they got you!" << endl;
    return -1;
  }

  // free memory
  free(b);
}