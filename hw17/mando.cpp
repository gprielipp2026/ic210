#include <iostream>
using namespace std;

int dot(int dim, int* a, int* b);

int main()
{
    cout << "Enter dimension: ";
    int dim;
    cin >> dim;

    cout << "Enter two vectors: ";
   
    int a[dim];
    int b[dim];

    int num;
    char c;
    for(int i = 0; i < dim; i++)
    {
        cin >> c >> num;
        a[i] = num;
    }
    cin >> c;
    for(int i = 0; i < dim; i++)
    {
        cin >> c >> num;
        b[i] = num;
    }
    cin >> c;

    cout << "Dot product = " << dot(dim, a, b) << endl;

    return 0;
}

int dot(int dim, int* a, int*b)
{
    int sum = 0;
    while(--dim >= 0)
    {
        sum += a[dim] * b[dim];
    }
    return sum;
}
