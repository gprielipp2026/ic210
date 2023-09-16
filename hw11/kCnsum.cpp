/*
 * Filename: kCnsum.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Sums k choose n as k goes from 0 to n
 */

#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // get n
    int n = atoi(argv[1]);
   // cout << "Enter a value for n: ";
   // cin >> n;

    // comput the sum
    int sum = 0;
    for(int k = 1; k <= n; k++)
    {
        int num = 1;
        int den = 1;
        for(int i = 0; i < k; i++)
        {
            num *= (n - i);
            den *= (k - i);
        }
        sum += num / den;
    }
    sum += 1; // for some reason always one behind
    cout << sum << endl;

    return 0;
}
