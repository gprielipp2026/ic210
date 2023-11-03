/* hw.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * allows to search through different sections by different criteria */
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Section 
{
  string name;
  int id;
  uint8_t days; // 000FRWTM access by (1 << (day)) & days
  string dayStr;
  // get the shift index for creating days
  int getShift(char day)
  {
    int num = -1;
    switch(day)
    {
      case 'M':
        num = 0;
        break;
      case 'T':
        num = 1;
        break;
      case 'W':
        num = 2;
        break;
      case 'R':
        num = 3;
        break;
      case 'F':
        num = 4;
        break;
    }
    return num;
  }
  
  // figure out if this section meets on a given day
  bool meetsOnDay(char day)
  {
    uint8_t num = 1;
    switch(day)
    {
      case 'M':
        num = 1 << 0;
        break;
      case 'T':
        num = 1 << 1;
        break;
      case 'W':
        num = 1 << 2;
        break;
      case 'R':
        num = 1 << 3;
        break;
      case 'F':
        num = 1 << 4;
        break;
    }
    return (days & num) > 0;
  }

  // input
  friend istream& operator>>(istream& in, Section& s)
  {
    in >> s.name >> s.id >> s.dayStr;

    // parse the dayStr
    for(int i = 0; i < s.dayStr.length(); i++)
    {
      int shift = s.getShift(s.dayStr[i]);
      if(shift >= 0)
      {
        s.days += (1 << shift);
      }
    }

    return in;
  }
  // output
  friend ostream& operator<<(ostream& out, Section& s)
  {
    out << s.name << " " << s.id << " " << s.dayStr;

    return out;
  }
};

Section* read(ifstream* fin, int* n);
void searchByCourse(Section* sections, int n);
void searchBySection(Section* sections, int n);
void searchByDay(Section* sections, int n);

int main()
{
  string fname;
  cout << "Filename: ";
  cin >> fname;
  ifstream fin(fname);

  int n;
  Section* sections = read(&fin, &n);

  string cmd;
  cout << "> ";
  while( (cin >> cmd) && (cmd != "quit") )
  {
    if( cmd == "course" )
      searchByCourse(sections, n);
    else if ( cmd == "section" )
      searchBySection(sections, n);
    else if ( cmd == "day" )
      searchByDay(sections, n);

    cout << endl << "> ";
  }


  delete [] sections;
  return 0;
}

Section* read(ifstream* fin, int* n)
{
  // read in n
  char N;
  *fin >> N >> N >> *n;

  // create the sections
  Section* sections = new Section[*n];

  // read the sections
  for(int i = 0; i < *n; i++)
  {
    *fin >> sections[i];
  }

  return sections;
}

void searchByCourse(Section* sections, int n)
{
  // get the course to search for
  string course;
  cin >> course;

  // search and print as we go
  for(int i = 0; i < n; i++)
  {
    if(sections[i].name == course)
    {
      cout << sections[i] << endl;
    }
  }
}

void searchBySection(Section* sections, int n)
{
  // get the section to search for
  int section;
  cin >> section;

  // search and print as we go
  for(int i = 0; i < n; i++)
  {
    if(sections[i].id == section)
    {
      cout << sections[i] << endl;
    }
  }
}

void searchByDay(Section* sections, int n)
{
  // get the day to search for
  char day;
  cin >> day;

  // search and print as we go
  for(int i = 0; i < n; i++)
  {
    if(sections[i].meetsOnDay(day))
    {
      cout << sections[i] << endl;
    }   
  }
}
