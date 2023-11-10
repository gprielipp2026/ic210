#pragma once
#include <iostream>
#include "Pos.h"
using namespace std;

/* NODE */
struct Node
{
  Pos pos;
  Node* next;
};

Node* add2front(Pos p, Node* n);
ostream& operator<<(ostream& out, Pos p);
