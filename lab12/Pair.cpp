#include "Pair.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& in, Pair& p)
{
  char c;
  in >> c >> p.name >> p.value >> c;
  return in;
}

ostream& operator<<(ostream& out, Pair p)
{
  return out << "(" << p.name << " " << p.value << ")";
}
