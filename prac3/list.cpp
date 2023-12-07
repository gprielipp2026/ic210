/******************************************
list.cpp

DO NOT DELETE ANY CODE BELOW
Only add code below as necessary
******************************************/
#include "list.h"

ostream& operator<<(ostream& os, Character c)
{
  return os << "[" << c.label << " (" << c.row << "," << c.col << ")]";
}

void deletelist(Node* L)
{
  if( L == NULL )
  {
    return;
  }
  else 
  {
    deletelist(L->next);
    delete L;
  }
}

// my stuff
Node* add2back(Character x, Node* root)
{
  if(root == NULL)
  {
    root = new Node{x, NULL};
  }
  else
  {
    Node* temp = root;
    while(temp->next != NULL)
      temp = temp->next;

    temp->next = new Node{x, NULL};
  }

  return root;
}

void print(Node* root)
{
  if(root == NULL)
  {
    cout << endl;
    return;
  }
  cout << root->data << " ";
  print(root->next);
}

void nodesLeftOf(Node* root, int col)
{
  if(root == NULL)
    return;
  if(root->data.col < col)
    cout << root->data << endl;
  nodesLeftOf(root->next, col);
}

void removeThird(Node* root)
{
  Node* second = root->next;
  Node* third = second->next;
  Node* fourth = third->next;

  second->next = fourth;
  delete third;
}


