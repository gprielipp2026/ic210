// selection sort
#include <iostream>
#include <cstdlib>
using namespace std;

void sort(int*& array, int length);

int main()
{
  srand(0);

  int length = 10;
  int* array = new int[length];

  for(int i = 0; i < length; i++)
    array[i] = rand() % 20;

  for(int i = 0; i < length; i++)
    cout << array[i] << " ";
  cout << endl;

  sort(array, length);

  for(int i = 0; i < length; i++)
    cout << array[i] << " ";
  cout << endl;

  delete[] array;

  return 0;
}

int min_ind(int* array, int length, int start)
{
  int min = array[start];
  int minInd = start;

  for(int i = start; i < length; i++)
  {
    if(array[i] < min)
    {
      min = array[i];
      minInd = i;
    }
  }

  return minInd;
}

void swap(int& a, int& b)
{
  int t = a;
  a = b;
  b = t;
}

void sort(int*& array, int length)
{
  for(int s = 0; s < length; s++)
  {
    int minInd = min_ind(array, length, s);

    if(array[minInd] < array[s])
      swap(array[minInd], array[s]);
  }
}
