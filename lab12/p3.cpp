/* p3.cpp
 * MIDN GEORGE PRIELIPP
 * Print pretty & count the score
 */
#include <iostream>
#include <fstream>
using namespace std;

#include "ll.h"

int getscore(Node* root);

int main()
{
  // get the input file
  string fn;
  cout << "Input file is: ";
  cin >> fn;

  // open the file
  ifstream file(fn);
  if(!file)
  {
    cout << "Error! File \'" << fn << "\' not found!" << endl;
    exit(1);
  }

  // read the data
  Node* root = nullptr;
  while(file >> root);
  file.close();

  // let the user figure out the list
  Node* cur = root;
  while(cur != nullptr)
  {
    cout << endl;
    cout << "The current node: " << cur->data << endl;
    cout << "Nodes before the current: "; print2(root, cur); cout << endl;
    cout << "#nodes after the current: " << cur->length-1 << endl;
    cout << "[a]ccept or [r]eject: ";
    char cmd;
    cin >> cmd;

    if(cmd == 'r')
    {
      Node* temp = cur->next;
      remove(cur, root);
      cur = temp;
    }
    else
      cur = cur->next;
  }

  // output
  cout << endl;
  cout << "List is: "; printpretty(root); cout << endl;
  cout << "Score is: " << getscore(root) << endl;

  // free memory
  deletell(root);
  

  return 0;
}

int getscore(Node* root)
{
  if(root == nullptr)
    return 0;
  return root->data.value + getscore(root->next);
}
