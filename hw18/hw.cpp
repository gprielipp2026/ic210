/*
 * Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * prints out hwo to do the dot procut of two vetors
 */

#include <iostream>
using namespace std;

bool isneg(double n);

int main()
{
    char x, y, c;
    int N;
    // read N
    cin >> c >> c >> N;

    // read X
    double X[N];
    cin >> x >> c;
    for(int i = 0; i < N; i++)
      cin >> c >> X[i];
    cin >> c;

    // read Y
    double Y[N];
    cin >> y >> c;
    for(int i = 0; i < N; i++)
        cin >> c >> Y[i];
    cin >> c;

    // output
    cout << "<" << x << "," << y << "> = ";
    double dot = 0;
    for(int i = 0; i < N; i++)
    {
      dot += X[i] * Y[i];
      // X
      if(isneg(X[i]))
          cout << "(" << X[i] << ")" << " * ";
      else
          cout << X[i] << " * ";
      // Y
      if(isneg(Y[i]))
          cout << "(" << Y[i] << ")";
      else
          cout << Y[i];
      
      if(i < N-1)
          cout << " + ";
    }

    cout << " = " << dot << endl;

    return 0;
}

bool isneg(double n)
{
    return n < 0;
}
