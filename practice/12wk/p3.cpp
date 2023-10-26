/* Filename: p3.cpp
 * name: MIDN GEORGE PRIELIPP (265112)
 * creates a user specified grid through commands to draw to the grid*/
#include <iostream>
using namespace std;

void draw(char**& grid, int width, int height, bool isRow, bool isPos, int idx, int idy);
void show(char** grid, int width, int height);

int main()
{
  // get the grid size
  int width, height;
  char x;
  cin >> height >> x >> width;

  // create the char**
  char** grid = new char*[height];
  for(int i = 0; i < height; i++)
  {
    grid[i] = new char[width];
    for(int j = 0; j < width; j++)
    {
      grid[i][j] = ' ';
    }
  }

  // get the commands
  string cmd;
  char atrc;
  int idx, idy;
  while(cin >> cmd && cmd != "quit")
  {
    if(cmd == "draw")
    {
      cin >> atrc;
      idy = 0;
      if(atrc == '@')
      {
        cin >> idx >> idy;
        draw(grid, width, height, false, true, idx, idy);
      }
      else if(atrc == 'r')
      {
        cin >> cmd >> idx;
        draw(grid, width, height, true, false, idx, idy);
      }
      else if(atrc == 'c')
      {
        cin >> cmd >> idx;
        draw(grid, width, height, false, false, idx, idy);
      }
    }

    else if(cmd == "show")
    {
      show(grid, width, height);
    }
  }

  return 0;
}

// alters the grid based on isRow and isPos
void draw(char**& grid, int width, int height, bool isRow, bool isPos, int idx, int idy)
{
  // its a position!
  if(isPos)
  {
    grid[idx][idy] = '+';
  }

  // its a row
  else if(isRow)
  {
    for(int i = 0; i < width; i++)
    {
      if(grid[idx][i] == '|') grid[idx][i] = '+';
      else grid[idx][i] = '-';
    }
  }

  // its a col
  else
  {
    for(int i = 0; i < height; i++)
    {
      if(grid[i][idx] == '-') grid[i][idx] = '+';
      else grid[i][idx] = '|';
    }
  }
}

void show(char** grid, int width, int height)
{
  for(int i = 0; i < height; i++)
  {
    for(int j = 0; j < width; j++)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }
}