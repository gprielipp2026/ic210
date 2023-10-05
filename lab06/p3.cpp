/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * simulates Craps played between the player (user) 
 * and the house (program) with additional rules
 */
#include <cstdlib>
#include <iostream>
using namespace std;

int rolldie();
int throwdice(int);
void playgame();
bool playagain();

int main()
{
  // seed rand
  int seed;
  cout << "Enter seed value: ";
  cin >> seed;
  srand(seed);
  
  // go until user doesn't want to play again
  do {
    playgame();
  } while(playagain());

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

/*
 * Output:  house wins = -1
 *          player wins = 0
 *          draw = sum of dice
 */
int throwdice(int setpoint)
{
  // dice
  int d1 = rolldie();
  int d2 = rolldie();
  int sum = d1 + d2;

  cout << "Player rolled " << d1 << " + " << d2 << " = " << sum;

  // craps rules
  if((sum == 7 || sum == 11) && setpoint == 0) return 0; // player wins
  if( sum == setpoint ) return 0; // player wins
  if((sum == 2 || sum == 3 || sum == 12) && setpoint == 0) return -1; // house wins
  if( setpoint > 0 && (sum == 7 || sum == 12)) return -1; // house wins
  else return sum; // neither won
}

void playgame()
{
  // var for the current sum of the game (ie each round)
  int game;
  int setpoint = 0;
  while( (game = throwdice(setpoint) > 0 ) {
    // neither house nor player have won
    cout << " roll again" << endl;

    // this means that the setpoint is in 4,5,6,8,9,10
    if(setpoint == 0) setpoint = game;
  }

  // determine who won
  if(game == -1)
    cout << " House wins!" << endl;
  else
    cout << " Player wins!" << endl;
}

bool playagain()
{
  char yORn;
  cout << "Play again? ";
  cin >> yORn;
  return yORn == 'y';
}
