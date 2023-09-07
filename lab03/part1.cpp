/*
Filename: part1.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Creates a bounding box for a given triangle in a format suitable for GNUPLOT
*/

#include <iostream>

using namespace std;

int main()
{
    // variables
    float minx = 100000, maxx = -100000, miny = 100000, maxy = -100000; // bounding box vars
    float xin, yin;
    char junkin; // input junk '(' ')' and ','
    int counter = 3;

    float tx1,ty1 , tx2,ty2 , tx3,ty3; // triangle points

    // read in three points
    while (counter-- > 0)
    {
        cin >> junkin >> xin >> junkin >> yin >> junkin; // (#,#)

        // save triangle points
        switch (counter) 
        {
            case 2:
                tx1 = xin;
                ty1 = yin;
                break;
            case 1:
                tx2 = xin;
                ty2 = yin;
                break;
            case 0:
                tx3 = xin;
                ty3 = yin;
    // default
        }

        // find min/max for x and y
        if (xin > maxx) maxx = xin;
        else if (xin < minx) minx = xin;

        if (yin > maxy) maxy = yin;
        else if (yin < miny) miny = yin;
    }

    // output 5 points for the box (start - middle - back to start)
    cout << minx << " " << miny << endl; // bottom left
    cout << minx << " " << maxy << endl; // top left
    cout << maxx << " " << maxy << endl; // top right;
    cout << maxx << " " << miny << endl; // bottom right
    cout << minx << " " << miny << endl; // bottom left

    // formatting
    cout << endl;

    // output the triangle (4 points)
    cout << tx1 << " " << ty1 << endl;
    cout << tx2 << " " << ty2 << endl;
    cout << tx3 << " " << ty3 << endl;
    cout << tx1 << " " << ty1 << endl;

    return 0;
}