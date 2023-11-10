#include "list.h"

/* NODE */
Node* add2front(Pos p, Node* list)
{
  Node* node = new Node;
  node->pos = p;
  node->next = list;
  return node;
}

void free(Node* list)
{
  Node* temp = list->next;
  while(temp != nullptr)
  { 
    delete list;
    list = temp;
    temp = list->next;
  }
  delete list;
}

ostream& operator<<(ostream& out, Pos p)
{
  return out << "(" << p.row << "," << p.col << ")";
}
