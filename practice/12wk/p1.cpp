/* Filename: p1.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * counts how many zeros, negatives, and positives there are, then outputs the
 * positives in the order they were entered*/
#include <iostream>
using namespace std;

int main()
{
  // read in the num of values
  int numVals;
  char colon;
  cin >> numVals >> colon;

  // create the array
  int* positives = new int[numVals];
  int zero = 0, neg = 0, pos = 0;

  // read in the values
  for(int i = 0; i < numVals; i++)
  {
    int num;
    cin >> num;
    if(num == 0) zero++;
    if(num < 0) neg++;
    if(num > 0) positives[pos++] = num;
  }

  // display calculations
  cout << "#zeros = " << zero;
  cout << ", #negatives = " << neg;
  cout << ", #positives = " << pos << endl;

  // display positives
  cout << "Positives =";
  for(int i = 0; i < pos; i++)
    cout << " " << positives[i];
  cout << endl;

  // free memeory
  delete [] positives;
  return 0;
}
