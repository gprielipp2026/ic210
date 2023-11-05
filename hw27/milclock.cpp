#include <iostream>
using namespace std;

struct Clock
{
  int hrs;
  int mins;

  Clock(int hr, int min)
  {
    this->hrs = hr;
    this->mins = min;
  }

  Clock operator+(Clock& other)
  {
    return Clock( (hrs + other.hrs + ((mins+other.mins) >= 60 ? 1:0) ) % 24, (mins + other.mins) % 60);
  }

  Clock operator++(int a)
  {
    hrs = (hrs + (mins+1 == 60)) % 24;
    mins = (mins + 1) % 60;
    return *this;
  }

  bool operator==(string repr)
  {
    // repr: "hh:mm"
    int hrs = 10*(repr[0]-'0') + (repr[1]-'0');
    int mins = 10*(repr[3]-'0') + (repr[4]-'0');
    return (this->hrs == hrs) && (this->mins == mins);
  }

  friend ostream& operator<<(ostream& out, Clock c)
  {
    if(c.hrs < 10)
      out << "0";
    out << c.hrs << ":";
    if(c.mins < 10)
      out << "0";
    out << c.mins;
    return out;
  }

};

int main()
{
  Clock c = Clock(0, 1);

  while(!(c == "00:00"))
  {
    cout << c << endl;
    c++;
  }

  return 0;
}
