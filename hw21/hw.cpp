/* Filename: hw.cpp
 * Name: MIDN GEORGE PRIELPP (265112)
 * takes series of flights and prints the reverse journey
 */
#include <iostream>
using namespace std;

void reverse(string* airports, int numStops);
void totalTime(int* times, int numStops);

int main()
{
  // get number of legs of trip
  int numStops;
  cout << "How many legs? ";
  cin >> numStops;
  
  // airports
  string* airports = new string[numStops+1];
  int* times = new int[numStops]; // stored in minutes

  // read the legs
  for(int stop = 0; stop < numStops; stop++)
  {
    int hours,minutes;
    char colon;
    string leg, city1, city2;
    cin >> leg >> hours >> colon >> minutes;

    city1 = leg.substr(0,3);
    city2 = leg.substr(5,7);

    // make sure they're continuous legs
    if(stop >= 1 && airports[stop] != city1)
    {
      cout << "city mismatch" << endl;
      return -1;
    }

    // save the airports
    airports[stop] = city1;
    airports[stop+1] = city2;

    // save the flight time
    times[stop] = hours*60 + minutes;
  }

  // print reverse trip
  cout << "Reverse trip: ";
  reverse(airports, numStops+1);
  for(int i = 0; i < numStops; i++)
  {
    cout << airports[i] << "->";
  }
  cout << airports[numStops] << endl;

  // and total time it will take
  totalTime(times, numStops);

  return 0;
}

void reverse(string* airports, int numStops)
{
  for(int i = 0; i < numStops/2; i++)
  {
    string temp = airports[i];
    airports[i] = airports[numStops-i-1];
    airports[numStops-i-1] = temp;
  }
}

void totalTime(int* times, int numStops)
{
  int sum = 0;
  for(int i = 0; i < numStops; i++)
    sum += times[i];
  cout << "Total time: " << sum / 60 << " hours " << sum % 60 << " minutes" << endl;
}
