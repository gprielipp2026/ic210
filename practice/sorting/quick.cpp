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

void sort(int*& array, int length)
{

}
