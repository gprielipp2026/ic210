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
  // read the rows x cols # spawnpts
  char junk;
  in >> b.ROWS >> junk >> b.COLS >> b.numspawnpts;
  b.spawnpts = new Node;
  b.spawnpts->pos = {-1, -1};
  b.spawnpts->next = nullptr;
  b.playerdir = NORTH;
  b.isStopped = true;

  // read away the empty space
  while(in.peek() != '#')
    in.get();

  // read in the board
  b.board = new char*[b.ROWS];
  b.numspawnpts = 0;
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
        b.numspawnpts++;
        b.spawnpts = add2front(Pos{row, col}, b.spawnpts);
      }
      else
      {
        b.board[row][col] = item;
      }
    }
    // read the newline
    in.get();
  }

  // also print out the spawn spots of the spawnpts
  // AND set the space ships
  // AND set the Hunters
  b.numships = b.numspawnpts * b.shipsPerSpawn;
  b.ships = new Enemy[b.numships];

  b.numhunters = b.numspawnpts * b.huntersPerSpawn;
  b.hunters = new Enemy[b.numhunters];

  Node *spawnpt = b.spawnpts;
  cout << "Spawn Spots: ";
  for (int i = 0; i < b.numspawnpts; i++)
  {
    cout << spawnpt->pos;
    if (i < b.numspawnpts - 1)
      cout << " ";

    // create the ships
    for (int j = 0; j < b.shipsPerSpawn; j++)
    {
      b.ships[i * b.shipsPerSpawn + j] = Enemy{spawnpt->pos, rand() % 4};
    }

    // create the hunter
    for (int j = 0; j < b.huntersPerSpawn; j++)
    {
      b.hunters[i * b.huntersPerSpawn + j] = Enemy{spawnpt->pos, rand() % 4};
    }

    spawnpt = spawnpt->next;
  }  
  cout << endl;

  return in;
}

void display(Board b)
{
  // draw base board
  for (int row = 0; row < b.ROWS; row++)
  {
    for (int col = 0; col < b.COLS; col++)
    {
      drawChar(b.board[row][col], row, col);
    }
  }

  // draw goal
  drawChar('X', b.goal.row, b.goal.col);

  // draw player
  drawChar('P', b.player.row, b.player.col);

  // draw the enemies
  // ships
  for (int i = 0; i < b.numships; i++)
  {
    drawChar('*', b.ships[i].pos.row, b.ships[i].pos.col);
  }
  // hunters
  for (int i = 0; i < b.numhunters; i++)
  {
    drawChar('K', b.hunters[i].pos.row, b.hunters[i].pos.col);
  }

  // update the window
  refreshWindow();
}

void free(Board &b)
{
  // free the board
  for(int row = 0; row < b.ROWS; row++)
  {
    delete[] b.board[row];
  }
  delete[] b.board;

  // free the spawnpts
  free(b.spawnpts);

  // free the ships
  delete[] b.ships;

  // free the Hunters
  delete[] b.hunters;
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

void move(Board &b)
{
  // take test step
  Pos test = step(b.player, b.playerdir);
  
  // handle collisions
  b.player = collision(b, test);

  // see if they won
  if(dist(b.player, b.goal) == 1)
    b.isWin = true;
}

void moveships(Board &b)
{
  for (int i = 0; i < b.numships; i++)
  {
    // figure out dir
    bool doTurn = rand() % 10 == 0; // 1/10 chance
    if (doTurn)
    {
      bool isLeft = rand() % 2 == 0;
      int angle = 90 * (isLeft ? -1 : 1);
      b.ships[i].enemydir = turn(b.ships[i].enemydir, angle);
    }

    // take test step
    Pos test = step(b.ships[i].pos, b.ships[i].enemydir);

    // handle collisions
    b.ships[i].pos = collision(b, b.ships[i], test);
  }
}

void movehunters(Board &b)
{
  for (int i = 0; i < b.numhunters; i++)
  {
    // figure out dir
    if (rand() % 2 == 1)
    {
      int dcol = b.player.col - b.hunters[i].pos.col;
      int drow = b.player.row - b.hunters[i].pos.row;
      int cdir, rdir;
      if (dcol < 0)
        cdir = WEST;
      if (dcol >= 0)
        cdir = EAST;
      if (drow < 0)
        rdir = NORTH;
      if (drow >= 0)
        rdir = SOUTH;
      if (rand() % 2 == 0)
      {
        b.hunters[i].enemydir = rdir;
      }
      else
      {
        b.hunters[i].enemydir = cdir;
      }
    }

    // take test step
    Pos test = step(b.hunters[i].pos, b.hunters[i].enemydir);

    // handle collisions
    b.hunters[i].pos = collision(b, b.hunters[i], test);
  }
}

Pos collision(Board &b, Pos test)
{
  // check for walls
  if (b.board[test.row][test.col] == '#')
  {
    test = step(test, turn(b.playerdir, 180));
    if (b.board[test.row][test.col] == '#')
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

Pos collision(Board &b, Enemy &enemy, Pos test)
{
  // check for player collision before moving
  if (equal(b.player, test))
  {
    b.collidedEnemy = true;
  }
  // check for walls
  if (b.board[test.row][test.col] == '#')
  {
    test = step(test, turn(enemy.enemydir, 180));
    if (b.board[test.row][test.col] == '#')
    {
      // stay in the same orientation and place
      return test;
    }
    else
    {
      enemy.enemydir = turn(enemy.enemydir, 180);
      return test;
    }
  }
  // check for player collision after moving
  if (equal(b.player, test))
  {
    b.collidedEnemy = true;
  }
  // no collision
  else
  {
    return test;
  }
}