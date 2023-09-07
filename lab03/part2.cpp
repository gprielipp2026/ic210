/*
Filename: part2.cpp
Name: MIDN GEORGE PRIELIPP (265112)
Can convert binary to decimal and add either of them
*/

#include <iostream>

using namespace std;

int main()
{
    // variables
    char type; // B or D
    char typeout = 'B'; // B or D based on rules
    char op = '+'; // + or =
    char b8,b4,b2,b1; // each bit and their corresponding value
    int Din; // D input
    int out = 0; // Decimal output (convert to B if needed)
    int nums = 0;

    while (op != '=')
    {
        // get user input
        cin >> type;

        // handle B
        if (type == 'B') 
        {
            // convert everything to D
            cin >> b8 >> b4 >> b2 >> b1;

            out += (b8 == '1') * 8;
            out += (b4 == '1') * 4;
            out += (b2 == '1') * 2;
            out += (b1 == '1') * 1;
            nums++;
        }
        // handle D
        else if (type == 'D') 
        {
            cin >> Din;

            out += Din;
            typeout = 'D';
            nums++;
        }
        cin >> op;
    }

    if ((nums == 1) && (typeout == 'D')) typeout = 'B'; // annoying case

    // iff B + D => D else => B
    if (typeout == 'D')
    {
        cout << 'D' << out << endl;
    }
    // convert back to B if needed
    else if (typeout == 'B')
    {
        cout << 'B' << ((out / 8) % 2) 
                    << ((out / 4) % 2) 
                    << ((out / 2) % 2) 
                    << ((out / 1) % 2) 
                    << endl;
    }

    return 0;
}