/* Filename: lab.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * answers questions about movies and users until user enters quit
 */
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_USERS 610
#define MAX_MOVIES 9724

double** get_data();
double useravg(double**, int);
double movieavg(double**, int);

int main()
{
  // load the data
  double** data = get_data();

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
      cout << movieavg(data, id) << endl;
    }
    // case user average  
    else if (cmd == "user")
    {
      cout << useravg(data, id) << endl;
    }
  }

  // unload the data from memory
  // delete [] ...
  for(int i = 0; i < MAX_USERS; i++)
    delete [] data[i];
  delete [] data;

  return 0;
}

/* read from ratings.tsv and store the data */
double** get_data()
{
  // initialize the array
  double** array = new double*[MAX_USERS];
  for(int i = 0; i < MAX_USERS; i++)
  {
    array[i] = new double[MAX_MOVIES];
    for(int j = 0; j < MAX_MOVIES; j++)
    {
      array[i][j] = 0.0;
    }
  }

  // open the file
  ifstream data("ratings.tsv");
  if(!data)
  {
    cerr << "ratings.tsv did not open" << endl;
    exit(1);
  }

  // read first line of file
  string s;
  data >> s >> s >> s;

  // loop through and read the data
  int userID, movieID;
  double rating;
  while(data >> userID >> movieID >> rating)
  {
    array[userID][movieID] = rating;
  }

  return array;
}

// take the average rating of a given user
double useravg(double** data, int id)
{
  int count = 0;
  double sum = 0.0;
  for(int i = 0; i < MAX_MOVIES; i++)
  {
    if(data[id][i])
    {
      count++;
      sum += data[id][i];
    }
  }
  return sum / count;
}

// take the average rating of a given movie
double movieavg(double** data, int id)
{
  int count = 0;
  double sum = 0.0;
  for(int i = 0; i < MAX_USERS; i++)
  {
    if(data[i][id])
    {
      count++;
      sum += data[i][id];
    }
  }
  return sum / count;
}
