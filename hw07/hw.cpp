/*
    Filename: hw.cpp
    Name: MIDN GEORGE PRIELIPP (265112)
    Figure out how many days it takes you to eat a given amount of cookies
*/

#include <iostream>

using namespace std;

int main()
{
    // variables
    int ttlCookies, numCookies, maxCookies = 0, dayCookies, numDays = 0;

    // get cookie input
    cout << "How many cookies? ";
    cin >> numCookies;
    ttlCookies = numCookies;

    // how many did you eat today?
    while (numCookies > 0) 
    {
        cout << "Cookies eaten on day " << ++numDays << ": ";
        cin >> dayCookies;

        if (dayCookies > maxCookies) maxCookies = dayCookies;

        numCookies -= dayCookies;
    }

    // report days taken and max cookies eaten
    if(numCookies == 0)
    {
        cout << "You ate " << ttlCookies << " cookies over " << numDays << " days." << endl;
        cout << "On your piggiest day you ate " << maxCookies << " cookies." << endl;
    }
    // unless you ate "too many"
    else
    {
        cout << "Not enough cookies!" << endl;
    }
    
    return 0;
}