/*********************************************
This program reads trial data from a roach
experiment, reads a time from the user, and
tells the user where the roach was going at
that point in time.
**********************************************/
#include <iostream>
using namespace std;

/*********************************************
 ** PROTOTYPES & STRUCT DEFINITIONS
 *********************************************/
//--- POINT ---------------------------------//
struct point
{
  double x, y;
};
istream& operator >> (istream& in, point& p);
ostream& operator << (ostream& os, point p);

//--- TIME IN HH:MM:SS ----------------------//
struct hhmmss
{
  int h,m,s;
};
istream& operator >> (istream& is, hhmmss& T);
bool operator < (hhmmss a, hhmmss b);

//--- A DATA READING FROM THE EXPERIMENT ----//
struct datum
{
  point position;
  hhmmss time;
};
istream& operator >> (istream& is, datum& D);


/*********************************************
 ** MAIN FUNCTION
 *********************************************/
int main()
{
  // Open file and read heading info
  int N;
  string s;
  ifstream fin("trial.txt");
  fin >> N >> s >> s;

  // Read and store data readings
  datum* A = new datum[N];
  for(int i = 0; i < N; i++)
    fin >> A[i]; 

  // Get the query time from the user
  hhmmss T;
  cout << "Enter a time: ";
  cin >> T; 

  // Find the first sighting at or after given time
  int k = 0; 
  while (k < N && A[k].time < T)
    k++;
  
  // Write result
  if (k == 0)
  {
    cout << "This was before the first sighting at ";
    cout << A[0].position << endl;
  }
  else if (k == N)
  {
    cout << "This was after the last sighting at ";
    cout << A[N-1].position << endl;
  }
  else
  {
    cout << "The roach was somewhere between ";
    cout << A[k-1].position << " and " << A[k].position << endl;
  }

  return 0;
}

/*********************************************
 ** DEFINITIONS 
 *********************************************/
istream& operator >> (istream& is, point &p)
{
  char c;
  return is >> c >> p.x >> c >> p.y >> c;
}

ostream& operator << (ostream& os, point p)
{
  return os << '(' << p.x << ',' << p.y << ')';
}

istream& operator >> (istream& is, hhmmss& T)
{
  char c;
  return is >> c >> T.h >> c >> T.m >> c >> T.s >> c;
}

bool operator<(hhmmss a, hhmmss b)
{
  int at = a.h*3600 + a.m*60 + a.s;
  int bt = b.h*3600 + b.m*60 + b.s;
  return at < bt; 
}

istream& operator >> (istream& is, datum& D)
{
  char c;
  return is >> c >> D.time >> c >> D.position >> c; 
}

