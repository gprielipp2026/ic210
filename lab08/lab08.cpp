/* Filename: lab08.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * part1: writing helper functions */

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
  cout << "Testing printSpaced..." << endl;
  cout << "["; 
  printSpaced("wash"); 
  cout << "]" << endl;

  cout << "["; 
  printSpaced("HelloWorld!"); 
  cout << "]" << endl;

  

  cout << endl << "Testing mkShadowString..." << endl;
  string s1 = "food";
  string s2 = mkShadowString(s1);
  cout << "original: " << s1 << endl;
  cout << "  shadow: " << s2 << endl;
  string s3 = "require";
  string s4 = mkShadowString(s3);
  cout << "original: " << s3 << endl;
  cout << "  shadow: " << s4 << endl;

     
  cout << endl << "Testing uncover..." << endl;
  string u1 = "housepet";
  string u2 = "________";
  cout << u1 << endl << u2 << endl;
  
  string u3 = uncover(u1,u2,'e');
  if( u2 == u3 )
    cout << u3 << " there were not e's!"  << endl;
  else
    cout << u3 << " there were e's!"  << endl;
  u2 = u3;
 
  u3 = uncover(u1,u2,'q');
  if( u2 == u3 )
    cout << u3 << " there were not q's!"  << endl;
  else
    cout << u3 << " there were q's!"  << endl;

  cout << endl << "Testing crossOut..." << endl;
  string t1 = "Go get good food!";
  cout << t1 << endl;
  t1 = crossOut('o',t1);
  cout << t1 << endl;
  t1 = crossOut('g',t1);
  cout << t1 << endl;
   
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
