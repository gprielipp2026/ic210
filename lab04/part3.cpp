/*
 *Filename: part1.cpp
  Name: MIDN GEORGE PRIELIPP (265112)
  Finds the average, min, and max temperature in fahrenheit from a .tsv file with data in celsius
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

  // get the output filename
  string outFN;
  cin >> outFN;

  // open the output file
  ofstream outData(outFN);

  // find the average temperature in fahrenheit
  double sum = 0;
  int numRows = 0;
  string date, time;

  // minimum temperature data
  double minTemp = 10000000;
  string minDate = "";

  // maximum temperature data
  double maxTemp = -10000000;
  string maxDate = "";

  // first row is unnecessary header information
  string hTime, hTemp;
  inData >> hTime >> hTemp;

  // first row output file:
  outData << "day\thour\ttemp" << endl;

  // read from the file
  double celsius;
  while((inData >> date >> time >> celsius))
  {

    // convert celsius to fahrenheight
    double fahrenheit = celsius * 9.0 / 5.0 + 32;

    // see if min/max
    if(fahrenheit < minTemp)
    {
      minTemp = fahrenheit;
      minDate = date;
    } 
    if(fahrenheit > maxTemp)
    {
      maxTemp = fahrenheit;
      maxDate = date;
    }

    // write the data to the output file
    int hour = 10*(time[0]-'0') + (time[1]-'0') + 1; // "parse" the time string
    outData << date << ' ' << hour << '\t' << fahrenheit << endl;

    sum += fahrenheit;
    numRows++;
  }

  // output data
  double avg = sum / numRows;
  
  // report data
  cout << "file: " << inFN << endl;
  cout << "ave: " << avg << endl;
  cout << "min: " << minTemp << " on " << minDate << endl;
  cout << "max: " << maxTemp << " on " << maxDate << endl;
  cout << "output in: " << outFN << endl;

  return 0;
}
