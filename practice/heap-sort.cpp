#include <iostream>

#include <bits/stdc++.h>

using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &v, int i, int size)
{
    int root = i;
    int l = root * 2 + 1;
    int r = root * 2 + 2;

    if (l < size && v[l] < v[root])
    {
        root = l;
    }
    if (r < size && v[r] < v[root])
    {
        root = r;
    }

    if (root != i)
    {
        swap(v[root], v[i]);
        heapify(v, root, size);
    }
}

void printV(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void heapSort(vector<int> &v)
{
    for (int i = (v.size() - 1) / 2; i >= 0; i--)
    {
        heapify(v, i, v.size());
    }

    printV(v);

    for (int i = v.size() - 1; i >= 0; i--)
    {
        swap(v[0], v[i]);
        heapify(v, 0, i + 1);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v;
    while (n--)
    {
        int elm;
        cin >> elm;
        v.push_back(elm);
    }

    heapSort(v);
    printV(v);
    return 0;
}
