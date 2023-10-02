#include <iostream>
#include <fstream>
using namespace std;

int min(int a, int b);
int max(int a, int b);

int main()
{
  string word;
  char c;
  int num;

  int nmin = 100000000;
  int nmax = -100000000;

  ifstream data("numbers.txt");

  data >> word >> c >> num;
  data >> word;

  while(data >> num)
  {
      nmin = min(nmin, num);
      nmax = max(nmax, num);
  }

  cout << "min: " << nmin << endl;
  cout << "max: " << nmax << endl;


  return 0;
}

int min(int a, int b)
{
    return (a > b ? b:a);
}

int max(int a, int b)
{
    return (a > b ? a:b);
}
