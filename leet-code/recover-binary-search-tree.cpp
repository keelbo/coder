#include <iostream>

#include <bits/stdc++.h>

using namespace std;

//Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeNodeChildMinMax
{
    TreeNode *minNode;
    TreeNode *minNodePar;
    TreeNode *maxNode;
    TreeNode *maxNodePar;
    TreeNodeChildMinMax(TreeNode *min, TreeNode *minPar, TreeNode *max, TreeNode *maxPar) : minNode(min), minNodePar(minPar), maxNode(max), maxNodePar(maxPar) {}
};

class Solution
{
public:
    void swap(TreeNode *n1, TreeNode *n1p, TreeNode *n2, TreeNode *n2p)
    {
        int temp = n1->val;
        n1->val = n2->val;
        n2->val = temp;
    }

    TreeNodeChildMinMax *travelTree(TreeNode *node, TreeNode *parNode, bool &isSwaped)
    {

        TreeNodeChildMinMax *leftMinMax = NULL;
        TreeNodeChildMinMax *rightMinMax = NULL;

        if (node->left)
        {
            leftMinMax = travelTree(node->left, node, isSwaped);
        }

        if (node->right)
        {
            rightMinMax = travelTree(node->right, node, isSwaped);
        }

        TreeNodeChildMinMax *ret;
        if (isSwaped)
        {
            return ret;
        }

        if (leftMinMax && rightMinMax)
        {
            if (leftMinMax->maxNode->val < node->val && node->val < rightMinMax->minNode->val)
            {

                return new TreeNodeChildMinMax(leftMinMax->minNode, leftMinMax->minNodePar, rightMinMax->maxNode, rightMinMax->maxNodePar);
            }
            else if (leftMinMax->maxNode->val < node->val)
            {

                swap(node, parNode, rightMinMax->minNode, rightMinMax->minNodePar);
                isSwaped = true;
                return ret;
            }
            else if (node->val < rightMinMax->minNode->val)
            {

                swap(node, parNode, leftMinMax->maxNode, leftMinMax->maxNodePar);
                isSwaped = true;
                return ret;
            }
            else
            {
                swap(leftMinMax->maxNode, leftMinMax->maxNodePar, rightMinMax->minNode, rightMinMax->minNodePar);
                isSwaped = true;
                return ret;
            }
        }
        else if (leftMinMax)
        {

            if (leftMinMax->maxNode->val < node->val)
            {

                return new TreeNodeChildMinMax(leftMinMax->minNode, leftMinMax->minNodePar, node, parNode);
            }
            else
            {

                swap(node, parNode, leftMinMax->maxNode, leftMinMax->maxNodePar);
                isSwaped = true;
                return ret;
            }
        }
        else if (rightMinMax)
        {

            if (node->val < rightMinMax->minNode->val)
            {

                return new TreeNodeChildMinMax(node, parNode, rightMinMax->maxNode, rightMinMax->maxNodePar);
            }
            else
            {

                swap(node, parNode, rightMinMax->minNode, rightMinMax->minNodePar);
                isSwaped = true;
                return ret;
            }
        }
        else
        {
            return new TreeNodeChildMinMax(node, parNode, node, parNode);
        }
    }

    void recoverTree(TreeNode *root)
    {
        bool isSwaped = false;
        TreeNode *rootPar = new TreeNode(0);
        rootPar->left = root;
        travelTree(root, rootPar, isSwaped);
    }
};

void printBST(TreeNode *node)
{
    if (node->left)
    {
        printBST(node->left);
    }
    cout << node->val << " ";
    if (node->right)
    {
        printBST(node->right);
    }
    return;
}

int main(int argc, char const *argv[])
{
    TreeNode *two = new TreeNode(2);
    TreeNode *one = new TreeNode(1);
    TreeNode *four = new TreeNode(4);
    TreeNode *three = new TreeNode(3);
    TreeNode *root = three;
    three->left = one;
    three->right = four;
    four->left = two;

    Solution s;
    printBST(root);
    cout << endl;
    s.recoverTree(root);
    printBST(root);

    return 0;
}
