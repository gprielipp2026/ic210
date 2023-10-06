#include <iostream>
using namespace std;

// ======================================
// Function prototypes below
// ======================================

int readN();
int* readData(int);
void show(int*, int);
void swap(int*, int);

// ======================================
// main function
// TOUCH NOTHING INSIDE THE FUNCTION!!
// ======================================
int main()
{
  int n = readN();
  int* A = readData(n);

  string cmd;
  cout << "cmd: ";
  while( (cin >> cmd) && cmd != "quit" ) 
  {
    if( cmd == "show" )
      show(A, n);
    else if ( cmd == "swap" )
      swap(A, n);

    cout << "cmd: ";
  }

  return 0;
}


// ======================================
// Function definitions below
// ======================================

int readN()
{
  int N;
  char c;
  //     N    =    D
  cin >> c >> c >> N;
  return N;
}

int* readData(int N)
{
  int* data = new int[N];

  // read the next entries
  for(int i = 0; i < N; i++)
    cin >> data[i];

  return data;
}

void show(int* data, int len)
{
  // loop through the "rows"
  for(int row = 0; row < len; row++)
  {
    // print out what row we're at
    cout << '[' << row << "] ";
    // print out the corresponding number of strs
    for(int col = 0; col < data[row]; col++)
      cout << '*';
    // move to next line
    cout << endl;
  }

}

void swap(int* data, int len)
{
  // get which rows to swap
  int rowA, rowB;
  cin >> rowA >> rowB;

  // swap the rows
  data[rowA] ^= data[rowB];
  data[rowB] ^= data[rowA];
  data[rowA] ^= data[rowB];
}
