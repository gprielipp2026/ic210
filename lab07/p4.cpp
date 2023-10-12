/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * going further, let's get graphical 
 */
#include <iostream>
using namespace std;

// function prototypes
int* read(int);
void print(int*, int);
bool isInOrder(int*, int);

int index(char);
void swap(int*, int*);

void reverse(int*, int, int);

int max(int*,int);

int main()
{
  // intro
  cout << "Welcome to Swap and Reverse!" << endl;
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
    else if (cmd == "reverse")
    {
      // read which column
      char col1, col2;
      int ind1, ind2;

      cin >> col1 >> col2;

      // figure out what letter equals what index
      ind1 = index(col1);
      ind2 = index(col2);

      // reverse
      reverse(A, ind1, ind2);

      // add up numMoves and numPoints
      numMoves ++;
      numPoints += 2;
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
  int rows = max(arr, len);
  for(int row = 0; row < rows; row++)
  {
    // loop through array and see what it should print
    for(int col = 0; col < len; col++)
    {
      if(rows-row <= arr[col])
        cout << " #";
      else
        cout << "  ";
    }
    cout << endl;
  }
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

void reverse(int* arr, int ind1, int ind2)
{
  // reverse the array in place
  for(int i = 0; i <= (ind2-ind1)/2; i++)
  {
    swap(&arr[ind1 + i], &arr[ind2 - i]);
  }
}

int max(int* arr, int len)
{
  int m = arr[0];
  // loop through array and see if the value is greater than max
  while(len--)
  {
    if(arr[len] > m) m = arr[len];
  }
  return m;
}
