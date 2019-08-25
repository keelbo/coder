#include <iostream>

#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {

        string encoding = "";
        deque<TreeNode *> q;
        q.push_back(root);

        bool isFirstTime = true;

        while (!q.empty())
        {
            int qSize = q.size();
            while (qSize--)
            {

                if (isFirstTime)
                {
                    isFirstTime = !isFirstTime;
                }
                else
                {
                    encoding += ',';
                }

                if (!q.front())
                {
                    // encoding.append(to_string(q.front()->val));
                    TreeNode *temp = nullptr;
                    TreeNode *left = q.front()->left ? q.front()->left : temp;
                    TreeNode *right = q.front()->right ? q.front()->right : temp;
                    q.push_back(left);
                    q.push_back(right);
                }
                else
                {
                    encoding.append("null");
                }

                q.pop_front();
            }
        }

        return encoding;
    }

    void split(vector<string> &strs, string str, char c)
    {
        string s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ',')
            {
                strs.push_back(s);
                s = "";
                continue;
            }
            s += str[i];
        }
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        vector<string> nodeVals;
        split(nodeVals, data, ',');

        deque<TreeNode *> q;
        TreeNode *root;
        if (nodeVals[0] == "null")
            return root;

        root = new TreeNode(stoi(nodeVals[0]));
        q.push_back(root);
        int index = 1;

        while (!q.empty())
        {
            int qSize = q.size();
            while (qSize--)
            {

                if (index < nodeVals.size() && nodeVals[index] != "null")
                {
                    q.front()->left = new TreeNode(stoi(nodeVals[index]));
                    q.push_back(q.front()->left);
                }
                index++;
                if (index < nodeVals.size() && nodeVals[index] != "null")
                {
                    q.front()->right = new TreeNode(stoi(nodeVals[index]));
                    q.push_back(q.front()->right);
                }
                index++;
                q.pop_front();
            }
        }

        return root;
    }
};

void printInorder(TreeNode *root)
{
    cout << endl
         << "printInorder" << endl;
    if (!root)
    {
        cout << "null" << endl;
        return;
    }

    deque<TreeNode *> q;
    q.push_back(root);

    while (!q.empty())
    {
        int qSize = q.size();
        while (qSize--)
        {
            cout << q.front()->val << " ";
            if (q.front()->left)
                q.push_back(q.front()->left);
            if (q.front()->right)
                q.push_back(q.front()->right);

            q.pop_front();
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    Codec c;
    TreeNode *root = c.deserialize("1,2,3,null,null,4,5");
    printInorder(root);
    return 0;
}