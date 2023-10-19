/* Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * read two candidate names, read bunch of votes, says who won/tied
 */ 

// hw.cpp
#include <iostream>
#include <string>
using namespace std;

// TO DO: Give function prototypes
void get_names(string* candidate1, string* candidate2);
bool update_counts(string selection, string candidate1, 
     int* count1, string candidate2, int* count2);
void display_results(string candidate1, int count1, 
                     string candidate2, int count2);


// *** DON'T CHANGE main()!! ****
int main() 
{
  string candidate1;
  string candidate2;

  get_names(&candidate1, &candidate2);

  int count1 = 0;
  int count2 = 0;

  cout << "Enter votes, ending with \"END\":" << endl;

  string selection;
  cin >> selection;
  while (update_counts(selection, candidate1, &count1, candidate2, &count2)) 
  {
    cin >> selection;
  }

  display_results(candidate1, count1, candidate2, count2);

  return 0;
}


// TO DO: Give function definitions
void get_names(string* candidate1, string* candidate2)
{
  // get names
  cout << "Candidate names: ";
  cin >> *candidate1 >> *candidate2;
}

bool update_counts(string selection, string candidate1, 
     int* count1, string candidate2, int* count2)
{
  // nothing left to count
  if(selection == "END") return false;

  // add to the corresponding counter
  if(selection == candidate1)
    (*count1)++;
  else if(selection == candidate2)
    (*count2)++;
  else
    cout << "Invalid name" << endl; 

  // keep counting
  return true;
}

void display_results(string candidate1, int count1, 
                     string candidate2, int count2)
{
  if(count1 > count2)
    cout << candidate1 << " wins with " << count1 
         << " out of " << count1 + count2 << " votes" << endl;
  else if(count2 > count1)
    cout << candidate2 << " wins with " << count2
         << " out of " << count1 + count2 << " votes" << endl;
  else if(count1 == count2)
    cout << "Tie!" << endl;
}



