#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void getCharFreq(string &distChars, vector<int> &charFreq, string s)
    {
        char c;

        for (auto ch : s)
        {
            if (ch != c)
            {

                c = ch;
                distChars.push_back(ch);
                charFreq.push_back(1);
            }
            else
            {
                charFreq[charFreq.size() - 1]++;
            }
        }
    }

    int expressiveWords(string s, vector<string> words)
    {

        string distChars = "";
        vector<int> charFreq;

        getCharFreq(distChars, charFreq, s);

        int ans = 0;

        for (auto word : words)
        {

            int distCharsIndex = 0;

            for (int i = 0; i < word.size();)
            {

                if (distCharsIndex >= distChars.size())
                {
                    distCharsIndex = -1;
                    break;
                }

                if (word[i] == distChars[distCharsIndex])
                {

                    int wordCharFreq = 0;

                    while (i < word.size() && word[i] == distChars[distCharsIndex])
                    {
                        i++;
                        wordCharFreq++;
                    }

                    if (wordCharFreq == charFreq[distCharsIndex] || (charFreq[distCharsIndex] > wordCharFreq && charFreq[distCharsIndex] >= 3))
                    {
                        distCharsIndex++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            if (distCharsIndex == distChars.size())
                ans++;
        }

        return ans;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << "ans " << s.expressiveWords("heeellllllllllooooooooooo", vector<string>{"helllllo"}) << endl;
    return 0;
}
