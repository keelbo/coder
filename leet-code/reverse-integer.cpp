#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    int sign = x > 0 ? 1 : -1;
    x *= sign;
    double revX = 0;

    while (x / 10 > 0)
    {
        revX = revX * 10 + x % 10;
        x = x / 10;
    }

    if (x > 0)
    {
        revX = revX * 10 + x;
    }

    return revX * sign;
}

int main(int argc, char const *argv[])
{
    int x;
    cin >> x;
    cout << reverse(x);
    return 0;
}
