/*
Filename: part3.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Classifies a triangle given 3 sides
*/

#include <iostream>

using namespace std;

int main() 
{
    // variables
    float l1, l2, l3; // lengths
    float a, b, c;

    // prompt user and get input
    cout << "Enter side lengths: ";
    cin >> l1 >> l2 >> l3;

    // find a, b, c
    if (l3 > l2 && l3 > l1) 
    {
        a = l1;
        b = l2;
        c = l3;
    }
    else if (l2 > l3 && l2 > l1)
    {
        a = l1;
        b = l3;
        c = l2;
    }
    else if (l1 > l2 && l1 > l3) 
    {
        a = l2;
        b = l3;
        c = l1;
    }
    else
    {
        a = l1;
        b = l2;
        c = l3;
    }

    // lengths violate triangle
    if (a + b <= c && a != b && a != c)
    {
        cout << "Error! these lengths violate the triangle inequality!" << endl;
        return 0;
    }
    // right angle
    else if ((a*a + b*b) == (c*c))
    {
        cout << "This is a right";
    }
    // acute angle
    else if ((a*a + b*b) > (c*c))
    {
        cout << "This is a acute";
    }
    // obtuse angle
    else if ((a*a + b*b) < (c*c))
    {
        cout << "This is a obtuse";
    }

    // see what kind of triangle it is
    if (a == b && b == c)
    {
        cout << " equilateral triangle." << endl;
    }
    else if (a == b || a == c || b == c)
    {
        cout << " isosceles triangle." << endl;
    }
    else if (a + b > c && a != b && b != c)
    {
        cout << " scalene triangle." << endl;
    }

    return 0;
}