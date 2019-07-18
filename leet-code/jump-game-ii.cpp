#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int jump(vector<int> &nums)
{
    vector<int> dp(nums.size(), 0);

    int q = nums.size() - 1;
    while (--q >= 0)
    {
        int minJumps = dp[q + 1] + 1;
        cout << "dp[q + 1] + 1 : " << dp[q + 1] + 1 << endl;
        for (int j = 2; j <= nums[q] && j + q < dp.size(); j++)
        {
            minJumps = min(minJumps, 1 + dp[j + q]);
        }
        dp[q] = minJumps;
    }

    return dp[0];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int elm;
        cin >> elm;
        v.push_back(elm);
    }
    cout << jump(v);
    return 0;
}
