#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  cout << "Filename: ";
  string fn;
  cin >> fn;

  ifstream data(fn);
  if(!data)
  {
    cout << "File not found!" << endl;
    exit(1);
  }

  string flight;
  int hrs1, hrs2, mins1, mins2;
  string longestFlight;
  int longestHr=-10000000000000, longestMin=-100000000000;
  char junk;

  while(data >> flight >> hrs1 >> junk >> mins1 >> junk >> hrs2 >> junk >> mins2)
  {
    int difHr = hrs2 - hrs1;
    int difMin = mins2 - mins1;

    if(difHr < 0)
      difHr += 24;

    if (difMin < 0)
    {
      difMin += 60;
      difHr--;
    }


    if (difHr > longestHr || (difHr == longestHr && difMin > longestMin))
    {
      longestHr = difHr;
      longestMin = difMin;
      longestFlight = flight;
    }

    cout << flight << ": " << difHr << " hours and " << difMin << " minutes" << endl;
  }

  cout << "Longest: " << longestFlight << " with " << longestHr << " hours and " << longestMin << " minutes" << endl;

  return 0;
}
