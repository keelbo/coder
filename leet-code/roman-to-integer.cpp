#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s)
{
    unordered_map<char, int> symbolValue;
    unordered_map<char, set<char>> subMap;

    symbolValue['I'] = 1;
    symbolValue['V'] = 5;
    symbolValue['X'] = 10;
    symbolValue['L'] = 50;
    symbolValue['C'] = 100;
    symbolValue['D'] = 500;
    symbolValue['M'] = 1000;

    subMap['I'] = set<char>{'V', 'X'};
    subMap['X'] = set<char>{'L', 'C'};
    subMap['C'] = set<char>{'D', 'M'};

    int index = 0;
    int ans = 0;

    while (index < s.length())
    {

        if (index + 1 < s.length())
        {
            if (s[index] != s[index + 1])
            {
                if (subMap[s[index]].find(s[index + 1]) != subMap[s[index]].end())
                {
                    ans += symbolValue[s[index + 1]] - symbolValue[s[index]];
                    index += 2;
                }
                else
                {
                    ans += symbolValue[s[index]];
                    index += 1;
                }
            }
            else
            {
                int cnt = 2;
                if (index + 2 < s.length() && s[index] == s[index + 2])
                {
                    cnt = 3;
                }
                ans += (symbolValue[s[index]] * cnt);
                index += cnt;
            }
        }
        else
        {
            ans += symbolValue[s[index]];
            index += 1;
        }
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << romanToInt(s) << endl;
    return 0;
}
