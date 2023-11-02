/* p1.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * reads two vectors then does stuff with it */

#include <iostream>
using namespace std;

int readN();
double* readnums(int, char*);
void print(double*, double*, char, char, int);
void average(double*, double*, char, char, int);

int main()
{
  int n = readN();
  char cA, cB;
  double* A = readnums(n, &cA);
  double* B = readnums(n, &cB);

  string cmd;
  while( cout << "> " && cin >> cmd && cmd != "quit" )
  {
    if( cmd == "print" )
      print(A, B, cA, cB, n);
    else if ( cmd == "average" )
      average(A, B, cA, cB, n);
    else
      cout << "invalid command!" << endl;
  }

  delete [] A;
  delete [] B;

  return 0;
}
  
int readN()
{
  int n;
  cin >> n;
  return n;
}

double* readnums(int n, char* c)
{
  char colon;
  cin >> *c >> colon;
  double* arr = new double[n];
  for(int i = 0; i < n; i++)
    cin >> arr[i];

  return arr;
}

void print(double* A, double* B, char a, char b, int n)
{
  char letter;
  cin >> letter;
  if(letter == a)
  {
    cout << "[";
    for(int i = 0; i < n; i++)
    {
      cout << A[i];
      if(i < n-1)
        cout << " ";
    }
    cout << "]" << endl;
  }
  else if(letter == b)
  {
    cout << "[";
    for(int i = 0; i < n; i++)
    {
      cout << B[i];
      if(i < n-1)
        cout << " ";
    }
    cout << "]" << endl;
  }
  else
  {
    cout << "no such vector!" << endl;
  }
}

void average(double* A, double* B, char a, char b, int n)
{
  char letter;
  cin >> letter;
  double avg = 0;
  if(letter == a)
  {
    for(int i = 0; i < n; i++)
      avg += A[i]/n;
  }
  else if(letter == b)
  {
    for(int i = 0; i < n; i++)
      avg += B[i]/n;
  }
  else
  {
    cout << "no such vector!" << endl;
    return;
  }
  cout << avg << endl;
}
