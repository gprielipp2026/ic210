/*
 * Filename: hw.cpp
 * Name: MIDN GEORGE PRIELIPP (265112)
 * Takes in a file of ints and creates an html table with the data
 */
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    // open input file
    ifstream fin("input.txt");
    if(!fin) return 1;

    // open output file
    ofstream fout("output.html");

    // read height and width of table
    int rows, cols;
    fin >> rows >> cols;

    // format output table
    fout << "<table border=2>" << endl;

    // read in rest of data
    for(int row = 0; row < rows; row++)
    {
        fout << "<tr>";
        for(int col = 0; col < cols; col++)
        {
            int num;
            // read num
            fin >> num;
            // save it to output in correct form
            fout << "<td>" << num << "</td>";
        }
        fout << "</tr>" << endl;
    }
  
    // end format table
    fout << "</table>" << endl;

    return 0;
}
