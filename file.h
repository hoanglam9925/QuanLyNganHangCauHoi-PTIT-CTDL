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
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include "DSLop.h"
#include "DSCauHoiThi.h"
#include "DSDiemThi.h"

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
            string fMaSV, fHo, fTen, fGioiTinh, fPassword, fLop;
            getline(input, fMaSV, '\n');
            getline(input, fHo, '\n');
            getline(input, fTen, '\n');
            getline(input, fGioiTinh, '\n');
            getline(input, fPassword, '\n');
            getline(input, fLop, '\n');
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

bool checkFileExist(string fileName)
{
    struct stat buffer;
    return (stat(fileName.c_str(), &buffer) == 0);
}

void createFile(string fileName)
{
    ofstream output(fileName.c_str());
    output.close();
}

void docFileSinhVien(ListSinhVien &lSinhVien, string maLop)
{
    // string temp = "DSSinhVien" + maLop + ".txt";
    // const char *filename = temp.c_str();
    ifstream input("DSSinhVien.txt");
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
            SinhVien *sv = taoSinhVien(fMaSV, fHo, fTen, fGioiTinh, fPassword, fLop);
            themSinhVien(lSinhVien, sv);
        }
    }
}
void docToanBoFileSinhVien(ListSinhVien &lSinhVien)
{
    ifstream input("DSSinhVien.txt");
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
        SinhVien *sv = taoSinhVien(fMaSV, fHo, fTen, fGioiTinh, fPassword, fLop);
        themSinhVien(lSinhVien, sv);
    }
}

void luuFileSinhVien(ListSinhVien lSinhVien, string maLop)
{
    ListSinhVien tempLSV;
    initListSinhVien(tempLSV);
    docToanBoFileSinhVien(tempLSV);
    capNhatDanhSachSinhVien(tempLSV, lSinhVien);
    // string temp = "DSSinhVien" + maLop + ".txt";
    // const char *filename = temp.c_str();
    ofstream output("DSSinhVien.txt");
    if (!output)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    SinhVien *p = tempLSV.head;
    while (p != NULL)
    {
        output << p->maSv << endl;
        output << p->ho << endl;
        output << p->ten << endl;
        output << p->gioiTinh << endl;
        output << p->password << endl;
        output << p->maLop << endl;
        p = p->next;
    }
}

void docFileLop(DanhSachLop &lLop)
{
    ifstream input("DSLop.txt");
    if (!input)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    while (!input.eof())
    {
        string fMaLop, fTenLop;
        getline(input, fMaLop, '\n');
        getline(input, fTenLop, '\n');
        if (fMaLop != "")
        {
            ListSinhVien lSinhVien;
            initListSinhVien(lSinhVien);
            docFileSinhVien(lSinhVien, fMaLop);
            taoLop(lLop, fMaLop, fTenLop, lSinhVien);
        }
    }
}
void luuFileLop(DanhSachLop lLop)
{
    ofstream output("DSLop.txt");
    if (!output)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    for (int i = 0; i < lLop.length; i++)
    {

        output << lLop.lop[i].maLop << endl;
        output << lLop.lop[i].tenLop << endl;

        // Tao file sinh vien neu chua co
        // string temp = "DSSinhVien" + lLop.lop[i].maLop + ".txt";
        // const char *filename = temp.c_str();
        // if (!checkFileExist("DSSinhVien.txt"))
        // {
        //     createFile("DSSinhVien.txt");
        // }
        // luuFileSinhVien(lLop.l[i].lSinhVien, lLop.l[i].maLop);
    }
}

void scan(DanhSachMonHoc lMonHoc, ofstream &output)
{
    if (lMonHoc != NULL)
    {
        output << lMonHoc->maMon << endl;
        output << lMonHoc->tenMon << endl;
        scan(lMonHoc->left, output);
        scan(lMonHoc->right, output);
    }
}
void luuFileMonHoc(DanhSachMonHoc lMonHoc)
{
    ofstream output("DSMonHoc.txt");
    if (!output)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    scan(lMonHoc, output);
}
int docFileCauHoi(CauHoiThi cauHoiThi[], string maMon)
{
    ifstream input("DSCauHoi.txt");
    if (!input)
    {
        cout << "Khong tim thay thong tin" << endl;
        return -1;
    }
    int i = 0;
    while (!input.eof())
    {
        string fMaMon, fNoiDungCauHoi, fDapAnA, fDapAnB, fDapAnC, fDapAnD, fDapAnDung;
        getline(input, fNoiDungCauHoi, '\n');
        getline(input, fDapAnA, '\n');
        getline(input, fDapAnB, '\n');
        getline(input, fDapAnC, '\n');
        getline(input, fDapAnD, '\n');
        getline(input, fDapAnDung, '\n');
        // string to int
        int dapAnDung = atoi(fDapAnDung.c_str());
        getline(input, fMaMon, '\n');
        if (fMaMon == maMon)
        {
            cauHoiThi[i].noiDung = fNoiDungCauHoi;
            cauHoiThi[i].a = fDapAnA;
            cauHoiThi[i].b = fDapAnB;
            cauHoiThi[i].c = fDapAnC;
            cauHoiThi[i].d = fDapAnD;
            cauHoiThi[i].dapAn = dapAnDung;
            i++;
        }
    }
    return i;
}
void luuFileCauHoiThi(CauHoiThi cauHoiThi[], string maMon, int n)
{
    ofstream output("DSCauHoi.txt");
    if (!output)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        output << cauHoiThi[i].noiDung << endl;
        output << cauHoiThi[i].a << endl;
        output << cauHoiThi[i].b << endl;
        output << cauHoiThi[i].c << endl;
        output << cauHoiThi[i].d << endl;
        output << cauHoiThi[i].dapAn << endl;
        output << maMon << endl;
    }
}
void docFileMonHoc(DanhSachMonHoc &lMonHoc)
{
    ifstream input("DSMonHoc.txt");
    if (!input)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    while (!input.eof())
    {
        string fMaMonHoc, fTenMonHoc, fSoTinChi;
        getline(input, fMaMonHoc, '\n');
        getline(input, fTenMonHoc, '\n');
        if (fMaMonHoc != "")
        {
            CauHoiThi cauHoiThi[200];
            int length = docFileCauHoi(cauHoiThi, fMaMonHoc);
            taoMonHoc(lMonHoc, fMaMonHoc, fTenMonHoc, cauHoiThi, length);
        }
    }
}

void luuFileDiemThi(ListDiemThi lDiemThi)
{
    ofstream output("DSDiemThi.txt");
    if (!output)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    DiemThi *p = lDiemThi.head;
    while (p != NULL)
    {
        output << p->sinhVien.maSv << endl;
        output << p->sinhVien.maMon << endl;
        output << p->sinhVien.diem << endl;
        p = p->next;
    }
}
void docFileDiemThi(ListDiemThi &lDiemThi)
{
    ifstream input("DSDiemThi.txt");
    if (!input)
    {
        cout << "Khong tim thay thong tin" << endl;
        return;
    }
    while (!input.eof())
    {
        string fMaSinhVien, fMaMonHoc, fDiem;
        getline(input, fMaSinhVien, '\n');
        getline(input, fMaMonHoc, '\n');
        getline(input, fDiem, '\n');
        // string to float diem
        float diem = atof(fDiem.c_str());
        // int diem = atoi(fDiem.c_str());
        if (fMaSinhVien != "")
        {
            taoDiemThi(lDiemThi, fMaSinhVien, fMaMonHoc, diem);
        }
    }
}
#endif // __FILE_H__
