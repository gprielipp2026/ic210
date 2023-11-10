#include "board.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "easycurses.h"
#include "Pos.h"
#include "list.h"

/* FUNCTIONS */
istream& operator>>(istream& in, Board& b)
{
  // read the rows x cols # enemies
  char junk;
  in >> b.ROWS >> junk >> b.COLS >> b.numenemies;
  b.enemies = new Node;
  b.enemies->pos = {-1,-1};
  b.enemies->next = nullptr;
  b.playerdir = NORTH;
  b.isStopped = true;

  // read away the empty space
  while(in.peek() != '#')
    in.get();

  // read in the board
  b.board = new char*[b.ROWS];
  b.numenemies = 0;
  for(int row = 0; row < b.ROWS; row++)
  {
    b.board[row] = new char[b.COLS];
    for(int col = 0; col < b.COLS; col++)
    {
      char item = in.get();
      b.board[row][col] = ' ';
      if(item == 'X')
      {
        b.goal = {row,col};
      }
      else if(item == 'Y')
      {
        b.player = {row, col}; 
        cout << "Player Start: " << b.player << endl;
      }
      else if(item == 'Z')
      {
        b.numenemies++;
        b.enemies = add2front(Pos{row,col}, b.enemies);
      }
      else
      {
        b.board[row][col] = item;
      }
    }
    // read the newline
    in.get();
  }

  // also print out the spawn spots of the enemies
  Node* enemy = b.enemies;
  cout << "Spawn Spots: ";
  for(int i = 0; i < b.numenemies; i++)
  {
    cout << enemy->pos;
    if(i < b.numenemies-1)
      cout << " ";
    enemy = enemy->next;
  }  
  cout << endl;

  return in;
}

void display(Board b)
{
  // draw base board
  for(int row = 0; row < b.ROWS; row++)
  {
    for(int col = 0; col < b.COLS; col++)
    {
      drawChar(b.board[row][col], row, col);
    }
  }

  // draw goal
  drawChar('X', b.goal.row, b.goal.col);

  // draw player
  drawChar('P', b.player.row, b.player.col);

  drawChar(b.playerdir + '0', b.ROWS, 1);

  // draw the enemies
  /*Node* enemy = b.enemies;
  for(int i = 0; i < b.numenemies; i++)
  {
    drawChar('Z', enemy->pos.row, enemy->pos.col);
    enemy = enemy->next;
  } 
  */
  // update the window
  refreshWindow();
}

void free(Board b)
{
  // free the board
  for(int row = 0; row < b.ROWS; row++)
  {
    delete[] b.board[row];
  }
  delete[] b.board;

  // free the enemies
  free(b.enemies);
}

int dir(Board& b, int keycode)
{
  switch(keycode)
  {
    //case KEY_UP:
    case 'w':
      return NORTH;
    //case KEY_RIGHT:
    case 'd':
      return EAST;
    //case KEY_DOWN:
    case 's':
      return SOUTH;
    //case KEY_LEFT:
    case 'a':
      return WEST;
    case 'r':
      b.isStopped = !b.isStopped;
      return b.playerdir;
      break;
    default:
      {
        if(b.isStopped) return -1;
        else return b.playerdir;
      }
  }
}

bool move(Board& b)
{
  // take test step
  Pos test = step(b.player, b.playerdir);
  
  // handle collisions
  b.player = collision(b, test);

  // see if they won
  if(dist(b.player, b.goal) == 1)
    return true;

  return false;
}

Pos collision(Board& b, Pos test)
{
  // check for walls
  if(b.board[test.row][test.col] == '#')
  {
    test = step(test, turn(b.playerdir, 180));
    if(b.board[test.row][test.col] == '#')
    {
      // stay in the same orientation and place
      return b.player;
    }
    else
    {
      b.playerdir = turn(b.playerdir, 180);
      return test;
    }
  }
  // no collision
  else
  {
    return test;
  }
}
