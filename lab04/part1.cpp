/*
 *Filename: part1.cpp
  Name: MIDN GEORGE PRIELIPP (265112)
  Finds the average temperature in fahrenheit from a .tsv file with data in celsius
 */

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // get the input filename
  string inFN;
  cin >> inFN;

  // open the input file
  ifstream inData(inFN);

  if (!inData)
  {
    cout << "Could not open file '" << inFN << "'" << endl;
    return 1;
  }

  // find the average temperature in fahrenheit
  double sum = 0;
  int numRows = 0;
  string pdate="",date, ptime="", time;

  // first row is junk
  string junk;
  inData >> junk >> junk;

  // read from the file
  while(inData)
  {
    double celsius;
    inData >> date >> time >> celsius;

    if(date == pdate && time == ptime) break;

    // convert celsius to fahrenheight
    double fahrenheit = celsius * 9.0 / 5.0 + 32;

    sum += fahrenheit;
    numRows++;
    pdate = date;
    ptime = time;
  }

  // output data
  double avg = sum / numRows;
  
  // report data
  cout << "file: " << inFN << endl;
  cout << "ave: " << avg << endl;

  return 0;
}
