/* p2.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * The user iterates through the list
 */
#include <iostream>
#include <fstream>
using namespace std;

#include "ll.h"
#include "Pair.h"

typedef DLL<Pair> DLLP;

int getNUMNODES(string fn);

int main()
{
  // get the filename
  string fn;
  cout << "Input file is: ";
  cin >> fn;
  cout << endl;

  // get the NUMNODES
  int NUMNODES = getNUMNODES(fn);

  // open the file
  ifstream file(fn);
  
  // create the DLL
  DLLP dll;
  dll.length = 0;
  dll.head = nullptr;
  dll.tail = nullptr;

  // get the stuff from the file
  Pair data;
  char cmd;
  int count = 0;
  while(file >> data && ++count)
  {
    cout << "The current node: " << data << endl;
    cout << "Nodes before the current: " << dll << endl;
    cout << "#nodes after the current: " << NUMNODES - count << endl;
    cout << "[a]ccept or [r]eject: ";
    cin >> cmd;
    if(cmd == 'a')
    {
      add2back(data, dll);
    }
    cout << endl;
  }
 

  // output
  cout << "List is: " << dll << endl;

  // free memory
  delete_dll(dll);

  return 0;
}

int getNUMNODES(string fn)
{
  ifstream file(fn);
  if(!file)
  {
    cerr << "Couldn't open the file" << endl;
    exit(1);
  }
 
  int count = 0;
  Pair data;
  while(file >> data && ++count);

  return count;
}
