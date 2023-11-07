/* p2.cpp
 * MIDN GEORGE PRIELIPP (265112) 
 * learn how to use drawChar and drawCharAndRefresh */
#include "easycurses.h"
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

/* POINT */
struct Point
{
  // starting at 0 and going to height or width respectively
  int row, col;
  char val;

  void display();
  void refresh();
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

    // wait for user to quit
  char c;
  while( (c = inputChar()) != 'q')
  {
    // display points and erase the points after displaying
    for(int i = 0; i < N; i++)
    {
      points[i].refresh();
      usleep(800000);
    }

    // erase the screen by redisplaying the points
    for(int i = 0; i < N; i++)
    {
      points[i].display();
    }
    refreshWindow();
    usleep(800000);
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
  // custom function to display a space instead of the val
  drawChar(' ', row, col);
}

void Point::refresh()
{
  drawCharAndRefresh(val, row, col);
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
