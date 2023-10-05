/*
 * Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Prints out an ordered deck of cards
 */
#include <iostream>
using namespace std;

int cardvalue(int suit, int facevalue);
int* gencards();
void printcards(int* cards);

/*
 * Suits: 1 = ♣, 2 = ♦, 3 = ♥, 4 = ♠
 * Face:  2-10, J=11, Q=12, K=13, A=14
 */

int main()
{
  // get the cards
  int* cards = gencards();

  // display the deck
  printcards(cards, 52);  

  // remove cards from memory
  delete [] cards;

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
