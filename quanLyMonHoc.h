#ifndef __QUAN_LY_MON_HOC_H__
#define __QUAN_LY_MON_HOC_H__
#include <bits/stdc++.h>
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "DSSinhVien.h"
#include "DSLop.h"
#include "DSMonHoc.h"

void quanLyMonHoc(DanhSachMonHoc &lMonHoc)
{
    clrscr();
    bool isExit = false;

    while (!isExit)
    {
        clrscr();
        gotoxy(35, 3);
        cout << "CHUONG TRINH QUAN LY NGAN HANG CAU HOI" << endl;
        gotoxy(35, 4);
        cout << "1. Them mon hoc" << endl;
        gotoxy(35, 5);
        cout << "2. Sua thong tin mon hoc" << endl;
        gotoxy(35, 6);
        cout << "3. Xoa mon hoc" << endl;
        gotoxy(35, 7);
        cout << "4. Xuat mon hoc" << endl;
        gotoxy(35, 8);
        cout << "5. Luu va Thoat" << endl;
        int a = nhapso("Chon chuc nang: ");
        fflush(stdin);
        if (a == 1)
        {
            nhapMonHoc(lMonHoc);
        }
        if (a == 2)
        {
            string maMonHoc;
            while (true)
            {
                maMonHoc = nhapchuoi("Nhap ma mon hoc: ", 15);
                if (maMonHoc == "")
                {
                    break;
                }

                NodeMonHoc *p = timKiemMonHoc(lMonHoc, maMonHoc);
                if (p != NULL)
                {
                    string tenMonHoc = nhapchuoi("Nhap ten mon hoc: ");
                    suaMonHoc(p, tenMonHoc);
                }
                else
                {
                    cout << "Ma mon hoc khong ton tai" << endl;
                }
            }
        }
        if (a == 3)
        {
            string maMonHoc;
            while (true)
            {
                maMonHoc = nhapchuoi("Nhap ma mon hoc: ", 15);
                if (maMonHoc == "")
                {
                    break;
                }

                NodeMonHoc *p = timKiemMonHoc(lMonHoc, maMonHoc);
                if (p != NULL)
                {
                    xoaMonHocTrongDanhSach(lMonHoc, maMonHoc);
                }
                else
                {
                    cout << "Ma mon hoc khong ton tai" << endl;
                }
            }
        }
        if (a == 4)
        {
            cout << "Danh sach mon Hoc: " << endl;
            xuatDanhSachMonHoc(lMonHoc);
            getchar();
        }
        if (a == 5)
        {
            luuFileMonHoc(lMonHoc);
            isExit = true;
        }
    }
}

#endif