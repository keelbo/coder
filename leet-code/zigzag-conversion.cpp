#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printRow(int rowIndex, string s, int numRows, string &modifiedS)
{
    int index = rowIndex;
    int isDirDown = true;
    while (index < s.length())
    {

        modifiedS.push_back(s[index]);

        if (rowIndex == 0)
        {
            isDirDown = true;
        }
        else if (rowIndex == numRows - 1)
        {
            isDirDown = false;
        }

        if (isDirDown)
        {
            index = index + (numRows - 1 - rowIndex) * 2;
            if (numRows == 1)
            {
                index++;
            }
        }
        else
        {
            index = index + rowIndex * 2;
        }

        isDirDown = isDirDown ? false : true;
    }
}

string convert(string s, int numRows)
{
    string modifiedS;
    for (int i = 0; i < numRows; i++)
    {
        printRow(i, s, numRows, modifiedS);
    }
    return modifiedS;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int numRows;
    cin >> numRows;
    cout << convert(s, numRows);
    return 0;
}
