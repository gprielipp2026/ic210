#include <iostream>
using namespace std;

#include "ll.h"

Node* add2back(int data, Node* root)
{
  Node* temp = new Node{data, NULL};

  if(root == NULL)
  {
    root = temp;
  }
  else
  {
    Node* it = root;
    while(it->next != NULL)
      it = it->next;
    it->next = temp;
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

void enter_after(int data, int value, Node* root)
{
  Node* after = find(value, root);
  Node* n = new Node{data, after->next};
  after->next = n; 
}

Node* remove(int value, Node* root)
{
  Node* prev = NULL;
  Node* cur = root;
  while(cur != NULL && cur->data != value)
  {
    prev = cur;
    cur = cur->next;
  }

  if(cur != NULL && prev != NULL)
  {
    prev->next = cur->next;
    delete cur;
  }
  
  return root;
}

Node* find(int value, Node* root)
{
  Node* temp = root;

  while(temp != NULL && temp->data != value)
  {
    temp = temp->next;
  }

  return temp;
}

void deletelist(Node* root)
{
  if(root == NULL)
    return;

  deletelist(root->next);
  delete root;
}
