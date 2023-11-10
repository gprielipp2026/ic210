/* hw.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * prints out the 3rd to last number that was entered by storing 
 * them in a linked list */
#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node* next;
};

// adds a number to the front of a linked list
Node* add2front(int data, Node* list);

int main()
{
  // create the linked list
  Node* root = new Node;
  root->data = -1;
  root->next = nullptr;

  // get the numbers into the list
  int num;
  while(cin >> num && num > 0)
  {
    root = add2front(num, root);
  }

  // display the 3rd to last
  // there is a better/generic way to do this but this works :)
  cout << root->next->next->data << endl;

  // free memory
  Node* tmp = root->next;
  while(tmp != nullptr)
  {
    delete root;
    root = tmp;
    tmp = root->next;
  }
  delete root;

  return 0;
}

Node* add2front(int data, Node* list)
{
  Node* root = new Node;
  root->data = data;
  root->next = list;

  return root;
}
