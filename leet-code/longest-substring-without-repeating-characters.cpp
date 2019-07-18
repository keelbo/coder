#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void updateMaxLength(int subStringIndex, int currIndex, int *maxLength)
{
    if (currIndex - subStringIndex > *maxLength)
    {
        *maxLength = currIndex - subStringIndex;
    }
    return;
}

int lengthOfLongestSubstring(string s)
{
    int subStringIndex = 0;
    int maxLength = 0;
    int index = 0;

    unordered_map<char, int> mp;

    while (index < s.length())
    {
        bool doesCurrCharExist = mp.find(s[index]) != mp.end();
        if (doesCurrCharExist)
        {
            updateMaxLength(subStringIndex, index, &maxLength);

            while (subStringIndex <= mp[s[index]])
            {
                mp.erase(s[subStringIndex++]);
            }
        }

        mp[s[index]] = index;

        index++;
    }

    updateMaxLength(subStringIndex, index, &maxLength);

    return maxLength;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s);
    return 0;
}
