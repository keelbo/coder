#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
    if (nums.size() < 3)
    {
        return ans;
    }

    sort(nums.begin(), nums.end());
    int i = nums.size() - 1;
    while (i >= 2)
    {
        int p = 0;
        int q = i - 1;
        int twoElmSum = 0 - nums[i];
        while (p < q)
        {
            if (nums[p] + nums[q] == twoElmSum)
            {
                ans.push_back(vector<int>{nums[p], nums[q], nums[i]});
                int numP = nums[p];
                do
                {
                    p++;
                } while (p < q && numP == nums[p]);
                int numQ = nums[q];
                do
                {
                    q--;
                } while (p < q && numQ == nums[q]);
            }
            else if (nums[p] + nums[q] < twoElmSum)
            {
                p++;
            }
            else
            {
                q--;
            }
        }
        int numI = nums[i];
        do
        {
            i--;
        } while (i >= 2 && numI == nums[i]);
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> arr;
    while (n--)
    {
        int arrElm;
        cin >> arrElm;
        arr.push_back(arrElm);
    }
    vector<vector<int>> ans = threeSum(arr);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i][0] << "  " << ans[i][1] << "  " << ans[i][2] << endl;
    }

    return 0;
}
