#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int> array, int target)
{
    vector<int> retIndexArr;
    map<int, int> valueIndexMap;
    map<int, int>::iterator p, q;
    for (int i = 0; i < array.size(); i++)
    {
        if (valueIndexMap.find(array[i]) == valueIndexMap.end())
        {
            valueIndexMap[array[i]] = i + 1;
        }
        else if (array[i] * 2 == target)
        {
            retIndexArr.push_back(valueIndexMap[array[i]]);
            retIndexArr.push_back(i + 1);
            return retIndexArr;
        }
    }

    p = valueIndexMap.begin();
    q = valueIndexMap.end();
    q--;

    while (p != q)
    {
        int sum = p->first + q->first;
        if (sum == target)
        {
            retIndexArr.push_back(p->second);
            retIndexArr.push_back(q->second);
            return retIndexArr;
        }
        else if (sum > target)
        {
            q--;
        }
        else
        {
            p++;
        }
    }
}

vector<int> twoSum2(vector<int> nums, int target)
{
    map<int, int> mp;
    vector<int> ret;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            ret.push_back(mp[target - nums[i]]);
            ret.push_back(i + 1);
            return ret;
        }
        else
        {
            mp[nums[i]] = i + 1;
        }
    }
}

int main()
{
    int arraySize;
    vector<int> array;
    int target;

    cin >> arraySize;

    while (arraySize--)
    {
        int arrayElm;
        cin >> arrayElm;
        array.push_back(arrayElm);
    }

    cin >> target;

    vector<int> indexArr = twoSum2(array, target);
    cout << indexArr[0] << " " << indexArr[1] << '\n';
    return 0;
}