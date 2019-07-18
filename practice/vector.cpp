#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void printV(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void fun(vector<int> v1, int k)
{
    cout << "fun IN : k " << k << endl;
    printV(v1);
    int i = k;
    while (i--)
    {
        v1.push_back(i);
        fun(v1, k - 1);
    }
    cout << "fun IN : k " << k << endl;
    printV(v1);
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 2, 3};
    vector<int> v1;

    v1 = v;

    v1.push_back(4);
    v1.push_back(5);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
