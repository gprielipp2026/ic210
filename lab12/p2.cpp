/* p2.cpp
 * MIDN GEORGE PRIELIPP
 * The user iterates through the list
 */
#include <iostream>
#include <fstream>
using namespace std;

#include "ll.h"

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
    cerr << "Error! File \'" << fn << "\' not found!" << endl;
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
    cout << "The current node: " << cur->data << endl;
    cout << "Nodes before the current: "; print2(root, cur); cout << endl;
    cout << "#nodes after the current: " << cur->length-1 << endl;
    cout << "[a]ccept or [r]eject: ";
    char cmd;
    cin >> cmd;
    cout << endl;

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
  cout << "List is: " << root << endl;

  // free memory
  deletell(root);
  

  return 0;
}
