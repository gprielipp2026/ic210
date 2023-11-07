/* p4.cpp
 * MIDN GEORGE PRIELIPP (265112) 
 * make my points move *RANDOMLY* */
#include "easycurses.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
#include <ctime>
using namespace std;

#define NORTH M_PI_2
#define EAST 0
#define SOUTH 3*M_PI_4
#define WEST M_PI

int ROWS, COLS;

/* POINT */
struct Point
{
  // seed random
  srand(time(0));

  // starting at 0 and going to height or width respectively
  int row, col;
  char val;
  double dir;

  void display();
  void update(int distance);
  void erase();
  Point& operator=(char c);
  friend istream& operator>>(istream& in, Point& pt);
};

/* FUNCTIONS */
double rand_dir(double curdir);

int main()
{
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

  // move the characters around for 20 frames
  for(int frame = 0; frame < 20; frame++)
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
  col += int(distance*cos(dir)) % COLS;
  row += int(distance*-1*sin(dir)) % ROWS;
}

void Point::erase()
{
  drawChar(' ', row, col);
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
  int r = rand() % 5;
  if(r == 0)
    return NORTH;
  else if(r == 1)
    return EAST;
  else if(r == 2)
    return SOUTH;
  else if(r == 3)
    return WEST;
  else if(r == 4)
    return curdir;
}
