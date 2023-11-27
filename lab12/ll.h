#pragma once
#include <iostream>
using namespace std;

#include "Pair.h"

struct Node 
{
  Pair data;
  Node* next;
  int length;
};


Node* newNode(Pair p, Node* n, int l);
void deletell(Node*& root);
void add2front(Pair p, Node*& root);
void remove(Node* node, Node*& root);
void print2(Node* root, Node* node);
void printpretty2(Node* root, Node* node);
void printpretty(Node* root);

istream& operator>>(istream& is, Node*& root);
ostream& operator<<(ostream& os, Node* root);
