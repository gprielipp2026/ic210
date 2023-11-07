/* p3.cpp
 * MIDN GEORGE PRIELIPP (265112) 
 * make my points move */
#include "easycurses.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cmath>
using namespace std;

#define NORTH M_PI_2
#define EAST 0
#define SOUTH 3*M_PI_4
#define WEST M_PI

int ROWS, COLS;

/* POINT */
struct Point
{
  // starting at 0 and going to height or width respectively
  int row, col;
  char val;

  void display();
  void update(double angle, int distance);
  void erase();
  Point& operator=(char c);
  friend istream& operator>>(istream& in, Point& pt);
};

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
      points[i].update(EAST, 1); 
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

void Point::update(double angle, int distance)
{
  col += int(distance*cos(angle)) % COLS;
  row += int(distance*sin(angle)) % ROWS;
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
  return in >> pt.val >> c >> pt.row >> c >> pt.col >> c;
}
