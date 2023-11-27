/* p1.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * Linked Lists -- Printing and Counting
 */
#include <iostream>
#include <fstream>
using namespace std;

#include "ll.h"
#include "Pair.h"

typedef DLL<Pair> DLLP;

int main()
{
  // get the filename
  string fn;
  cout << "Input file is: ";
  cin >> fn;

  // open the file
  ifstream file(fn);
  if(!file)
  {
    cerr << "Error! File\'" << fn << "\' not found!" << endl;
    exit(1);
  }

  // create the DLL
  DLLP dll;
  dll.length = 0;
  dll.head = nullptr;
  dll.tail = nullptr;

  // get the stuff from the file
  Pair data;
  while(file >> data)
  {
    add2front(data, dll);
  }
  
  // output
  cout << "Count is " << dll.length << endl;
  cout << dll << endl;

  // free memory
  delete_dll(dll);

  return 0;
}
