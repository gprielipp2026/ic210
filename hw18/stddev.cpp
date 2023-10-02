#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double avg(int sum, int n);
int sum(int* arr, int n);

int main()
{
  string word;
  char c;
  int num;
  ifstream data("numbers.txt");
  int N;
  data >> word >> c >> N;
  data >> word;
  int count = 0;

  int nums[N];
  while(count < N && data >> nums[count++]){}

  double avg_ = avg(sum(nums, N), N);
  double top = 0;
  while(count--)
  {
      cout << count << endl;
      top += (nums[count] - avg_)*(nums[count] - avg_);
  }

  double dev = sqrt( top/(double)N );
  cout << "STD Deviation: " << dev << endl;

  return 0;
}

double avg(int sum, int n)
{
    return (double)sum/double(n);
}

int sum(int* arr, int n)
{
    int s = 0;
    while(n--)
        s += arr[n];
    return s;
}
