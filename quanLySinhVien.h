#ifndef __QUANLYSINHVIEN_H__
#define __QUANLYSINHVIEN_H__
#include <bits/stdc++.h>
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "DSSinhVien.h"
#include "DSLop.h"

void quanLySv(DanhSachLop &llop)
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
        // isExist = nhapLop(maLop);
        int index = timIndexLop(llop, maLop);
        if (index != -1)
        {
            isExist = true;
            lSinhVien = llop.lop[index].listSinhVien;
        }
    }
    // docFileSinhVien(lSinhVien, maLop);
    while (!isExit)
    {
    loop:
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
        cout << "5. Luu va Thoat" << endl;
        int a = nhapso("Chon chuc nang: ");
        fflush(stdin);
        if (a == 1)
        {
            string maSv, ho, ten, gioiTinh, pw;

            ListSinhVien allFileSinhVien;
            initListSinhVien(allFileSinhVien);
            docToanBoFileSinhVien(allFileSinhVien);

            while (true)
            {
                maSv = nhapchuoi("Nhap ma sinh vien: ", 15);
                if (maSv == "")
                {
                    goto loop;
                }
                if (kiemTraMaSv(lSinhVien, maSv) || kiemTraMaSv(allFileSinhVien, maSv))
                {
                    cout << "Ma sinh vien da ton tai" << endl;
                    continue;
                }

                else
                {
                    break;
                }
            }
            ho = nhapchuoi("Nhap ho sinh vien: ");
            ten = nhapchuoi("Nhap ten sinh vien: ");
            gioiTinh = nhapchuoi("Nhap gioi tinh sinh vien: ");
            pw = nhapchuoi("Nhap password sinh vien: ");
            SinhVien *sv = taoSinhVien(maSv, ho, ten, gioiTinh, pw);
            themSinhVien(lSinhVien, sv);
        }
        if (a == 2)
        {
            string maSv;
            while (true)
            {
                maSv = nhapchuoi("Nhap ma sinh vien can sua: ");
                if (kiemTraMaSv(lSinhVien, maSv))
                {
                    break;
                }
                else if (maSv == "")
                {
                    goto loop;
                }
                else
                {
                    cout << "Ma sinh vien khong ton tai hoac khong trong lop nay" << endl;
                    continue;
                }
            }
            suaSinhVien(lSinhVien, maSv);
        }
        if (a == 3)
        {
            string maSv;
            while (true)
            {
                maSv = nhapchuoi("Nhap ma sinh vien can xoa: ");
                if (kiemTraMaSv(lSinhVien, maSv))
                {
                    break;
                }
                else if (maSv == "")
                {
                    goto loop;
                }
                else
                {
                    cout << "Ma sinh vien khong ton tai hoac khong trong lop nay" << endl;
                    continue;
                }
            }
            xoaSinhVien(lSinhVien, maSv);
        }
        if (a == 4)
        {
            cout << "Danh sach sinh vien: " << endl;
            xuatSinhVien(lSinhVien);
            getchar();
        }
        if (a == 5)
        {
            luuFileSinhVien(lSinhVien, maLop);
            isExit = true;
        }
    }
}
#endif
