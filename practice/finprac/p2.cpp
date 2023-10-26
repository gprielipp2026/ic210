/* Filename: p2.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * creates infinite series and sees how many steps until it repeats */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  // get a and b
  int a, b;
  cout << "> ";
  cin >> a >> b;

  int x = a;
  vector<int> series;

  do
  {
    series.push_back(x);
    x = (series[series.size()-1] * a) % b;
  } while(find(series.begin(), series.end(), x) == series.end());
  cout << "repeat after " << series.size() << " steps" << endl;

  return 0;
}
