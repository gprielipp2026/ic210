/* Filename: lab.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * answers questions about movies and users until user enters quit
 */
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_USERS 610
#define MAX_MOVIES 9724

void get_averages(double*& movieAvgs, double*& userAvgs);

int main()
{
  // load the data
  double* movieAvgs;
  double* userAvgs;
  get_averages(movieAvgs, userAvgs);

  // get the command
  string cmd;
  while (cin >> cmd && cmd != "quit")
  {
    // "id"
    int id;
    cin >> id;

    // case movie average
    if(cmd == "movie")
    {
      cout << movieAvgs[id] << endl;
    }
    // case user average  
    else if (cmd == "user")
    {
      cout << userAvgs[id] << endl;
    }
  }

  // unload the data from memory
  // delete [] ...
  delete [] movieAvgs;
  delete [] userAvgs;

  return 0;
}

/* output: 
 * stores the average rating of a given movie based on how many users have watched that given movie
 */
void get_averages(double*& movieAvgs, double*& userAvgs)
{
  movieAvgs = new double[MAX_MOVIES];
  userAvgs = new double[MAX_USERS];
  int* movieCount = new int[MAX_MOVIES];
  int* userCount = new int[MAX_USERS];
  
  // initialize values to 0
  for(int i = 0; i < MAX_USERS; i++)
  {
    userAvgs[i] = 0;
    userCount[i] = 0;
  }
  for(int i = 0; i < MAX_MOVIES; i++)
  {
    movieAvgs[i] = 0;
    movieCount[i] = 0;
  }

  // open the file to read from
  ifstream data("ratings.tsv");
  if(!data)
  {
    cerr << "Couldn't open ratings.tsv" << endl;
    exit(1);
  }

  // read file header (junk to us)
  string str;
  data >> str >> str >> str;

  // sum up the ratings and counts
  int userId, movieId;
  double rating;
  while(data >> userId >> movieId >> rating)
  {
    movieAvgs[movieId] += rating;
    userAvgs[userId] += rating;

    movieCount[movieId]++;
    userCount[userId]++;
  }

  // take the averages
  for(int i = 0; i < MAX_USERS; i++)
  {
    // don't divide by zero
    if(userCount[i])
    {
      userAvgs[i] /= userCount[i];
    }
  }
  for(int i = 0; i < MAX_MOVIES; i++)
  {
    // don't divide by zero
    if(movieCount[i])
    {
      movieAvgs[i] /= movieCount[i];
    }
  }

  // free up the memory taken for the counts
  delete [] userCount;
  delete [] movieCount;
}
