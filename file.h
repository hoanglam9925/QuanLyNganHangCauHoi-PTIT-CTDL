#ifndef __FILE_H__
#define __FILE_H__
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

bool loginSV(string userName, string password)
{
    ifstream input("credentialStudent.txt");
    if (!input)
    {
        cout << "Khong tim thay thong tin" << endl;
        return false;
    }
    string fUserName, fPassword;
    while (!input.eof())
    {
        input >> fUserName;
        input >> fPassword;
        if (fUserName == userName && fPassword == password)
        {
            cout << "Dang nhap thanh cong" << endl;
            return true;
        }
    }
    return false;
}
#endif // __FILE_H__