#ifndef __UTILS_H__
#define __UTILS_H__
#include <bits/stdc++.h>
#include <string>

using namespace std;

int nhapso(string msg = "")
{
    fflush(stdin);
    int a;
    cout << msg;
    while (true)
    {
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << msg;
        }
        else
        {
            return a;
        }
    }
}
string nhapchuoi(string msg = "", int maxLength = 999)
{
    fflush(stdin);
    string a;
    cout << msg;
    getline(cin, a);
    a.resize(maxLength);
    return a;
}
#endif
