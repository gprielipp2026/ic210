/*
 * Filename: p6.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * scores 
 */
#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

int cardvalue(int suit, int facevalue);
int* gencards();
void printcards(int* cards, int length);
int deal(int* length, int** cards);
void displaygame(int* player, int playerLen, int* dealer, int dealerLen);
void swap(int* a, int* b);
void shuffle(int* cards, int length);
string face(int card);
int sumhand(int* cards, int length);

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
  int numCards = 52;

  // shuffle the cards
  shuffle(cards, numCards);

  // the two hands
  int* player = new int[52];
  int* dealer = new int[52];
  int numPlayerCards = 0;
  int numDealerCards = 0;

  // initialize player and dealer's hands
  for(int i = 0; i < 4; i++)
  {
    int card = deal(&numCards, &cards);
    if(i%2)
      dealer[numDealerCards++] = card;
    else
      player[numPlayerCards++] = card;
  }

  // initial game state
  displaygame(player, numPlayerCards, dealer, numDealerCards);

  // game loop
  char cmd;
  bool playerStand = false, dealerStand = false;
  int round = 1;
  while(!(playerStand && dealerStand)){
    // get hit or stand: player
    cout << "Round " << round << " Player's turn" << endl;
    cout << "hit or stand ? [h/s] ";
    cin >> cmd;

    if(cmd == 'h')
    {
      int card = deal(&numCards, &cards);
      player[numPlayerCards++] = card;
      playerStand = false;
    } 
    else
    {
      playerStand = true;
    }

    displaygame(player, numPlayerCards, dealer, numDealerCards);

    // make sure I don't need to quit game
    if(playerStand && dealerStand) break;

    // get hit or stand: dealer
    cout << "Round " << round << " Dealer's turn" << endl;
    cout << "hit or stand ? [h/s] ";
    cin >> cmd;

    if(cmd == 'h')
    {
      int card = deal(&numCards, &cards);
      dealer[numDealerCards++] = card;
      dealerStand = false;
    }
    else
    {
      dealerStand = true;
    }

    displaygame(player, numPlayerCards, dealer, numDealerCards);

    round++;
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

void displaygame(int* player, int playerLen, int* dealer, int dealerLen)
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
      cout << "  ";
    }
    cout << "  | ";
    if(i < dealerLen)
    {
      cout << face(dealer[i]);
    }
    else
    {
      cout << "  ";
    }
    cout << "  |" << endl;
  }
  // print out the sum of the hands
  cout << "Player " << sumhand(player, playerLen) << ", ";
  cout << "Dealer " << sumhand(dealer, dealerLen) << endl;
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
    if(val == 14)
    {
      sawAce = true;
      val = 1;
    }
    if(val > 10) val = 10;
    sum += val;
  }
  // aces only get counted as 11 if the total sum could potentially be 21 with two cards
  if(sawAce && sum <= 11)
    sum += 10;

  return sum;
}
