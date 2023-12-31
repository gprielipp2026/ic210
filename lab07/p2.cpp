/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * swap it! 
 */
#include <iostream>
using namespace std;

// function prototypes
int* read(int);
void print(int*, int);
bool isInOrder(int*, int);

int index(char);
void swap(int*, int*);

int main()
{
  // intro
  cout << "Welcome to SWARE!" << endl;
  cout << "board> ";

  char c;
  int N;
  cin >> c >> c >> N;

  int* A = read(N);
  print(A,N);
  
  // game loop (i add this)
  int numMoves = 0;
  int numPoints = 0;
  string cmd;
  while(!isInOrder(A,N))
  {
    // get the next command
    cout << "> ";
    cin >> cmd;

    // handle the command
    if(cmd == "swap")
    {
        // read which column
        char col1, col2;
        int ind1, ind2;
        
        cin >> col1 >> col2;

        // figure out what letter equals what index
        ind1 = index(col1);
        ind2 = index(col2);

        // swap
        swap(&A[ind1], &A[ind2]);

        // add up numMoves and numPoints
        numMoves++;
        numPoints += 3;
    }
    else
    {
        cout << "Unknown move \'" << cmd << "\'" << endl;
    }

    // redisplay the board
    print(A,N);
  }

  // display the game win
  cout << numPoints << " points! (" << numMoves << " moves)" << endl;

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
  // make a pretty space
  cout << endl;

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

int index(char c)
{
  if (c >= 'A' && c <= 'Z')
    return c - 'A';
  else
    return -1;
}

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
