#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<int> setParent;
    vector<int> setSize;

    unordered_map<string, int> gridIndexMap;

public:
    string keyGen(int i, int j)
    {
        return to_string(i) + "$" + to_string(j);
    }

    void init(vector<vector<char>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                // cout << keyGen(i,j) << endl;
                gridIndexMap[keyGen(i, j)] = setParent.size();
                setParent.push_back(setParent.size());
                setSize.push_back(1);
            }
        }
        for (int i = 0; i < setParent.size(); i++)
        {
            cout << setParent[i] << " ";
        }
        cout << endl;
    }

    int setFind(int x)
    {
        if (x != setParent[x])
        {
            setParent[x] = setFind(setParent[x]);
        }
        return setParent[x];
    }

    void setUnion(int x, int y)
    {
        int xRoot = setFind(x);
        int yRoot = setFind(y);

        if (xRoot == yRoot)
            return;

        if (setSize[xRoot] < setSize[yRoot])
        {
            setParent[xRoot] = yRoot;
            setSize[yRoot] += setSize[xRoot];
        }
        else
        {
            setParent[yRoot] = xRoot;
            setSize[xRoot] += setSize[yRoot];
        }
    }

    void connectConnectedLands(vector<vector<char>> &grid)
    {
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] != '1')
                    continue;

                if (i - 1 >= 0 && grid[i - 1][j] == grid[i][j])
                {
                    setUnion(gridIndexMap[keyGen(i - 1, j)], gridIndexMap[keyGen(i, j)]);
                }
                if (i + 1 < grid.size() && grid[i + 1][j] == grid[i][j])
                {
                    setUnion(gridIndexMap[keyGen(i + 1, j)], gridIndexMap[keyGen(i, j)]);
                }
                if (j - 1 >= 0 && grid[i][j - 1] == grid[i][j])
                {
                    setUnion(gridIndexMap[keyGen(i, j - 1)], gridIndexMap[keyGen(i, j)]);
                }
                if (j + 1 < grid[i].size() && grid[i][j + 1] == grid[i][j])
                {
                    setUnion(gridIndexMap[keyGen(i, j + 1)], gridIndexMap[keyGen(i, j)]);
                }
            }
        }
    }

    int countLands()
    {
        int ans = 0;
        for (int i = 0; i < setParent.size(); i++)
        {
            cout << setParent[i] << " ";
            if (setParent[i] == i)
                ans++;
        }
        cout << endl;
        return ans;
    }

    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.size() == 0)
            return 0;

        init(grid);

        connectConnectedLands(grid);

        return countLands();
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<char>> grid{{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution s;
    cout << "numIslands : " << s.numIslands(grid) << endl;

    return 0;
}
