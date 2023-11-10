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

/* BOARD */
struct Board
{
  int ROWS, COLS;
  char** board; // the spots and stuff, what will be displayed
  Pos player;
  int playerdir;
  Pos goal;
  bool isStopped;
  int numenemies;
  Node* enemies; // linked list
};

/* FUNCTIONS */
istream& operator>>(istream& in, Board& b);
void display(Board b);
void free(Board b);
int dir(Board& b, int keycode);
bool move(Board& b);
Pos collision(Board& b, Pos test);
