/* Filename: p2.cpp
 * name: MIDN GEORGE PRIELIPP (265112)
 * decodes a secret message hidden steganographically */
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  // get the keywords
  int numWords;
  cin >> numWords;
  string* keywords = new string[numWords];
  for(int i = 0; i < numWords; i++)
    cin >> keywords[i];

  // get the filename
  string fn;
  cin >> fn;

  // try to open the file
  ifstream msg(fn);
  if(!msg)
  {
    cout << "File \'" << fn << "\' not found!" << endl;
    return 1;
  }
    
  // read message and keep stuff that is after a keyword
  bool keepNext = false;
  string decoded = "";
  string word;
  while(msg >> word)
  {
    // see if we need to keep this word
    if(keepNext)
    {
      decoded += word + " ";
      keepNext = false;
      continue;
    }

    // see if it is a keyword
    for(int i = 0; i < numWords; i++)
    {
      if(word == keywords[i])
      {
        keepNext = true;
        break;
      }
    }
  }

  // output the decrypted message
  cout << decoded << endl;

  // free memory
  delete [] keywords;
  return 0;
}
