#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int find(vector<int> parents, int x)
    {
        if (parents[x] != x)
        {
            parents[x] = find(parents, parents[x]);
        }
        return parents[x];
    }

    void setUnion(vector<int> &parents, vector<int> &setSize, int x, int y)
    {
        int xroot = find(parents, x);
        int yroot = find(parents, y);

        if (xroot == yroot)
            return;

        if (setSize[xroot] <= setSize[yroot])
        {
            parents[xroot] = yroot;
            setSize[yroot] += setSize[xroot];
        }
        else
        {
            parents[yroot] = xroot;
            setSize[xroot] += setSize[yroot];
        }
    }

    vector<int> findRedundantDirectedConnection(vector<vector<int>> &edges)
    {
        vector<int> ret;
        vector<int> parents(edges.size() + 1);
        vector<int> setSize(edges.size() + 1);
        vector<int> indegree(edges.size() + 1, 0);
        int rootNodeIndex = 0;

        for (int i = 1; i < parents.size(); i++)
        {
            parents[i] = i;
            setSize[i] = 1;
            indegree[edges[i][1]]++;
        }

        for (int i = 1; i <= edges.size(); i++)
        {
            if (indegree[i] == 0)
            {
                rootNodeIndex = i;
                setUnion(parents, setSize, edges[i][0], edges[i][1]);
            }
        }

        for (int i = 0; i < edges.size(); i++)
        {
            if (i == rootNodeIndex)
            {
                continue;
            }

            if (find(parents, edges[i][0]) == find(parents, edges[i][1]))
            {
                ret.push_back(edges[i][0]);
                ret.push_back(edges[i][1]);
                return ret;
            }
            setUnion(parents, setSize, edges[i][0], edges[i][1]);
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> v{
        {1, 2}, {1, 3}, {2, 3}};
    s.findRedundantDirectedConnection(v);
    return 0;
}
