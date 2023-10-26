/* p3.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * performs bank transactions */
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct client
{
  int id;
  string fName;
  string lName;
  double balance;

  friend istream& operator>>(istream& in, client& c) {
    char dollar;
    in >> c.id >> c.fName >> c.lName >> dollar >> c.balance;
    return in;
  }

  friend ostream& operator<<(ostream& out, client& c)
  {
    out << c.id << " " << c.fName << " " << c.lName << " $" << c.balance;
    return out;
  }
};

int main()
{
  map<int, client> bank;

  // open the file
  string fn;
  cin >> fn;
  ifstream data(fn);
  if(!data)
  {
    cerr << "couldn't open \'" << fn << "\'" << endl;
    return 1;
  }
  // read header
  int numClients;
  string accounts;
  data >> numClients >> accounts;

  // parse data
  client c;
  while(data >> c)
  {
    bank[c.id] = c;
  }

  // handle the commands
  string cmd, to;
  char dollar;
  int acctNum, amount, acct1, acct2;
  while(true)
  { 
    cin >> cmd;

    // show
    if(cmd == "show")
    {
      cout << "> ";
      cin >> acctNum;
      if(!bank.count(acctNum)) cout << "Error!" << endl;
      else cout << bank[acctNum] << endl;
    }

    // transfer
    else if(cmd == "transfer")
    {
      cin >> dollar >> amount >> acct1 >> to >> acct2;
      if(!bank.count(acct1)) cout << "Error!" << endl;
      if(!bank.count(acct2)) cout << "Error!" << endl;
      if(bank.count(acct1) && bank.count(acct2))
      {
        // will bankrupt?
        if(amount > bank[acct1].balance)
        {
          cout << bank[acct1].fName << " " << bank[acct1].lName << " is bankrupt!" << endl;
          break;
        }
        else
        {
          bank[acct1].balance -= amount;
          bank[acct2].balance += amount;
        }
      }
    }
  }

  return 0;
}
