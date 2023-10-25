/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Sorts a list of colors by brightness or alphabetically (if same brightness)
 * from a given file*/
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct Color 
{ 
  int r;
  int b;
  int g;
  int bright; // 0-765 (255*3)
  string name;
  string hex;
};

Color getColor(ifstream& fin);

int main()
{
  // open file
  string fn;
  cout << "> ";
  cin >> fn;
  ifstream fin(fn);
  if(!fin)
  {
    cerr << fn << " is not a valid filepath." << endl;
    return -1;
  }

  // read in num colors
  int N;
  char c;
  fin >> c >> c >> N;

  vector<Color> colors; 
  // read all the colors
  for(int i = 0; i < N; i++)
  {
    colors.push_back( getColor(fin) );
  }

  // sort the stuff
  auto func = [=](Color a, Color b)
  {
    if(a.bright == b.bright)
    {
      return a.name < b.name;
    }
    return a.bright > b.bright;
  };
  sort(colors.begin(), colors.end(), func);

  // print sorted colors
  for(int i = 0; i < N; i++)
  {
    Color c = colors[i];
    cout << c.name << " " << c.r << "," << c.b << "," << c.g;
    cout << " " << c.hex << endl;
  }

  return 0;
}

// read a color value from the given ifstream
Color getColor(ifstream& fin)
{
  Color c;
  char junk;
  fin >> c.name >> c.r >> junk >> c.b >> junk >> c.g >> c.hex;
  c.bright = c.r + c.b + c.g;
  return c;
}
