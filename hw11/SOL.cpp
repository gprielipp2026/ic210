#include <iostream>
using namespace std;
int main(int argc, char* argv[])
{
    int n=atoi(argv[1]);
//    cout << "please enter n: ";
  //  cin >> n;
    int sum = 0;
    for(int k=0; k<=n; k++)
    {
        int num=1;
        for(int m=n; m>n-k;m--)
          num *= m;
        int den =1;
        for(int i=1;i<=k;i++)
            den*=i;
        sum+=num/den;
    }
    cout << sum <<endl;
    return 0;
}
