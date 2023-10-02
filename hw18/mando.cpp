#include <iostream>
using namespace std;

int isneg(int a)
{
    return (a < 0);
}

int main()
{
  int N;
  cin >> N;
  int neg[N],pos[N];  
  int negs = 0; int poss = 0;

  for(int i = 0; i < N; i++)
  {
    int a;
    cin >> a;
    if(isneg(a)) neg[negs++] = a;
    else pos[poss++] = a;
  }

  cout << "negative: ";
  for(int i = 0; i < negs; i++)
      cout << neg[i] << " ";
  cout << endl << "positive: ";
  for(int i = 0; i < poss; i++)
      cout << pos[i] << " ";
  cout << endl;

  return 0;
}
