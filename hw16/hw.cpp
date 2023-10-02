/*
 * Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * finds if a fraction is reduced or not
 */

#include <iostream>
using namespace std;

int gcd(int a, int b);
bool isreduced(int num, int den);

int main()
{
    // variables
    int num, den;
    char slash, comma;
    
    while(cin >> num >> slash >> den >> comma && comma != ';')
    {
        if(isreduced(num, den))
            cout << num << '/' << den << " is in lowest terms!" << endl;
    }


    return 0;
}

int gcd(int a, int b)
{
    while(b > 0)
    {
       int r = a % b;
       a = b;
       b = r;
    }
    return a;
}

bool isreduced(int num, int den)
{
    return gcd(num, den) == 1;
}
