/*
 * Filename: p7.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * full game 
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <unistd.h>
using namespace std;

int cardvalue(int suit, int facevalue);
int* gencards();
void printcards(int* cards, int length);
int deal(int* length, int** cards);
void displaygame(int *player, int playerLen, int *dealer, int dealerLen, bool showFirstDealerCard);
void swap(int* a, int* b);
void shuffle(int* cards, int length);
string face(int card);
int sumhand(int* cards, int length);
int game();

/*
 * Suits: 1 = ♣, 2 = ♦, 3 = ♥, 4 = ♠
 * Face:  2-10, J=11, Q=12, K=13, A=14
 */

int main()
{
  // get and set the seed
  int seed = 1;
  char shuffleCMD;
  cout << "Shuffle: [n | u <seed>]: ";
  cin >> shuffleCMD;
  
  // see if a seed was given
  if(shuffleCMD == 'u')
  {
    cin >> seed;
  }
  srand(seed);

  // go until someone busts or wins (ie no ties)
  int result;
  while ((result = game()) == 0)
  {
  }

  // determine who won/lost
  switch (result)
  {
  case -1:
    cout << "Player busts, dealer wins" << endl;
    break;
  case -2:
    cout << "Dealer busts, player wins" << endl;
    break;
  case 1:
    cout << "Player wins" << endl;
    break;
  case 2:
    cout << "Dealer wins" << endl;
    break;
  }

  // set the seed
  srand(seed);

  return 0;
}

// how I'm defining what a card is
int cardvalue(int suit, int facevalue)
{
    return suit*100+facevalue;
}

// return the pointer to an array of 52 cards
int* gencards()
{
  int* cards = new int[52];

  // loop through all possible card values
  for(int suit = 1; suit <= 4; suit++)
  {
    for(int facevalue = 2; facevalue <= 14; facevalue++)
    {
      // can think of cards as [4][13], so need to calculate what 
      // "row" and "col" to be at 
      int idx = (suit-1)*13 + (facevalue-2);
      cards[idx] = cardvalue(suit, facevalue);
    }
  }
 
  shuffle(cards, 52);

  return cards;
}

// loop through and print the cards
void printcards(int* cards, int length)
{ 
  cout << '[';
  for(int i = 0; i < length; i++)
  {
    cout << cards[i];
    if(i+1 < length) cout << ' ';
  }
  cout << ']' << endl;
}

// takes the top card and removes it from cards
int deal(int* length, int** cards)
{
  if(*length - 1 < 0) return -1; // error out of here

  // get the top card
  int card = *cards[0];

  // clean memory and shrink deck of cards
  *cards[0] = 0;
  *cards = (*cards + 1);
  *length -= 1;

  return card;
}

void displaygame(int *player, int playerLen, int *dealer, int dealerLen, bool showFirstDealerCard)
{
  cout << endl;
  cout << " Player Dealer" << endl;
  // go row by row and print out the hands
  for(int i = 0; i < max(playerLen, dealerLen); i++)
  {
    cout << "| ";
    if(i < playerLen)
    {
      cout << face(player[i]);
    }
    else
    {
      cout << "   ";
    }
    cout << "  | ";
    if(i < dealerLen)
    {
      if ((i == 0 && showFirstDealerCard) || i > 0)
        cout << face(dealer[i]);
      else
        cout << " **";
    }
    else
    {
      cout << "   ";
    }
    cout << "  |" << endl;
  }
}

// swap two ints at their respective addresses
void swap(int* a, int* b)
{
  int tmp = *b;
  *b = *a;
  *a = tmp;
}

// shuffles a deck of cards with a given length
void shuffle(int* cards, int length)
{
  // algorithm provided by project
  for(int i = 0; i < length; i++)
  {
    int j = rand() % length;
    swap(&cards[i], &cards[j]);
  }
}

string face(int card)
{
  string out = "";
  int faceval = card % 100;
  int suit = card / 100;
  
  if(faceval >= 11)
    out += " ";

  if(faceval == 11)
    out += 'J';
  else if(faceval == 12)
    out += 'Q';
  else if(faceval == 13)
    out += 'K';
  else if(faceval == 14)
    out += 'A';
  else
  {   
    int tmp = faceval;
    // make int to string
    while(faceval > 0)
    {
      out = char('0' + faceval%10) + out;
      faceval /= 10;
    }
    if(tmp < 10)
      out = " " + out;
  }

  if(suit == 1)
    out += "\u2663";
  else if(suit == 2)
    out += "\u2666";
  else if(suit == 3)
    out += "\u2665";
  else if(suit == 4)
    out += "\u2660";

  return out;
}

int sumhand(int* cards, int length)
{
  int sum = 0;
  bool sawAce = false;
  for(int i = 0; i < length; i++)
  {
    int val = cards[i] % 100;
    if (val == 14)
      sawAce = true;
    // ace
    if(val == 14) val = 1;
    // face cards
    if(val > 10) val = 10;
    sum += val;
  }
  // aces only get counted as 11 if the total sum could potentially be 21 with two cards
  if (sawAce && sum <= 11)
    sum += 10;

  return sum;
}

/*
 * Output:  1 = player win
 *          2 = dealer win
 *          0 = tie (same scores)
 *         -1 = player bust
 *         -2 = dealer bust
 */
int game()
{
  // get the cards
  int *cards = gencards();
  int numCards = 52;

  // the two hands
  int *player = new int[52];
  int *dealer = new int[52];
  int numPlayerCards = 0;
  int numDealerCards = 0;

  // initialize player and dealer's hands
  for (int i = 0; i < 4; i++)
  {
    int card = deal(&numCards, &cards);
    if (i % 2)
      dealer[numDealerCards++] = card;
    else
      player[numPlayerCards++] = card;
  }

  // initial game state
  displaygame(player, numPlayerCards, dealer, numDealerCards, false);

  // game loop
  char cmd;
  bool playerStand = false;
  bool dealerStand = false;
  int round = 1;
  int playerSum, dealerSum;
  playerSum = sumhand(player, numPlayerCards);
  dealerSum = sumhand(dealer, numDealerCards);
  while (!(playerStand && dealerStand))
  {
    // get hit or stand: player
    cout << "Round " << round << " Player's turn" << endl;
    cout << "hit or stand ? [h/s] ";
    cin >> cmd;

    // handle player hit/stand
    if (cmd == 'h')
    {
      int card = deal(&numCards, &cards);
      player[numPlayerCards++] = card;
      playerStand = false;
    }
    else if (cmd == 's')
    {
      playerStand = true;
    }
    playerSum = sumhand(player, numPlayerCards); // used later

    // make sure I don't need to quit game
    if (dealerStand && playerStand && round > 1)
    {
      displaygame(player, numPlayerCards, dealer, numDealerCards, true);
      break;
    }
    // other instance when I could need to quit
    if (dealerSum > 21 || playerSum > 21)
    {
      // bust
      displaygame(player, numPlayerCards, dealer, numDealerCards, true);
      break; // get out of loop
    }
    // display changes made by player
    displaygame(player, numPlayerCards, dealer, numDealerCards, false);

    // get hit or stand: dealer
    cout << "Round " << round << " Dealer's turn" << endl;
    cout << "hit or stand? [h/s] ";

    // decide dealer's move
    dealerSum = sumhand(dealer, numDealerCards); // used later
    if (dealerSum < 17)
      cmd = 'h';
    else
      cmd = 's';
    // pause for dramatic effect
    sleep(1);

    cout << cmd << endl;

    // handle dealer's choice
    if (cmd == 'h')
    {
      int card = deal(&numCards, &cards);
      dealer[numDealerCards++] = card;
      dealerStand = false;
    }
    else if (cmd == 's')
    {
      dealerStand = true;
    }
    // recalculate to make sure I didn't bust
    dealerSum = sumhand(dealer, numDealerCards); // used later

    if (dealerSum > 21 || playerSum > 21)
    {
      // bust
      displaygame(player, numPlayerCards, dealer, numDealerCards, true);
      break; // get out of loop
    }

    displaygame(player, numPlayerCards, dealer, numDealerCards, dealerStand && playerStand);

    round++;
  }

  // check game state:
  // draw
  if (playerSum == dealerSum)
    return 0;
  // player bust condition
  else if (playerSum > 21)
    return -1;
  // dealer bust
  else if (dealerSum > 21)
    return -2;
  // check player win condition
  else if (playerSum == 21 || playerSum > dealerSum)
    return 1;
  // dealer win
  else if (dealerSum == 21 || dealerSum > playerSum)
    return 2;
  // gets rid of compiler warnings
  else
    return 3; // I messed up if we get here :D
}
