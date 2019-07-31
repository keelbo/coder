#include <iostream>

#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    double weight;
    int targetNodeId;
    Edge(){};
    Edge(double _weight, int _targetNodeId) : weight(_weight), targetNodeId(_targetNodeId) {}
};

struct Node
{
    int nodeId;
    vector<Edge> edges;
    Node(){};
    Node(int _nodeId) : nodeId(_nodeId)
    {
    }
};

class Solution
{
private:
    // Set
    vector<int> parent;
    vector<int> setSize;

    // Construct Graph
    unordered_map<int, Node> graph;
    unordered_map<string, int> nodeIdMap;

    // DFS
    vector<bool> coveredNodes;

public:
    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void setUnion(int x, int y)
    {
        int xroot = find(x);
        int yroot = find(y);

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

    void updateNodeIdMap(vector<string> equation)
    {
        if (nodeIdMap.find(equation[0]) == nodeIdMap.end())
        {

            parent.push_back(nodeIdMap.size());
            setSize.push_back(1);
            nodeIdMap[equation[0]] = nodeIdMap.size();
        }
        if (nodeIdMap.find(equation[1]) == nodeIdMap.end())
        {

            parent.push_back(nodeIdMap.size());
            setSize.push_back(1);
            nodeIdMap[equation[1]] = nodeIdMap.size();
        }
        setUnion(nodeIdMap[equation[0]], nodeIdMap[equation[1]]);
    }

    void addEdgeToGraph(vector<string> equation, double weight)
    {
        string srcStr = equation[0];
        string destStr = equation[1];

        if (graph.find(nodeIdMap[srcStr]) == graph.end())
        {
            graph[nodeIdMap[srcStr]] = Node(nodeIdMap[srcStr]);
        }
        graph[nodeIdMap[srcStr]].edges.push_back(Edge(weight, nodeIdMap[destStr]));

        if (graph.find(nodeIdMap[destStr]) == graph.end())
        {
            graph[nodeIdMap[destStr]] = Node(nodeIdMap[destStr]);
        }
        graph[nodeIdMap[destStr]].edges.push_back(Edge(1 / weight, nodeIdMap[srcStr]));
    }

    double dfs(int srcId, int destId, double weightSum)
    {

        if (srcId == destId)
            return weightSum;

        vector<Edge> edges = graph[srcId].edges;

        // Check destId adj to srcId
        for (int i = 0; i < edges.size(); i++)
        {
            if (destId == edges[i].targetNodeId)
            {
                return weightSum * edges[i].weight;
            }
        }

        coveredNodes[srcId] = true;
        for (int i = 0; i < edges.size(); i++)
        {
            if (!coveredNodes[edges[i].targetNodeId])
            {
                double weight = dfs(edges[i].targetNodeId, destId, weightSum * edges[i].weight);
                if (weight > 0)
                {
                    return weight;
                }
            }
        }

        return -1;
    }

    double findNodeDist(string src, string dest)
    {
        coveredNodes = vector<bool>(nodeIdMap.size(), false);
        return dfs(nodeIdMap[src], nodeIdMap[dest], 1);
    }

    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {

        vector<double> ans;

        for (int i = 0; i < equations.size(); i++)
        {
            updateNodeIdMap(equations[i]);
            addEdgeToGraph(equations[i], values[i]);
        }

        for (int i = 0; i < queries.size(); i++)
        {
            int srcNodeId = nodeIdMap.find(queries[i][0]) != nodeIdMap.end() ? nodeIdMap[queries[i][0]] : -1;
            int destNodeId = nodeIdMap.find(queries[i][1]) != nodeIdMap.end() ? nodeIdMap[queries[i][1]] : -1;
            bool isSrcDestConnected = !(srcNodeId == -1 || destNodeId == -1 || find(srcNodeId) != find(destNodeId));
            if (!isSrcDestConnected)
            {
                ans.push_back(-1);
            }
            else
            {
                string src = queries[i][0];
                string dest = queries[i][1];
                double weight = findNodeDist(src, dest);
                // addEdgeToGraph(vector<string>{src, dest}, weight);

                ans.push_back(weight);
            }
        }

        return ans;
    }
};

void printVector(vector<double> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;
    vector<vector<string>> eqs{{"a", "b"}, {"b", "c"}};
    vector<double> values{2.0, 3.0};
    vector<vector<string>> queries{{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};

    printVector(s.calcEquation(eqs, values, queries));
    return 0;
}
