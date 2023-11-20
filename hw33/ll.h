#pragma once

struct Node
{
  int data;
  Node* next;
};

Node* add2back(int, Node*);
void print(Node*);
void enter_after(int, int, Node*);
Node* remove(int, Node*);
Node* find(int, Node*);
void deletelist(Node*);
