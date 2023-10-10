#include <iostream>
#include <vector>
using namespace std;

void filter(vector<int>& arr, bool (*func)(int) )
{
    for(int i : arr)
        if(func(i)) i = 0;
}

int main()
{
    int N = 10;
    vector<int> arr;
    for(int i = 2; i < N; i++)
      arr.push_back(i);
    
    bool func = [](int x) { return x % 2; };
  
    filter(arr, func);

    for(int i : arr)
        cout << i << ": " << func(i) << endl;

    return 0;
}
