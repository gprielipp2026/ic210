/******************************************
list.h

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/

#pragma once
#include <iostream>
using namespace std;

struct Character
{
  char label;
  int row, col;
};

struct Node
{
  Character data;
  Node* next;
};

void deletelist(Node* L);

// my stuff
ostream& operator<<(ostream& os, Character c);

Node* add2back(Character x, Node* root);
void print(Node* root);
void nodesLeftOf(Node* root, int col);
void removeThird(Node* root);
