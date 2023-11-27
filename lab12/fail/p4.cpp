/* p4.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * Accept or Reject Words 
 */
#include <iostream>
#include <fstream>
using namespace std;

#include "ll.h"
#include "Pair.h"

typedef DLL<Pair> DLLP;

int getNUMNODES(string fn);
int score(DLLP dll);
void printpretty(DLLP dll);

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
  DLLP data;
  data.length = 0;
  dll.head = nullptr;
  dll.tail = nullptr;
  Pair p;
  while(file >> p)
    add2front(p, data);
  file.close();

  // have the user modify it
  char cmd;
  int count = 0;
  Node<Pair>* temp = data.head;
  while(++count && temp != nullptr)
  {
    cout << "The current node: " << temp->data << endl;
    cout << "Sentence you made so far: ";
    printpretty(dll);

    cout << "#words left: " << NUMNODES - count << endl;
    cout << "[a]ccept or [r]eject: ";
    cin >> cmd;
    if(cmd == 'a')
    {
      add2back(temp->data, dll);
    }
    cout << endl;

    temp = temp->next;
  }
 

  // output
  cout << "List is: ";
  printpretty(dll);
  cout << "Score is: " << score(dll) << endl;

  // free memory
  delete_dll(dll);
  delete_dll(data);

  return 0;
}

int getNUMNODES(string fn)
{
  ifstream file(fn);
  if(!file)
  {
    cerr << "Error! File\'" << fn << "\' not found!" << endl;
    exit(1);
  }
 
  int count = 0;
  Pair data;
  while(file >> data && ++count);

  return count;
}

int score(DLLP dll)
{
  Node<Pair>* temp = dll.head;
  int sum = 0;
  while(temp != nullptr)
  {
    sum += temp->data.value;
    temp = temp->next;
  }
  return sum;
}

void printpretty(DLLP dll)
{
  Node<Pair>* temp = dll.head;
  while(temp != nullptr)
  {
    cout << temp->data.name << " ";
    temp = temp->next;
  }
  cout << endl;
}
