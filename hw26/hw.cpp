/* Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * tracks a car moving through the world with a velocity and position */
#include <iostream>
#include <fstream>
using namespace std;

struct car {
  char name;
  double pos;
  double vel;
};

void updatecars(car*,int, int);
void printcar(car);
void printcars(car*, int, int);
car* readcars(ifstream&, int&);

int main()
{
  // get the file to open
  string fn;
  cin >> fn;

  // open the file and check if its open
  ifstream fin(fn);
  if(!fin)
  {
    cout << "File didn't open" << endl;
    return -1;
  }
  
  // get the cars
  int numCars;
  car* cars = readcars(fin, numCars);

  // drive the cars for 8 hours
  for(int hour = 0; hour <= 8; hour++)
  {
    printcars(cars, hour, numCars);
    updatecars(cars, 1, numCars);
  }

  // clean the memory
  delete [] cars;
}

void updatecars(car* cars, int hoursDriven, int numCars)
{
  // update the cars by their velocity and time driven since last update
  for(int i = 0; i < numCars; i++)
  {
    cars[i].pos += cars[i].vel * hoursDriven;
  }
}

void printcar(car _car)
{
  cout << "[" << _car.name << ":" << _car.pos << "]";
}

void printcars(car* cars, int hour, int numCars)
{
  cout << "hour " << hour << " ";
  for(int i = 0; i < numCars; i++)
  {
    printcar(cars[i]);
  }
  cout << endl;
}

car* readcars(ifstream& fin, int& len)
{
  // read N
  char c;
  fin >> c >> c >> len;

  // read cars
  car* cars = new car[len];
  string str;
  for(int i = 0; i < len; i++)
  {
    fin >> cars[i].name >> str >> cars[i].pos >> str >> cars[i].vel;
  }

  return cars;
}
