#ifndef __QUAN_LY_CAU_HOI_H__
#define __QUAN_LY_CAU_HOI_H__
#include <bits/stdc++.h>
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "DSSinhVien.h"
#include "DSLop.h"
#include "DSMonHoc.h"
#include "DSCauHoiThi.h"

void quanLyCauHoi(DanhSachMonHoc &lMonHoc)
{
    clrscr();
    bool isExit = false;
    bool isExist = false;

    string maMon;
    NodeMonHoc *p;
    while (!isExist)
    {
        maMon = nhapchuoi("Nhap ma mon: ");
        p = timKiemMonHoc(lMonHoc, maMon);
        if (p != NULL)
        {
            isExist = true;
        }
        else
        {
            cout << "Ma mon khong ton tai" << endl;
        }
    }
    while (!isExit)
    {
    loop:
        clrscr();
        gotoxy(35, 3);
        cout << "CHUONG TRINH QUAN LY NGAN HANG CAU HOI" << endl;
        gotoxy(35, 4);
        cout << "1. Them cau hoi" << endl;
        gotoxy(35, 5);
        cout << "2. Sua cau hoi" << endl;
        gotoxy(35, 6);
        cout << "3. Xoa cau hoi" << endl;
        gotoxy(35, 7);
        cout << "4. Xuat cau hoi" << endl;
        gotoxy(35, 8);
        cout << "5. Luu va Thoat" << endl;
        int a = nhapso("Chon chuc nang: ");
        fflush(stdin);
        if (a == 1)
        {
            themCauHoiThi(p->cauHoiThi, p->length);
        }
        if (a == 2)
        {
            int index;
            while (true)
            {
                index = nhapso("Nhap vi tri cau hoi: ");
                if (index < 0 || index >= p->length)
                {
                    cout << "Vi tri cau hoi khong hop le" << endl;
                    break;
                }
                suaCauHoi(p->cauHoiThi, index);
                break;
            }
            getchar();
        }
        if (a == 3)
        {
            int index;
            while (true)
            {
                index = nhapso("Nhap vi tri cau hoi: ");
                if (index < 0 || index >= p->length)
                {
                    cout << "Vi tri cau hoi khong hop le" << endl;
                    break;
                }
                xoaCauHoiThi(p->cauHoiThi, index, p->length);
                break;
            }
            getchar();
        }
        if (a == 4)
        {
            xuatToanBoCauHoi(p->cauHoiThi, p->length);
            getchar();
        }
        if (a == 5)
        {
            luuFileCauHoiThi(p->cauHoiThi, maMon, p->length);
            isExit = true;
        }
    }
}
#endif // __QUAN_LY_CAU_HOI_H__
