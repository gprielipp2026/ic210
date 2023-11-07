/* p5.cpp
 * MIDN GEORGE PRIELIPP (265112) 
 * make my points move *RANDOMLY*, but within a border */
#include "easycurses.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <ctime>
using namespace std;

#define NORTH M_PI_2
#define EAST 0
#define SOUTH 3*M_PI_2
#define WEST M_PI

int ROWS = 0, COLS = 0;

/* POINT */
struct Point
{
  // starting at 0 and going to height or width respectively
  int row, col;
  char val;
  double dir;

  void display();
  void update(int distance);
  void erase();
  void bounce();
  Point& operator=(char c);
  friend istream& operator>>(istream& in, Point& pt);
};

/* FUNCTIONS */
double rand_dir(double curdir);

int main()
{
  // seed random
  srand(time(0));

  // get user input before entering curses
  int N;
  cin >> N;

  Point* points = new Point[N];
  
  // read points
  for(int i = 0; i < N; i++)
  {
    cin >> points[i];
  }


  // start ncurses
  startCurses();

  // get the dimensions
  getWindowDimensions(ROWS, COLS);

  // display all of the points
  for(int i = 0; i < N; i++)
  {
    points[i].display();
  }
  refreshWindow();
  usleep(80000);

  // move the characters around until the user enters 'q'
  char c;
  while((c = inputChar()) != 'q')
  {
    // move the points to the east
    for(int i = 0; i < N; i++)
    {
      points[i].erase();
      points[i].update(1); 
    }
    // display the points
    for(int i = 0; i < N; i++)
    {
      points[i].display();
    }

    refreshWindow();
    usleep(80000);
  }

  // end ncurses
  endCurses();

  // free memory
  delete[] points;

  return 0;
}

/* POINT */
void Point::display()
{
  drawChar(val, row, col);
}

void Point::update(int distance)
{
  dir = rand_dir(dir);
  
  int dx = int(distance*cos(dir));
  int dy = int(distance*-1*sin(dir));
  
  if(col + dx >= COLS || col + dx < 0)
  {
    bounce();
    dx = int(distance*cos(dir));
  }

  if(row + dy >= ROWS || row + dy < 0)
  {
    bounce();
    dy = int(distance*cos(dir));
  }

  col += dx;
  row += dy;
}

void Point::erase()
{
  drawChar(' ', row, col);
}

void Point::bounce()
{
  if(dir == NORTH)
    dir = SOUTH;
  else if(dir == SOUTH)
    dir = NORTH;
  else if(dir == EAST)
    dir = WEST;
  else if(dir == WEST)
    dir = EAST;
  
}

Point& Point::operator=(char c)
{
  val = c;
  return *this;
}

istream& operator>>(istream& in, Point& pt)
{
  char c;
  pt.dir = EAST;
  return in >> pt.val >> c >> pt.row >> c >> pt.col >> c;
}

/* FUNCTION */
double rand_dir(double curdir)
{
  // should we turn?
  bool doTurn = (rand()%5) == 1;
  
  if(doTurn)
  {
    // determine which way to turn
    int r = rand()%2;
    bool isVert = curdir == NORTH || curdir == SOUTH;

    // determine new dir
    // these conditions are described in p5.2 (bullet points) in the requirements
    if(isVert)
    {
      if(r)
        return WEST;
      else
        return EAST;
    }
    else
    {
      if(r)
        return NORTH;
      else
        return SOUTH;
    }
  }  

  return curdir;
}
