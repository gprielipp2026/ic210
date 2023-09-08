#include <iostream>
using namespace std;

int main()
{
  // variables
  int sum = 0, input;
  char op = 'a', space;

  cin >> sum >> op >> input;

  //loop until '='
  while (op != '=')
  {
    // process input
    if (op == '+') sum += input;
    else if (op == '-') sum -= input;
  
    // get input
    cin >> op >> input;
    cout << "sum: " << sum << " " << op << " " << input << endl;
  }

  // return sum
  cout << "sum: " << sum << endl;

  return 0;
}
