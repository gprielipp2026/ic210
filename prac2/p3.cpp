/* p3.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * avenues, streets, and car crashes */
#include <iostream>
using namespace std;

int** getroads(int* streets, int* avenue); // read in the "<n> streets, <x> avenues" 
                  // street = row
                  // avenue = col
void crash(int** roads, int street, int avenue);
void print(int** roads, int streets, int avenues);

int main()
{
  // get roads
  int streets, avenues;
  int** roads = getroads(&streets, &avenues);

  // handle commands
  string cmd;
  while(cout << "> " && cin >> cmd && cmd != "quit")
  {
    if(cmd == "crash")
    {
      int s, a;
      string word;
      cin >> s >> word >> word >> a >> word;
      crash(roads, s, a);
      print(roads, streets, avenues);
    }
  }

  // delete roads
  for(int i = 0; i < streets; i++)
    delete[] roads[i];
  delete[] roads;

  return 0;
}

int** getroads(int* streets, int* avenue)
{
  string word;
  cin >> *streets >> word >> *avenue >> word;

  int** roads = new int*[*streets];
  for(int i = 0; i < *streets; i++)
  {
    roads[i] = new int[*avenue];
    for(int j = 0; j < *avenue; j++)
    {
      cin >> roads[i][j];
    }
  }

  return roads;
}

void crash(int** roads, int street, int avenue)
{
  roads[street][avenue]++;
}

void print(int** roads, int streets, int avenues)
{
  for(int i = 0; i < streets; i++)
  {
    for(int j = 0; j < avenues; j++)
    {
      cout << roads[i][j];
      if(j < avenues - 1)
        cout << " ";
    }
    cout << endl;
  }
}
