#include "ll.h"

Node* newNode(Pair p, Node* n, int l)
{
  Node* node = new Node;
  node->data = p;
  node->next = n;
  node->length = l;
  return node;
}

void deletell(Node*& root)
{
  if(root == NULL)
    return;
  deletell(root->next);
  delete root;
}

void add2front(Pair p, Node*& root)
{
  Node* front = newNode(p, root, root->length+1);
  root = front;
}

void remove(Node* node, Node* root)
{
  Node* prev = root;
  // get the prev node
  while(prev->next != node && (prev = prev->next));
  
  prev->next = node->next;
  delete node;
}

void print2(Node* root, Node* node)
{
  Node* temp = root;
  while(temp != node)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
}

void printpretty(Node* root)
{
  if(root == nullptr)
    return;
  
  cout << root->data << " ";
  printpretty(root->next);
}

istream& operator>>(istream& is, Node*& root)
{
  Pair p;
  if(!(is >> p))
    return is;

  if(root == nullptr)
  {
    root = newNode(p, nullptr, 1);
  }
  else
  {
    add2front(p, root);
  }

  return is;
}

ostream& operator<<(ostream& os, Node* root)
{
  if(root == nullptr)
    return os;

  return os << root->data << " " << root->next;
}
