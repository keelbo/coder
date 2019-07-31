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

void inorderFunction(TreeNode *root)
{
    if (!root)
        return;
    inorderFunction(root->left);
    cout << root->val << " ";
    inorderFunction(root->right);
}

void inorderLoop(TreeNode *root)
{
    stack<TreeNode *> stack;
    while (!stack.empty() || root != nullptr)
    {
        while (root)
        {
            stack.push(root);
            root = root->left;
        }
        root = stack.top();
        stack.pop();
        cout << root->val << " ";
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

    inorderFunction(root);
    cout << endl;
    inorderLoop(root);

    return 0;
}
