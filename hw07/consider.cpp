#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 2;

    while(a <= 10)
    {
        if (a % 2) 
        {
            a = a + b;
            b = b + 2;
        }
        else
        {
            a = a + 1;
            b = b - 1;
        }
        cout << a << " " << b << endl;
    }

    return 0;
}