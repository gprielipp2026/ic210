/* p2.cpp
 * GEORGE PRIELIPP
 * something with fruit and prices */
#include <iostream>
#include <fstream>
using namespace std;

struct Market
{
  string name;
  double price;
};

istream& operator>>(istream& is, Market& market);
void add(Market* market, int mktLen, double& bill, double amount, string name);
void price(Market* market, int mktLen, string name);

int main()
{
  // get the fn and open the file
  string fn;
  cout << "Filename: ";
  cin >> fn;

  ifstream file(fn);

  // error chekc file
  if(!file)
  {
    cout << "File not found!" << endl;
    exit(1);
  }

  // read len and create the market*
  int mktLen;
  string junk;
  file >> mktLen >> junk;

  Market* market = new Market[mktLen];

  // read the market in
  for(int i = 0; i < mktLen; i++)
    file >> market[i];

  // ring up the customer
  double bill = 0;
  string cmd;
  while(cout << "command: " && cin >> cmd && cmd != "checkout")
  {
    if(cmd == "add")
    {
      double amt;
      string name;
      cin >> amt >> junk >> name;

      add(market, mktLen, bill, amt, name);
    }
    else if(cmd == "price")
    {
      string name;
      cin >> name;

      price(market, mktLen, name);
    }
  }

  cout << "total is $" << bill << endl;

  //free memory
  delete[] market;

  return 0;
}

istream& operator>>(istream& is, Market& market)
{
  char dollar;
  is >> market.name >> dollar >> market.price;

  return is;
}

void add(Market* market, int mktLen, double& bill, double amount, string name)
{
  // find the price to charge
  for(int i = 0; i < mktLen; i++)
  {
    // charge the price
    if(market[i].name == name)
    {
      bill += amount * market[i].price;
      return;
    }
  }
  // did not find it
  cout << "Error! " << name << " not found!" << endl;
}

void price(Market* market, int mktLen, string name)
{
  // find the price to print
  for(int i = 0; i < mktLen; i++)
  {
    // print the price
    if(market[i].name == name)
    {
      cout << market[i].name << " are $" << market[i].price << " per pound" << endl;
      return;
    }
  }
  // did not find it
  cout << "Error! " << name << " not found!" << endl;
}

