#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

void postorderFunction(TreeNode *root)
{
    if (!root)
        return;
    postorderFunction(root->left);
    postorderFunction(root->right);
    cout << root->val << " ";
}

void postorderLoop(TreeNode *root)
{
    stack<TreeNode *> stack;
    while (!stack.empty() || root != nullptr)
    {
        while (root)
        {
            cout << root->val << " ";
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        root = root->right;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    postorderFunction(root);
    cout << endl;
    postorderLoop(root);

    return 0;
}
