/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * simulates Craps played between the player (user) and the house (program) 
 */
#include <cstdlib>
#include <iostream>
using namespace std;

int rolldie();
int throwdice();

int main()
{
  // seed rand
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);
  
  // var for the current sum of the game (ie each round)
  int game;   
  while( (game = throwdice()) > 0 ) {
    // neither house nor player have won
    cout << " roll again" << endl;
  }  

  // determine who won
  if(game == -1)
  {
    // house won
    cout << " House wins!" << endl;
  }
  else
  {
    // player won
    cout << " Player wins!" << endl;
  }


  return 0;
}

int rolldie()
{
  int die;

  do {
    // this more evenly distrubutes 1-6 than rand()%6 would
    die = rand() % 8;
  } while(die == 0 || die == 7);

  return die;
}

/*
 * Output:  house wins = -1
 *          player wins = 0
 *          draw = sum of dice
 */
int throwdice()
{
  // dice
  int d1 = rolldie();
  int d2 = rolldie();
  int sum = d1 + d2;

  cout << "Player rolled " << d1 << " + " << d2 << " = " << sum;

  // craps rules
  if(sum == 7 || sum == 11) return 0; // player wins
  if(sum == 2 || sum == 3 || sum == 12) return -1; // house wins
  else return sum; // neither won
}
