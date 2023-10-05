/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * simulates a single roll of a 6 sided die
 */
#include <cstdlib>
#include <iostream>
using namespace std;

int rolldie();

int main()
{
  // seed rand
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);
  
  // dice
  int d1, d2;
  // max rounds to be played
  int ROUNDS = 5;

  for(int round = 0; round < ROUNDS; round++)
  {
    // roll die and print sum to screen
    d1 = rolldie();
    d2 = rolldie();

    cout << "Player rolled " << d1 << " + " << d2 << " = " << d1+d2 << endl;
  }

  return 0;
}

int rolldie()
{
  int die;

  do {
    // this more evenly distrubutes 1-6 than rand()%6 would
    die = (rand() % 8) + 1; // 1-8
  } while(die > 6);

  return die;
}
