#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int getPalimdromLength(string s, int i, int j)
{
    int length = 0;
    while (i >= 0 && j < s.length())
    {
        if (s[i--] != s[j++])
        {
            return length;
        }
        length++;
    }
    return length;
}

string longestPalindrome(string s)
{
    int palSubIndex = 0;
    int maxLength = 1;
    for (int i = 0; i < s.length(); i++)
    {
        int palLength = getPalimdromLength(s, i - 1, i + 1);
        if (palLength * 2 + 1 > maxLength)
        {
            palSubIndex = i - palLength;
            maxLength = palLength * 2 + 1;
        }

        palLength = getPalimdromLength(s, i, i + 1);
        if (palLength * 2 > maxLength)
        {
            palSubIndex = i - palLength + 1;
            maxLength = palLength * 2;
        }
    }

    return s.substr(palSubIndex, maxLength);
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
