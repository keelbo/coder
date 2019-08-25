#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 67;
    cout << " a " << a << " b " << b << endl;

    a ^= b;
    b ^= a;
    a ^= b;

    cout << " a " << a << " b " << b << endl;

    a ^= b;
    b ^= a;
    a ^= b;

    cout << " a " << a << " b " << b << endl;

    string s = "sachin";

    for (auto i = 0; s[i]; i++)
    {
        cout << s[i] << endl;
    }

    

    return 0;
}
