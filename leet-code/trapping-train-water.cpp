#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int trap(vector<int> &height)
{

    if (height.size() <= 1)
    {
        return 0;
    }

    int p = 0;
    int q = height.size() - 1;
    int pLast = p;
    int qLast = q;
    int ans = 0;

    vector<int> sumArr;
    sumArr.push_back(height[0]);

    for (int i = 1; i < height.size(); i++)
    {
        sumArr.push_back(sumArr[i - 1] + height[i]);
    }

    int isDirForward = height[p] <= height[q] ? true : false;
    while (p <= q)
    {

        if (isDirForward)
        {
            if (p != pLast && height[pLast] <= height[p])
            {
                ans += height[pLast] * (p - pLast) - (sumArr[p - 1] - (pLast - 1 >= 0 ? sumArr[pLast - 1] : 0));
                pLast = p;

                isDirForward = height[p] <= height[q] ? true : false;
            }
        }
        else
        {
            if (q != qLast && height[q] >= height[qLast])
            {
                ans = ans + height[qLast] * (qLast - q) - (sumArr[qLast] - sumArr[q]);
                qLast = q;

                isDirForward = height[p] <= height[q] ? true : false;
            }
        }

        if (isDirForward)
        {
            p++;
        }
        else
        {
            q--;
        }
    }
    return ans;
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
    cout << trap(v) << endl;
    return 0;
}
