#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  string word;
  char c;
  int num;
  int sum = 0;
  int count = 0;

  ifstream data("numbers.txt");

  data >> word >> c >> num;
  data >> word;

  while(data >> num)
  {
      sum += num;
      count++;
  }
  
  cout << "avg: " << double(sum) / double(count) << endl;

  return 0;
}
