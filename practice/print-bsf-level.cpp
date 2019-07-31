#include <iostream>

#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
    {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

// Node *connect1(Node *root)
// {
//     if (root == NULL || root->left == NULL || root->right == NULL)
//         return root;

//     root->left->next = root->right;
//     if (root->next != NULL && root->next->left != NULL)
//         root->right->next = root->next->left;

//     connect(root->left);
//     connect(root->right);

//     return root;
// }

Node *connect(Node *root)
{
    if (!root || !root->left)
        return root;

    root->left->next = root->right;
    if (root->next)
    {
        root->right->next = root->next->left;
    }

    connect(root->left);
    connect(root->right);
    return root;
}

void printInorder(Node *root)
{
    if (!root)
        return;

    cout << root->val << " ";

    printInorder(root->left);
    printInorder(root->right);

    return;
}

void printRow(Node *root)
{

    while (root)
    {
        cout << root->val << " ";
        root = root->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Node *one1 = new Node(1, nullptr, nullptr, nullptr);
    Node *one2 = new Node(2, nullptr, nullptr, nullptr);
    Node *one3 = new Node(3, nullptr, nullptr, nullptr);
    Node *one4 = new Node(4, nullptr, nullptr, nullptr);
    Node *one5 = new Node(5, nullptr, nullptr, nullptr);
    Node *one6 = new Node(6, nullptr, nullptr, nullptr);
    Node *one7 = new Node(7, nullptr, nullptr, nullptr);

    one1->left = one2;
    one1->right = one3;
    one2->left = one4;
    one2->right = one5;
    one3->left = one6;
    one3->right = one7;

    cout << "printInorder \n";
    printInorder(one1);
    cout << endl;
    one1 = connect(one1);

    printRow(one1);
    printRow(one2);
    printRow(one4);
    return 0;
}
