#include <iostream>

#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for a binary tree node.
 */

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
    TreeNode *bstToGst(TreeNode *root)
    {
        if (!root)
            return root;
        TreeNode *oRoot = root;
        int sum = 0;
        stack<TreeNode *> stack;
        while (root || !stack.empty())
        {
            while (root)
            {
                stack.push(root);
                root = root->right;
            }

            root = stack.top();
            stack.pop();

            sum += root->val;
            root->val = sum;

            root = root->left;
        }

        return oRoot;
    }
};

void printBST(TreeNode *root)
{
    if (!root)
        return;
    printBST(root->left);

    cout << root->val << " ";

    printBST(root->right);
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(1);
    root->left->left = new TreeNode(0);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(3);

    root->right = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);
    root->right->right->right = new TreeNode(8);

    Solution s;
    printBST(s.bstToGst(root));

    return 0;
}
