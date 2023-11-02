/* hw.cpp
 * MIDN GEORGE PRIELIPP (265112)
 * performs the dot product
 */

// ADD code necessary.
// Do NOT delete any code.
#include <iostream>
using namespace std;

struct Point3
{
  double x, y, z;
  
  friend istream& operator>>(istream& in, Point3& p)
  {
    char junk;
    // (x, y, z)
    in >> junk >> p.x >> junk >> p.y >> junk >> p.z >> junk;
    return in;
  }

  friend ostream& operator<<(ostream& out, Point3& p)
  {
    out << "(" << p.x << ", " << p.y << ", " << p.z << ")";
    return out;
  }

  int operator*(Point3& b)
  {
    return this->x*b.x + this->y*b.y + this->z*b.z;
  }
};


int main()
{
  Point3 a, b;

  cin >> a >> b;

  cout << "Inner product of " << a << " and " << b
       << " is " << a*b << endl;

  return 0;
} 
