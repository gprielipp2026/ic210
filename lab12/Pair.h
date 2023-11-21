#pragma once
#include <iostream>
using namespace std;

struct Pair
{
  string name;
  int value;
};

istream& operator>>(istream& in, Pair& p);
ostream& operator<<(ostream& out, Pair p);

