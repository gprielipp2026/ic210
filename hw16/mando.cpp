#include <iostream>
using namespace std;
bool isprime(int n)
{
    if (n <= 1) return false;
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0) return false;
    }
    return true;
}

int main()
{
    int n;
    int n_save;
    cout << "Enter n: ";
    cin >> n;
    n_save = n;

    int count = 0;
    while(n--)
    {
        if(isprime(n)) count++;
    }

    cout << (double(count) / double(n_save)) * 100.0 << "% of the first " << n_save << " integers are prime!" << endl;

    return 0;
}
