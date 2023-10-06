#include <iostream>
using namespace std;

bool contains(string s, string* A, int N)
{
  for(int i = 0; i < N; i++)
  {
    if(s == A[i]) return true;
  }
  return false;
}

int* getarray(int N, int x)
{
  int* A = new int[N];
  while(--N>=0)
  {
    A[N] = x;
  }
  return A;
}
