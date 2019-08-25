#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    void addSrc(unordered_map<int, vector<int>> &adjList, char srcChar)
    {
        int src = srcChar - 'a';

        if (adjList.find(src) == adjList.end())
        {
            adjList[src] = vector<int>(26, 0);
        }
    }

    void addEdge(unordered_map<int, vector<int>> &adjList, char srcChar, char destChar)
    {

        int src = srcChar - 'a';
        int dest = destChar - 'a';

        adjList[src][dest] = 1;
    }

    bool topologicalDfsTravelsal(unordered_map<int, vector<int>> &adjList, vector<int> &visitedNodeFlag, int src, string &topologicalOrder)
    {

        visitedNodeFlag[src] = 2;
        for (int i = 0; i < adjList[src].size(); i++)
        {

            if (adjList[src][i] == 1)
            {

                if (visitedNodeFlag[i] == 2)
                {
                    return false;
                }
                else if (visitedNodeFlag[i] == 0)
                {

                    bool loopExists = !topologicalDfsTravelsal(adjList, visitedNodeFlag, i, topologicalOrder);

                    if (loopExists)
                    {
                        return false;
                    }
                }
            }
        }
        visitedNodeFlag[src] = 1;
        topologicalOrder.push_back('a' + src);

        return true;
    }

    string getToplogicalOrder(unordered_map<int, vector<int>> &adjList)
    {
        vector<int> visitedNodeFlag(26, 0);

        string topologicalOrder = "";
        for (int i = 0; i < 26; i++)
        {
            if (adjList.find(i) != adjList.end() && visitedNodeFlag[i] == 0)
            {

                bool doesLoopExists = !topologicalDfsTravelsal(adjList, visitedNodeFlag, i, topologicalOrder);
                if (doesLoopExists)
                {
                    return "";
                }
            }
        }

        reverse(topologicalOrder.begin(), topologicalOrder.end());
        return topologicalOrder;
    }

    string alienOrder(vector<string> words)
    {

        if (words.empty())
            return "";

        unordered_map<int, vector<int>> adjList;

        for (int j = 0; j < words[0].size(); j++)
        {
            addSrc(adjList, words[0][j]);
        }

        for (int i = 0; i < words.size() - 1; i++)
        {

            for (int j = 0; j < words[i + 1].size(); j++)
            {
                addSrc(adjList, words[i + 1][j]);
            }

            int minWordLen = min(words[i].size(), words[i + 1].size());
            for (int j = 0; j < minWordLen; j++)
            {

                if (words[i][j] != words[i + 1][j])
                {
                    addEdge(adjList, words[i][j], words[i + 1][j]);
                    break;
                }
            }
        }

        return getToplogicalOrder(adjList);
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    cout << s.alienOrder(vector<string>{"za", "zb", "ca", "cb"}) << endl;
    return 0;
}
