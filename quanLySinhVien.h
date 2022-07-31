#ifndef __QUANLYSINHVIEN_H__
#define __QUANLYSINHVIEN_H__
#include <bits/stdc++.h>
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "DSSinhVien.h"

void quanLySv()
{
    clrscr();
    bool isExit = false;
    bool isExist = false;
    ListSinhVien lSinhVien;
    initListSinhVien(lSinhVien);
    string maLop;
    while (!isExist)
    {
        maLop = nhapchuoi("Nhap ma lop: ");
        isExist = nhapLop(maLop);
    }
    docFileSinhVien(lSinhVien, maLop);
    while (!isExit)
    {
        clrscr();
        gotoxy(35, 3);
        cout << "CHUONG TRINH QUAN LY NGAN HANG CAU HOI" << endl;
        gotoxy(35, 4);
        cout << "1. Them sinh vien" << endl;
        gotoxy(35, 5);
        cout << "2. Sua thong tin sinh vien" << endl;
        gotoxy(35, 6);
        cout << "3. Xoa sinh vien" << endl;
        gotoxy(35, 7);
        cout << "4. Xuat sinh vien" << endl;
        gotoxy(35, 8);
        cout << "5. Thoat" << endl;
        int a = nhapso("Chon chuc nang: ");
        fflush(stdin);
        if (a == 1)
        {
        }
        if (a == 2)
        {
        }
        if (a == 3)
        {
        }
        if (a == 4)
        {
            cout << "Danh sach sinh vien: " << endl;
            xuatSinhVien(lSinhVien);
            getchar();
        }
        if (a == 5)
        {
            isExit = true;
        }
    }
}
#endif
