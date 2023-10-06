#include <iostream>
#include <fstream>
using namespace std;

void fileMinMax(int* min, int* max)
{
  ifstream file("data.txt");
  int num;
  while(file >> num)
  {
    if(num > *max)
      *max = num;
    if(num < *min)
      *min = num;
  }
}
