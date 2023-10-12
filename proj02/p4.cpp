/*
 * Filename: p4.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * shuffling the deck 
 */
#include <iostream>
#include <cstdlib>
using namespace std;

int cardvalue(int suit, int facevalue);
int* gencards();
void printcards(int* cards, int length);
int deal(int* index, int* cards);
void displaygame(int* player, int playerLen, int* dealer, int dealerLen);
void swap(int* a, int* b);
void shuffle(int* cards, int length);

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

  // set the seed
  srand(seed);

  // get the cards
  int* cards = gencards();
  int index = 0;
  int numCards = 52;

  // shuffle the cards
  shuffle(cards, numCards);

  // display the cards
  printcards(cards, numCards);

  // the two hands
  int* player = new int[52];
  int* dealer = new int[52];
  int numPlayerCards = 0;
  int numDealerCards = 0;

  // initialize player and dealer's hands
  for(int i = 0; i < 4; i++)
  {
    int card = deal(&index, cards);
    if(i%2)
      dealer[numDealerCards++] = card;
    else
      player[numPlayerCards++] = card;
  }

  // initial game state
  displaygame(player, numPlayerCards, dealer, numDealerCards);

  // game loop
  char cmd;
  for(int round = 1; round <= 3; round++)
  {
    // get hit or stand: player
    cout << "Round " << round << " Player's turn" << endl;
    cout << "hit or stand ? [h/s] ";
    cin >> cmd;

    if(cmd == 'h')
    {
      int card = deal(&index, cards);
      player[numPlayerCards++] = card;
    }

    displaygame(player, numPlayerCards, dealer, numDealerCards);

    // get hit or stand: dealer
    cout << "Round " << round << " Dealer's turn" << endl;
    cout << "hit or stand ? [h/s] ";
    cin >> cmd;

    if(cmd == 'h')
    {
      int card = deal(&index, cards);
      dealer[numDealerCards++] = card;
    }

    displaygame(player, numPlayerCards, dealer, numDealerCards);
  }

  // go for 3 rounds

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

// takes the top card and removes it from cards
int deal(int* index, int* cards)
{
  if(*index >= 52) return -1; // error out of here

  return cards[(*index)++];
}

void displaygame(int* player, int playerLen, int* dealer, int dealerLen)
{
  cout << endl;
  cout << "Player: ";
  printcards(player, playerLen);
  cout << "Dealer: ";
  printcards(dealer, dealerLen);
  cout << endl;
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
