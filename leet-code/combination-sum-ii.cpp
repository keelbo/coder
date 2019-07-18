#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void gen(unordered_map<int, int> mp, int target, int sum, unordered_map<int, int>::iterator p, vector<int> arr, vector<vector<int>> &ans)
{
    if (sum == target)
    {
        ans.push_back(arr);
    }

    if (sum >= target || p == mp.end())
    {
        return;
    }

    unordered_map<int, int>::iterator pOld = p;
    p = next(p);
    gen(mp, target, sum, p, arr, ans);
    p = pOld;

    int s = sum;
    for (int i = 1; i <= p->second; i++)
    {
        arr.push_back(p->first);
        s += p->first;
        pOld = p;
        p = next(p);
        gen(mp, target, s, p, arr, ans);
        p = pOld;
    }

    return;
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> arr;

    sort(candidates.begin(), candidates.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < candidates.size(); i++)
    {
        if (mp.find(candidates[i]) == mp.end())
        {
            mp[candidates[i]] = 1;
        }
        else
        {
            mp[candidates[i]]++;
        }
    }

    gen(mp, target, 0, mp.begin(), arr, ans);
    return ans;
}

void print2D(vector<vector<int>> v)
{
    cout << "print2D" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }

        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int target;
    cin >> target;
    vector<int> v;
    cin >> n;
    while (n--)
    {
        int elm;
        cin >> elm;
        v.push_back(elm);
    }

    print2D(combinationSum2(v, target));

    return 0;
}
