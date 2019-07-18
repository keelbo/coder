#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

void updateMaxOutput(int &maxOutput, int i, int j, vector<int> height)
{
    int currOutput = min(height[i], height[j]) * (j - i);
    maxOutput = max(currOutput, maxOutput);
}

void updateIndexes(int &i, int &j, vector<int> height)
{
    if (height[i] > height[j])
    {
        j--;
    }
    else
    {
        i++;
    }
}

int maxArea(vector<int> &height)
{
    int startIndex = 0;
    int endIndex = height.size() - 1;
    int maxOutput = 0;

    while (startIndex <= endIndex)
    {
        updateMaxOutput(maxOutput, startIndex, endIndex, height);
        updateIndexes(startIndex, endIndex, height);
    }

    return maxOutput;
}
// 1 8 6 2 5 4 8 3 7
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

    cout << maxArea(arr);

    return 0;
}
