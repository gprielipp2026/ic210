/*
 * Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Prints out an ordered deck of cards
 */
#include <iostream>
using namespace std;

int cardvalue(int suit, int facevalue);
int* gencards();

/*
 * Suits: 1 = ♣, 2 = ♦, 3 = ♥, 4 = ♠
 * 2-10, J=11, Q=12, K=13, A=14
 */

int main()
{
  for(int suit = 1; suit <= 4; suit++)
  {
    for(int facevalue = 2; facevalue <= 14; 
            }}

  return 0;
}

int cardvalue(int suit, int facevalue)
{
    return suit*100+facevalue;
}

int* gencards()
{
  int* cards = new int[52];

  for(int suit = 1; suit <= 4; suit++)
  {
    for(int facevalue = 2; facevalue <= 14; 
            }}

}
