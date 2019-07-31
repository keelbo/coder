#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adjList(numCourses, vector<int>());
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> stack;

        // Prepare adjList
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int src = prerequisites[i][1];
            int dest = prerequisites[i][0];

            adjList[src].push_back(dest);
            indegree[dest]++;
        }

        // Find all degreeZero nodes
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // Find topo-order
        int i = 0;
        while (!q.empty())
        {
            int nodeVal = q.front();
            q.pop();
            stack.push_back(nodeVal);

            for (int j = 0; j < adjList[nodeVal].size(); j++)
            {
                int dest = adjList[i][j];
                indegree[dest]--;

                if (indegree[dest] == 0)
                {
                    q.push(dest);
                }
            }
            i++;
        }

        if (i == numCourses)
        {
            return stack;
        }
        else
        {
            return vector<int>();
        }
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<int>> v(1, vector<int>{0, 1});
    s.findOrder(2, v);
    return 0;
}
