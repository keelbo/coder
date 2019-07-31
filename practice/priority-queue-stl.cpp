// Ref : https://www.geeksforgeeks.org/priority-queue-in-cpp-stl/

#include <iostream>

#include <bits/stdc++.h>

using namespace std;

void showpq(priority_queue<int> pq)
{

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(8);
    pq.push(4);
    pq.push(100);
    pq.push(77);
    pq.push(898);
    pq.push(11);

    showpq(pq);

    return 0;
}
