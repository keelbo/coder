#include <iostream>

#include <bits/stdc++.h>

using namespace std;

bool MyComparator(int x, int y)
{
    return x > y;
}

void printV(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> v{1, 99, 23, 87, 100, 3, 5, 4, 8, 2};
    sort(v.begin(), v.end(), MyComparator);
    printV(v);
    return 0;
}
