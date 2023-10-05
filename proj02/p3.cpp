/*
 * Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Simulates dealing cards 
 */
#include <iostream>
using namespace std;

int cardvalue(int suit, int facevalue);
int* gencards();
void printcards(int* cards, int length);
string command();
int deal(int* length, int** cards);

/*
 * Suits: 1 = ♣, 2 = ♦, 3 = ♥, 4 = ♠
 * Face:  2-10, J=11, Q=12, K=13, A=14
 */

int main()
{
  // get the cards
  int* cards = gencards();
  int numCards = 52;

  // display the cards
  printcards(cards, numCards);

  // the two hands
  int* player = new int[52];
  int* dealer = new int[52];
  int numPlayerCards = 0;
  int numDealerCards = 0;

  // get the next command
  string cmd;
  while((cmd = command()) != "quit")
  {
    // is it a player command
    if(cmd[cmd.size()-1] == 'p')
    {
      // deal
      if(cmd[0] == 'd')
      {
        int card = deal(&numCards, &cards);
        player[numPlayerCards++] = card;
      }
      // or print
      else if(cmd[0] == 'p')
      {
        printcards(player, numPlayerCards);
      }
    }
    // or a dealer command
    else if(cmd[cmd.size()-1] == 'd')
    {
      // deal
      if(cmd[0] == 'd')
      {
        int card = deal(&numCards, &cards);
        dealer[numDealerCards++] = card;
      }
      // or print
      else if (cmd[0] == 'p')
      {
        printcards(dealer, numDealerCards);
      }
    }
  }

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

// get the next command
string command()
{
  string cmd;
  cout << "> ";
  cin >> cmd;
  return cmd;
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
