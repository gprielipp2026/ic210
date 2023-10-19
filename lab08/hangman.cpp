/* Filename: hangman.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * part2: hangman */

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void printSpaced(string s);
string mkShadowString(string s);
string uncover(string original, string covered, char c);
string crossOut(char c, string s);

int main()
{
  // print opening statement
  cout << "Welcome to hangman!" << endl;

  // get the seed value
  int seed;
  cout << "Enter a seed value: ";
  cin >> seed;
  srand(seed);
   
  // get a random word from words07.txt
  string word;
  ifstream fin("words07.txt");
  int index = rand() % 1466;
  while(index-- >= 0) fin >> word;
  
  // game loop
  int guessesRemain = 8;
  string blank = mkShadowString(word);
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  while(guessesRemain && blank != word)
  {
    // game state
    cout << "Wrong guesses remaining: " << guessesRemain;
    cout << "\t" << alphabet << endl;
    printSpaced(blank);
    cout << endl;

    // get user input
    char inp;
    cout << ": ";
    cin >> inp;

    // update characterset
    alphabet = crossOut(inp, alphabet);

    // check word
    if(crossOut(inp, word) != word)
    {
      // ie word contained inp
      blank = uncover(word, blank, inp);
    }
    else
    {
      // was not the right letter
      guessesRemain--;
      cout << "There were no " << inp << "\'s!" << endl;
    }
  }

  // see if they won
  if(blank == word)
  {
    cout << "You win!!!! The word was " << word << endl;
  }
  else
  {
    cout << "You lose!!!! The word was " << word << endl;
  }

  return 0;
}

// print a string with spaces between the characters
void printSpaced(string s)
{
  for(int i = 0; i < s.length(); i++)
  {
    cout << s[i];
    if(i < s.length()-1) cout << " ";
  }
}

// returns a string that is the same length as "s" but is full of "_"
string mkShadowString(string s)
{
  string out = "";
  for(int i = 0; i < s.length(); i++)
    out += "_";
  return out;
}

// takes a string and if the char is in the original, replacing the letter in
// the covered at the given location
string uncover(string original, string covered, char c)
{
  string out = "";
  for(int i = 0; i < original.length(); i++)
  {
    if(original[i] == c)
      out += original[i];
    else
      out += covered[i];
  }
  return out;
}

// replaces a letter in a string with *
string crossOut(char c, string s)
{
  string out = "";

  for(int i = 0; i < s.length(); i++)
  {
    if(s[i] == c)
      out += "*";
    else
      out += s[i];
  }

  return out;
}
