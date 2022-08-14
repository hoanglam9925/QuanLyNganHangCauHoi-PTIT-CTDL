#ifndef __FILE_H__
#define __FILE_H__
#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <string>
#include "DSSinhVien.h"
#include "DSMonHoc.h"
#include "DSCauHoiThi.h"
#include "DSDiemThi.h"
#include "utils.h"
#include "mylib.h"
#include <cstring>

using namespace std;
/*
    @param: role: 1: giao vien, 2: sinh vien
*/
bool login(string userName, string password, int role)
{
    if (role == 2)
    {
        ifstream input("DSSinhVien.txt");
        if (!input)
        {
            cout << "Khong tim thay thong tin" << endl;
            return false;
        }
        string fMaSV, fHo, fTen, fGioiTinh, fPassword, fLop;

        while (!input.eof())
        {
            input >> fMaSV;
            input >> fHo;
            input >> fTen;
            input >> fGioiTinh;
            input >> fPassword;
            input >> fLop;
            if (fMaSV == userName && fPassword == password)
            {
                cout << "Dang nhap thanh cong" << endl;
                return true;
            }
        }
        return false;
    }
    else
    {
        ifstream input("credentialTeacher.txt");
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
}

bool nhapLop(string maLop)
{
    ifstream input("DSLop.txt");
    if (!input)
    {
        cout << "Khong tim thay thong tin" << endl;
        return false;
    }
    string fMaLop;
    while (!input.eof())
    {
        input >> fMaLop;
        if (fMaLop == maLop)
        {
            cout << "Nhap thanh cong" << endl;
            return true;
        }
    }
    return false;
}

void docFileSinhVien(ListSinhVien &lSinhVien, string maLop)
{
	string temp = "DSSinhVien" + maLop + ".txt";
	const char * filename = temp.c_str();
    ifstream input(filename);
    if (!input)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    while (!input.eof())
    {
        string fMaSV, fHo, fTen, fGioiTinh, fPassword, fLop;
        getline(input, fMaSV, '\n');
        getline(input, fHo, '\n');
        getline(input, fTen, '\n');
        getline(input, fGioiTinh, '\n');
        getline(input, fPassword, '\n');
        getline(input, fLop, '\n');
        if (fLop == maLop)
        {
            SinhVien *sv = taoSinhVien(fMaSV, fHo, fTen, fGioiTinh, fPassword);
            themSinhVien(lSinhVien, sv);
        }
    }
}
void luuFileSinhVien(ListSinhVien lSinhVien, string maLop)
{
	string temp = "DSSinhVien" + maLop + ".txt";
	const char * filename = temp.c_str();
    ofstream output(filename);
    if (!output)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    SinhVien *p = lSinhVien.head;
    while (p != NULL)
    {
        output << p->maSv << endl;
        output << p->ho << endl;
        output << p->ten << endl;
        output << p->gioiTinh << endl;
        output << p->password << endl;
        output << maLop << endl;
        p = p->next;
    }
}
#endif // __FILE_H__
