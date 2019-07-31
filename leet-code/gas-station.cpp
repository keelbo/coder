#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int fuelSum = 0;
        int maxFuelIndex = 0;
        int maxFuelVal = INT_MIN;

        vector<int> fuel(gas.size(), 0);
        for (int i = 0; i < gas.size(); i++)
        {
            fuel[i] += gas[i] - cost[i];
            if (gas[i] - cost[i] >= maxFuelVal)
            {
                maxFuelIndex = i;
                maxFuelVal = gas[i] - cost[i];
            }
            fuelSum += fuel[i];
        }

        if (fuelSum < 0)
            return -1;

        int preMaxIndex = -1;
        int sum = 0;
        int i = maxFuelIndex - 1;
        while (i >= 0)
        {
            sum += gas[i] - cost[i];
            if (sum >= 0)
            {
                sum = 0;
                preMaxIndex = i;
            }
            i--;
        }

        i = gas.size() - 1;
        while (maxFuelIndex < i)
        {
            sum += gas[i] - cost[i];
            if (sum >= 0)
            {
                sum = 0;
                preMaxIndex = i;
            }
            i--;
        }

        return preMaxIndex;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> gas, costs;
    int i = 0;
    int num;
    while (i++ < n)
    {
        cin >> num;
        gas.push_back(num);
    }

    i = 0;
    while (i++ < n)
    {
        cin >> num;
        costs.push_back(num);
    }

    Solution s;
    cout << s.canCompleteCircuit(gas, costs) << endl;

    return 0;
}
