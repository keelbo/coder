#include <iostream>

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node(){};
    Node(int v) : val(v){};
};

int main(int argc, char const *argv[])
{

    Node *n = nullptr;

    if (n != NULL)
    {
        cout << "n : " << n->val << endl;
    }
    else
    {
        cout << "n is NULL" << endl;
    }
    return 0;
}
