#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> unionSets(vector<string> a, vector<string> b)
    {
        unordered_map<string, bool> m;
        for (int i = 0; i < a.size(); i++)
        {
            m[a[i]] = true;
        }

        for (int i = 0; i < b.size(); i++)
        {
            m[b[i]] = true;
        }

        vector<string> ret;
        auto itr = m.begin();
        while (itr != m.end())
        {
            ret.push_back(itr->first);
            itr++;
        }

        sort(ret.begin(), ret.end());
        return ret;
    }

    vector<string> concatSets(vector<string> a, vector<string> b)
    {

        vector<string> ret;
        for (int i = 0; i < a.size(); i++)
        {
            for (int j = 0; j < b.size(); j++)
            {
                ret.push_back(a[i] + b[j]);
            }
        }

        sort(ret.begin(), ret.end());
        return ret;
    }

    vector<string> braceExpansionII(string expression)
    {
        if (expression.size() == 0)
            return vector<string>{};

        if (expression.size() == 1)
            return vector<string>{expression};

        if ('a' <= expression[0] && expression[0] <= 'z')
        {

            vector<string> l1{expression.substr(0, 1)};

            if (expression[1] == ',')
            {
                vector<string> l2 = braceExpansionII(expression.substr(2));
                return unionSets(l1, l2);
            }

            if (expression[1] == '{')
            {
                vector<string> l2 = braceExpansionII(expression.substr(1));
                return concatSets(l1, l2);
            }
        }
        else if (expression[0] == '{')
        {

            int closingIndex = 0;
            int st = 0;
            while (closingIndex < expression.size())
            {
                if (expression[closingIndex] == '{')
                {
                    st++;
                }
                if (expression[closingIndex] == '}')
                {
                    st--;
                }
                if (st == 0)
                {
                    break;
                }
                closingIndex++;
            }

            vector<string> l1 = braceExpansionII(expression.substr(1, closingIndex - 1));

            if (closingIndex + 1 >= expression.size())
            {
                return l1;
            }

            if (expression[closingIndex + 1] == ',')
            {
                vector<string> l2 = braceExpansionII(expression.substr(closingIndex + 2));
                return unionSets(l1, l2);
            }
            else
            {
                // { , a
                vector<string> l2 = braceExpansionII(expression.substr(closingIndex + 1));
                return concatSets(l1, l2);
            }
        }

        return vector<string>{};
    }
};

int main(int argc, char const *argv[])
{
    Solution s;

    vector<string> v = s.braceExpansionII("{a,b}{c,{d,e}}");

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}
