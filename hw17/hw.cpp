/*
 * Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * takes n words, and sentence with n words, and prints it with '?' then reverse with '!'
 */

#include <iostream>
using namespace std;

string reverse(int n, string str[]);

int main()
{
    // get number of words
    int n;
    cout << "Number of words: ";
    cin >> n;

    // get sentence
    cout << "Sentence: ";
    string sentences[n];
    for(int i = 0; i < n; i++)
    {
        cin >> sentences[i];
        cout << sentences[i];
        if (i < n-1) cout << " ";
    }
    // output
    cout << "? " << reverse(n, sentences) << "!" << endl;

    return 0;
}

string reverse(int n, string str[])
{
    string rev = "";
    while(n--)
    {
        rev += str[n];
        if(n) rev += " ";
    }
    return rev;
}
