#include <iostream>
using namespace std;

string clean(int num) 
{
    string out;
    out += '0' + (num / 10);
    out += '0' + (num % 10);
    return out;
}

int main()
{
    int hr,mins;
    char colon;
    string pm;

    cout << "Enter time in HH:MMAM (or PM if it's PM): ";
    cin >> hr >> colon >> mins >> pm;

    if (pm == "PM")
    {
        if (hr == 12)
        {
            cout << "12:" << clean(mins) << endl;
        } else
        {
            cout << clean(hr+12) << ":" << clean(mins) << endl;
        }
    } else if (pm == "AM") 
    {
        if (hr == 12)
        {
            cout << "00:" << clean(mins) << endl;
        } else
        {
            cout << clean(hr) << ":" << clean(mins) << endl;
        }
    }

    return 0;
}