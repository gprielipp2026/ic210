/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * array functions
 */
#include <iostream>
using namespace std;

// function prototypes
int* read(int);
void print(int*, int);
bool isInOrder(int*, int);

int main()
{
  char c;
  int N;
  cin >> c >> c >> N;

  int* A = read(N);
  print(A,N);
  if (isInOrder(A,N))
    cout << "Is in order!" << endl;
  else
    cout << "Is not in order!" << endl;
  delete [] A;
  return 0;
}

// function definition
int* read(int size)
{
  // read ':'
  char c;
  cin >> c;

  // create pointer
  int* arr = new int[size];
  
  // read ints
  for(int i = 0; i < size; i++)
    cin >> arr[i];

  return arr;
}

void print(int* arr, int len)
{
  // print out the values
  for(int i = 0; i < len; i++)
    cout << " " << arr[i];
  cout << endl;

  // print out the "-----"
  for(int i = 0; i <= 2*len; i++)
    cout << "-";
  cout << endl;

  // print out the letters
  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for(int i = 0; i < len; i++)
    cout << " " << alpha[i];
  cout << endl;
}

bool isInOrder(int* arr, int len)
{
  // loop through array and see if ordered ascending
  for(int i = 0; i < len-1; i++)
  {
    if(arr[i] > arr[i+1]) return false;
  }
  return true;
}
