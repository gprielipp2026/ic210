#include <iostream>
using namespace std;

int main()
{
  int num, den, ttl;
  char slash;
  string word;

  cin >> num >> slash;


  if (slash == '/')
  {
    cin >> den >> word >> ttl >> word;
    
    cout << double(ttl) * double(num) / double(den) << " " << word << endl;
  }else if (slash == '%')
  {
    cin >> word >> ttl >> word;
    cout << double(num/100.0) * ttl << " " << word << endl;
  }

  return 0;
}

