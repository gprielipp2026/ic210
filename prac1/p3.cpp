#include <iostream>
using namespace std;

int main()
{
  int rows;
  cout << "Enter number rows: ";
  cin >> rows;

  string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  if(rows > alpha.size())
  {
    for(int i = alpha.size(); i < rows; i++)
      alpha += '!';
  }

  for(int row = 0; row < rows; row++)
  {
    int ltr = 0;
    
    if(row+1 < 10)
      cout << ' ';
    
    cout << row+1 << ":";

    for(int col = 0; col < rows; col++)
    {
      if(((col+1) % (row+1)) == 0)
        cout << alpha[ltr++];
      else
        cout << ' ';
    }
    cout << endl;
  }

  return 0;
}
