// Ref : https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
};

class MyComparator
{
public:
    int operator()(Node *n1, Node *n2)
    {
        return n1->val > n2->val;
    }
};

void showpq(priority_queue<Node *, vector<Node *>, MyComparator> pq)
{
    while (!pq.empty())
    {
        cout << pq.top()->val << " ";
        pq.pop();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    priority_queue<Node *, vector<Node *>, MyComparator> pq;
    pq.push(new Node(1));
    pq.push(new Node(100));
    pq.push(new Node(99));
    pq.push(new Node(89));
    pq.push(new Node(23));
    pq.push(new Node(44));

    showpq(pq);

    return 0;
}
