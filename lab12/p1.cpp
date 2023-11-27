/* p1.cpp
 * MIDN GEORGE PRIELIPP
 * Linked Lists -- Printing and Counting
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
    cout << "Error! File \'" << fn << "\' not found!" << endl;
    exit(1);
  }

  // read the data
  Node* root = nullptr;
  while(file >> root);
  file.close();

  // output
  cout << "Count is " << root->length << endl;
  cout << root << endl;

  // free memory
  deletell(root);
  

  return 0;
}
