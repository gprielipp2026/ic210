/* hw.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * create a linked list and search it */
#include <iostream>
using namespace std;

struct Node
{
  string data;
  Node* next;
};

Node* add2front(Node* root, string data);
void free(Node* root);

int main()
{
  // create the root
  Node* root = new Node{"", nullptr};

  // read in the words
  cout << "Enter words followed by END: " << endl;
  
  string word;
  cin >> root->data;
  if(root->data == "END") return 1;
  while(cin >> word && word != "END")
  {
    root = add2front(root, word);
  }

  // search the words
  char item;
  cout << "What letter? ";
  cin >> item;

  Node* temp = root;
  while(temp != nullptr)
  {
    if(temp->data[0] == item)
    {
      cout << temp->data << endl;
    }
    temp = temp->next;
  }

  // free memory
  free(root);

  return 0;
}

Node* add2front(Node* root, string data)
{
  return new Node{data, root};
}

void free(Node* root)
{
  Node* temp = root;
  while(temp->next != nullptr)
  {
    temp = temp->next;
    delete root;
    root = temp;
  } 
  delete root;
}
