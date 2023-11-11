#pragma once
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "easycurses.h"
#include "Pos.h"
#include "list.h"
using namespace std;

/* POS DIRECTIONS */
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

/* ENEMY */
struct Enemy
{
  Pos pos;
  int enemydir;
};

/* BOARD */
struct Board
{
  bool isWin;
  bool collidedEnemy;

  int shipsPerSpawn;
  int huntersPerSpawn;

  int ROWS, COLS;
  char** board; // the spots and stuff, what will be displayed
  Pos player;
  int playerdir;
  Pos goal;
  bool isStopped;
  int numspawnpts;
  Node *spawnpts; // linked list

  /* the ENEMIES */
  // space ships
  int numships;
  Enemy *ships;
  // hunters
  int numhunters;
  Enemy *hunters;
};

/* FUNCTIONS */
istream& operator>>(istream& in, Board& b);
void display(Board b);
void free(Board &b);
int dir(Board& b, int keycode);
void move(Board &b);
void moveships(Board &b);
void movehunters(Board &b);
Pos collision(Board& b, Pos test);
Pos collision(Board &b, Enemy &enemy, Pos test);
