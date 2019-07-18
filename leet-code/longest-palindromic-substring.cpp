#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int checkPalindrom(vector<vector<int>> &isPalindromExists, string s, int i, int j)
{
    if (j < i)
    {
        return 1;
    }
    if (isPalindromExists[i][j] != -1)
    {
        return isPalindromExists[i][j];
    }

    int isPalindrom = s[i] == s[j] && checkPalindrom(isPalindromExists, s, i + 1, j - 1);

    isPalindromExists[i][j] = isPalindrom ? 1 : 0;

    return isPalindromExists[i][j];
}

string longestPalindrome(string s)
{
    vector<vector<int>> isPalindromExist(s.length());
    for (int i = 0; i < s.length(); i++)
    {
        isPalindromExist[i] = vector<int>(s.length() - i);
        for (int j = 0; j < isPalindromExist[i].size(); j++)
        {
            isPalindromExist[i][j] = -1;
        }
    }

    int maxPalLength = 0;
    int palSubIndex = 0;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            if (i > j)
            {
                continue;
            }

            if (checkPalindrom(isPalindromExist, s, i, j))
            {
                if (j - i + 1 > maxPalLength)
                {
                    maxPalLength = j - i + 1;
                    palSubIndex = i;
                }
            }
        }
    }

    return s.substr(palSubIndex, maxPalLength);
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
    return 0;
}
