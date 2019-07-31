#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find(vector<int> &parent, int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent, parent[x]);
        }

        return parent[x];
    }

    void setUnion(vector<int> &parent, vector<int> &setSize, int x, int y)
    {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (xroot == yroot)
            return;

        if (setSize[xroot] <= setSize[yroot])
        {
            parent[xroot] = yroot;
            setSize[yroot] += setSize[xroot];
        }
        else
        {
            parent[yroot] = xroot;
            setSize[xroot] += setSize[yroot];
        }
    }

    int removeStones(vector<vector<int>> &stones)
    {
        vector<int> parent(stones.size());
        vector<int> setSize(stones.size());
        map<pair<int, int>, int> vertextToIndexMap;
        map<int, vector<int>> colPoints;
        map<int, vector<int>> rowPoints;
        map<int, vector<int>>::iterator itr;

        for (int i = 0; i < stones.size(); i++)
        {
            parent[i] = i;
            setSize[i] = 1;
        }

        for (int i = 0; i < stones.size(); i++)
        {
            vertextToIndexMap[pair<int, int>(stones[i][0], stones[i][1])] = i;
            colPoints[stones[i][0]].push_back(stones[i][1]);
            rowPoints[stones[i][1]].push_back(stones[i][0]);
        }

        for (itr = colPoints.begin(); itr != colPoints.end(); itr++)
        {
            int src = itr->first;
            vector<int> destList = itr->second;
            for (int i = 1; i < destList.size(); i++)
            {
                pair<int, int> srcV(src, destList[0]);
                pair<int, int> destV(src, destList[i]);
                setUnion(parent, setSize, vertextToIndexMap[srcV], vertextToIndexMap[destV]);
            }
        }

        for (itr = rowPoints.begin(); itr != rowPoints.end(); itr++)
        {
            int dest = itr->first;
            vector<int> srcList = itr->second;
            for (int i = 1; i < srcList.size(); i++)
            {
                pair<int, int> srcV(srcList[0], dest);
                pair<int, int> destV(srcList[i], dest);
                setUnion(parent, setSize, vertextToIndexMap[srcV], vertextToIndexMap[destV]);
            }
        }

        int ans = 0;
        for (int i = 0; i < parent.size(); i++)
        {
            if (parent[i] == i)
            {
                ans += (setSize[i] - 1);
            }
        }
        return ans;
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> v{
        {0, 0}, {0, 1}, {1, 0}, {1, 2}, {2, 1}, {2, 2}};
    Solution s;
    s.removeStones(v);
    return 0;
}
