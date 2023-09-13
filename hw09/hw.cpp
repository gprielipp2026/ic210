/*
Filename: hw.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Finds the best student from a list of grades
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  // grade variables
  int hw, quiz, exam;
  string student, bestStudent;
  float avg, best = -10000;

  // prev variables to check input validity
  string pstudent = "";

  // get the filename for the data
  string filename;
  cout << "Filename: ";
  cin >> filename;

  // open the file
  ifstream data (filename);

  if (!data) return 1; // make sure file opened

  // read the first junk line of the file
  data >> student >> student >> student >> student; // 4 junk strings

  // loop through data
  while(data)
  {
    // get the student's data
    data >> student >> hw >> quiz >> exam;
    
    // calculate average
    avg = 0.2*hw + 0.2*quiz + 0.6*exam;
  
    // report their score to screen
    if( pstudent != student ) {
      cout << student << " " << avg << endl;
    }
  
    // save the previous data
    pstudent = student;

    // save them if they're the best
    if (avg > best)
    {
      bestStudent = student;
      best = avg;
    }
  }

  // report the best student
  cout << "The best student is " << bestStudent << "." << endl;

  return 0;
}
