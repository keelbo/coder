#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num)
{
    map<int, std::string> intRomanMap;
    intRomanMap[1] = "I";
    intRomanMap[2] = "II";
    intRomanMap[3] = "III";
    intRomanMap[4] = "IV";
    intRomanMap[5] = "V";
    intRomanMap[6] = "VI";
    intRomanMap[7] = "VII";
    intRomanMap[8] = "VIII";
    intRomanMap[9] = "IX";
    intRomanMap[10] = "X";

    intRomanMap[10] = "X";
    intRomanMap[20] = "XX";
    intRomanMap[30] = "XXX";
    intRomanMap[40] = "XL";
    intRomanMap[50] = "L";
    intRomanMap[60] = "LX";
    intRomanMap[70] = "LXX";
    intRomanMap[80] = "LXXX";
    intRomanMap[90] = "XC";
    intRomanMap[100] = "C";

    intRomanMap[100] = "C";
    intRomanMap[200] = "CC";
    intRomanMap[300] = "CCC";
    intRomanMap[400] = "CD";
    intRomanMap[500] = "D";
    intRomanMap[600] = "DC";
    intRomanMap[700] = "DCC";
    intRomanMap[800] = "DCCC";
    intRomanMap[900] = "CM";
    intRomanMap[1000] = "M";

    intRomanMap[2000] = "MM";
    intRomanMap[3000] = "MMM";

    int unitPlace = 0;
    stack<string> st;
    while (num)
    {
        int digit = num % 10;
        st.push(intRomanMap[digit * (int)pow(10, unitPlace)]);
        num /= 10;
        unitPlace++;
    }

    string romanStr;
    while (!st.empty())
    {
        romanStr.append(st.top());
        st.pop();
    }

    return romanStr;
}

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    cout << intToRoman(num);
    return 0;
}
