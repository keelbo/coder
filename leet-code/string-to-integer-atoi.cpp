#include <iostream>

#include <bits/stdc++.h>

using namespace std;

int myAtoi(string str)
{
    long ret = 0;
    int i = 0;
    int sign = 1;
    int validInt = false;
    while (i < str.length() && str[i] == ' ')
    {
        i++;
    }
    if (i < str.length() && sign == 0 && str[i] == '-')
    {
        sign = -1;
        i++;
    }
    if (i < str.length() && sign == 0 && str[i] == '+')
    {
        sign = 1;
        i++;
    }

    while (i < str.length() && str[i] >= '0' && str[i] <= '9' && ret < INT_MAX && ret > INT_MIN)
    {
        validInt = true;
        cout << str[i] << endl;
        char c = str[i];
        ret = ret * 10 + (c - '0');
        i++;
    }

    if (!validInt)
    {
        return 0;
    }

    if (ret > INT_MAX)
    {
        return INT_MAX;
    }

    if (ret < INT_MIN)
    {
        return INT_MIN;
    }

    return (int)(ret * sign);
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    cout << myAtoi(s) << endl;
    return 0;
}
