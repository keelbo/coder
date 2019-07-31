#include <iostream>

#include <bits/stdc++.h>

using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        deque<TreeNode *> dqueue;

        if (!root)
            return ret;

        bool leftToRight = true;

        dqueue.push_back(root);

        while (!dqueue.empty())
        {
            vector<int> v;
            int qsize = dqueue.size();
            if (leftToRight)
            {
                for (int i = 0; i < qsize; i++)
                {
                    TreeNode *n = dqueue.front();
                    dqueue.pop_front();
                    v.push_back(n->val);
                    if (n->left)
                        dqueue.push_back(n->left);
                    if (n->right)
                        dqueue.push_back(n->right);
                }
            }
            else
            {
                for (int i = 0; i < qsize; i++)
                {
                    TreeNode *n = dqueue.back();
                    dqueue.pop_back();
                    v.push_back(n->val);
                    if (n->right)
                        dqueue.push_front(n->right);
                    if (n->left)
                        dqueue.push_front(n->left);
                }
            }
            ret.push_back(v);
            leftToRight = !leftToRight;
        }

        return ret;
    }
};

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution s;
    s.zigzagLevelOrder(root);

    return 0;
}
