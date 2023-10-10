#include <iostream>
using namespace std;

int getposint()
{
  int x;

  do {
      cin >> x;
  } while(x < 0); // can't have negative number

  return x;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int a = getposint(), b = getposint();
    cout << "The gcd is " << gcd(a,b) << endl;
    return 0;
}
