/* hw.cpp
 * MIDN GEORGE PRIELIPP
 * Reads in two points and prints their midpoint
 */
#include <stdio.h>

int main()
{
  // the points
  float x1, y1;
  float x2, y2;

  // getting the points
  char newline;
  scanf("(%f,%f)%c", &x1, &y1, &newline);
  scanf("(%f,%f)%c", &x2, &y2, &newline);

  // calculate the midpoint
  float mx = (x1 + x2) / 2.0;
  float my = (y1 + y2) / 2.0;

  // print it to the screen
  printf("(%f,%f)\n", mx, my);

  return 0;
}
