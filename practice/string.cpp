#include <iostream>

using namespace std;

int main()
{
    int numberOfTests;
    string a, b;
    cin >> numberOfTests;
    while (numberOfTests--)
    {
        cin >> a >> b;
        int maxLength = a.length() > b.length() ? a.length() : b.length();
        cout << maxLength << endl;
        string concat = a + b;
        cout << concat << endl;
    }
    return 0;
}
