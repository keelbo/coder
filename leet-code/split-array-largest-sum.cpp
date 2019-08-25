#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> dp;

public:
    int splitArray(vector<int> &nums, int m, int p)
    {
        cout << "p " << p << " m " << m << endl;
        if (dp[p][m] != -1)
            return dp[p][m];

        int minLargestSum = 0;

        if (m == 1)
        {
            for (int i = p; i < nums.size(); i++)
            {
                minLargestSum += nums[i];
            }
        }
        else if (p + m == nums.size())
        {
            minLargestSum = *max_element(nums.begin() + p, nums.begin() + p + m);
        }
        else
        {

            minLargestSum = INT_MAX;
            int sum = 0;
            int index = p;
            while (index + m <= nums.size())
            {
                sum += nums[index++];
                minLargestSum = min(minLargestSum, max(sum, splitArray(nums, m - 1, index)));
            }
        }

        dp[p][m] = minLargestSum;
        return dp[p][m];
    }

    int splitArray(vector<int> &nums, int m)
    {
        initDP(nums.size(), m);
        return splitArray(nums, m, 0);
    }

    void initDP(int n, int m)
    {
        dp.clear();
        while (n--)
        {
            dp.push_back(vector<int>(m + 1, -1));
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<int> v{2, 3, 1, 2, 4};
    cout << s.splitArray(v, 3) << endl;
    return 0;
}
