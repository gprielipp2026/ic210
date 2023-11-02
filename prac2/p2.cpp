/* p2.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * takes in a string ended with a '.', and the command "hide <a> <b>" and hides
 * letters a and b in the string (only for that line), quits on command "quit"
 * */
#include <iostream>
using namespace std;

void hide(string s, char a, char b);

int main()
{
  string word, sentence="", cmd;
  
  // read the sentence
  while(cin >> word && word != ".")
    sentence += word + " ";

  // the commands
  char a, b;
  while(cout << "> " && cin >> cmd && cmd != "quit")
  {
    if(cmd == "hide")
    {
      cin >> a >> b;
      hide(sentence, a, b);
    }
  }
}

void hide(string s, char a, char b)
{
  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == a || s[i] == b)
      cout << '*';
    else
      cout << s[i];
  }
  cout << endl;
}

