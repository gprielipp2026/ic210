/************************************************
p1.cpp
GEORGE PRIELIPP
DO NOT DELETE ANY CODE BELOW. 
Only add code as necessary.
*************************************************/

#include <iostream>
using namespace std;

struct position
{
  int row, col;
};

struct movement
{
  char dir;
  int length;
};


istream& operator>>(istream& is, position& p);
ostream& operator<<(ostream& os, position p);
istream& operator>>(istream& is, movement& m);
position operator+(position p, movement m);

int main()
{
  position p; 
  cout << "position? ";
  cin >> p;

  cout << "how many moves? ";
  int n; 
  cin >> n;

  for(int i=0; i<n; i++)
  {
    movement v;
    cin >> v;
    p = p + v;
    cout << p << endl;
  }

  return 0;
}

istream& operator>>(istream& is, position& p)
{
  char junk;
  is >> junk >> p.row >> junk >> p.col >> junk;
  return is;
}

ostream& operator<<(ostream& os, position p)
{
  os << "(" << p.row << "," << p.col << ")";
  return os;
}

istream& operator>>(istream& is, movement& m)
{
  is >> m.dir >> m.length;
  return is;
}

position operator+(position p, movement m)
{
  position out = position{p.row, p.col};
  switch(m.dir)
  {
    case 'N':
      out.row -= m.length;
      break;
    case 'E':
      out.col += m.length;
      break;
    case 'S':
      out.row += m.length;
      break;
    case 'W':
      out.col -= m.length;
      break;
  }

  return out;
}
