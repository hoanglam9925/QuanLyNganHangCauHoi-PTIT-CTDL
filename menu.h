#ifndef __MENU_H__
#define __MENU_H__
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "quanLySinhVien.h"
#include "quanLyMonHoc.h"
#include "quanLyCauHoi.h"
#include "DSDiemThi.h"
#include "quanLyBangDiem.h"
#include <ctime>

using namespace std;
bool dangNhap(int, string, string);
void menuGV();
void mainmenu();
void menuSV(string);

void mainmenu() // lua chon che do nguoi dung (giao vien/ sinh vien)
{
    clrscr();
    bool is_Exit = false;

    while (!is_Exit)
    {
        system("cls");
        gotoxy(35, 3);
        cout << "CHUONG TRINH QUAN LY NGAN HANG CAU HOI" << endl;
        gotoxy(35, 4);
        cout << "1. Giao vien" << endl;
        gotoxy(35, 5);
        cout << "2. Sinh vien" << endl;
        gotoxy(35, 6);
        cout << "3. Thoat" << endl;

        int a = nhapso("Chon che do nguoi dung: ");
        fflush(stdin);
        if (a == 1)
        {
            clrscr();
            string userName, password;
            userName = nhapchuoi("Nhap username: ");
            password = nhapchuoi("Nhap mat khau: ");
            if (dangNhap(1, userName, password))
            {
                menuGV();
            }
            else
            {
                cout << "Dang nhap that bai" << endl;
                getchar();
            }
        }
        if (a == 2)
        {
            clrscr();
            string userName, password;
            userName = nhapchuoi("Nhap username: ");
            password = nhapchuoi("Nhap mat khau: ");
            if (dangNhap(2, userName, password))
            {
                menuSV(userName);
            }
            else
            {
                cout << "Dang nhap that bai" << endl;
                getchar();
            }
        }
        if (a == 3)
        {
            is_Exit = true; // thoat
        }
    }
}

void menuGV()
{
    clrscr();
    bool isExit = false;
    bool isExist = false;
    DanhSachLop llop;
    khoiTaoDanhSachLop(llop);
    docFileLop(llop);

    DanhSachMonHoc lMonHoc;
    khoiTaoDanhSachMonHoc(lMonHoc);
    docFileMonHoc(lMonHoc);

    ListDiemThi lDiemThi;
    initListDiemThi(lDiemThi);
    docFileDiemThi(lDiemThi);

    while (!isExit)
    {
    loop:
        clrscr();
        gotoxy(35, 3);
        cout << "CHUONG TRINH QUAN LY NGAN HANG CAU HOI" << endl;
        gotoxy(35, 4);
        cout << "1. Them lop" << endl;
        gotoxy(35, 5);
        cout << "2. Quan ly sinh vien" << endl;
        gotoxy(35, 6);
        cout << "3. Quan ly mon hoc" << endl;
        gotoxy(35, 7);
        cout << "4. Quan ly cau hoi" << endl;
        gotoxy(35, 8);
        cout << "5. Xuat bang diem" << endl;
        gotoxy(35, 9);
        cout << "6. Thoat" << endl;
        int a = nhapso("Chon chuc nang: ");
        fflush(stdin);
        if (a == 1)
        {
            string maLop, tenLop;
            while (true)
            {
                maLop = nhapchuoi("Nhap ma lop: ", 15);
                if (kiemTraMaLop(llop, maLop))
                {
                    cout << "Ma lop da ton tai" << endl;
                    continue;
                }
                else if (maLop == "")
                {
                    goto loop;
                }
                else
                {
                    break;
                }
            }
            tenLop = nhapchuoi("Nhap ten lop: ");
            ListSinhVien lsv;
            initListSinhVien(lsv);
            string temp = "DSSinhVien" + maLop + ".txt";
            const char *filename = temp.c_str();
            if (!checkFileExist(filename))
            {
                createFile(filename);
            }
            taoLop(llop, maLop, tenLop, lsv);
            luuFileLop(llop);
        }
        if (a == 2)
        {
            clrscr();
            quanLySv(llop);
        }
        if (a == 3)
        {
            clrscr();
            quanLyMonHoc(lMonHoc);
        }
        if (a == 4)
        {
            clrscr();
            quanLyCauHoi(lMonHoc);
        }
        if (a == 5)
        {
            clrscr();
            string maLop, maMonHoc;
            ListSinhVien lSinhVien;
            initListSinhVien(lSinhVien);
            while (true)
            {
                clrscr();
                maLop = nhapchuoi("Nhap ma lop: ", 15);
                maMonHoc = nhapchuoi("Nhap ma mon hoc: ", 15);
                if (maLop == "")
                {
                    goto loop;
                }
                else if (maMonHoc == "")
                {
                    goto loop;
                }
                if (!kiemTraMaLop(llop, maLop))
                {
                    cout << "Ma lop khong ton tai" << endl;
                    getchar();
                    continue;
                }
                if (!kiemTraMaMonHoc(lMonHoc, maMonHoc))
                {
                    cout << "Ma mon hoc khong ton tai" << endl;
                    continue;
                }
                docFileSinhVien(lSinhVien, maLop);

                xuatBangDiemTheoLop(lDiemThi, lSinhVien, maLop, maMonHoc);
                getchar();
            }
        }
        if (a == 6)
        {
            isExit = true;
        }
    }
}

void menuSV(string maSv)
{
    clrscr();
    bool isExit = false;
    DanhSachLop llop;
    khoiTaoDanhSachLop(llop);
    docFileLop(llop);

    DanhSachMonHoc lMonHoc;
    khoiTaoDanhSachMonHoc(lMonHoc);
    docFileMonHoc(lMonHoc);

    ListSinhVien lSinhVien;
    initListSinhVien(lSinhVien);

    ListDiemThi lDiemThi;
    initListDiemThi(lDiemThi);
    docFileDiemThi(lDiemThi);

largeLoop:
    while (!isExit)
    {
        clrscr();
        string maLop, maMon;
        int soCauHoi, soPhut;
        while (true)
        {
        smallLoop:
            // maSv = nhapchuoi("Nhap ma sinh vien: ", 15);
            maLop = nhapchuoi("Nhap ma lop: ", 15);
            maMon = nhapchuoi("Nhap ma mon: ", 15);
            soCauHoi = nhapso("Nhap so cau hoi: ");
            soPhut = nhapso("Nhap so phut: ");
            if (maSv == "" || maLop == "" || maMon == "" || soCauHoi < 1 || soPhut < 0)
            {
                cout << "Nhap sai" << endl;
                continue;
            }
            else
            {
                int index = timIndexLop(llop, maLop);
                if (index != -1)
                {
                    lSinhVien = llop.lop[index].listSinhVien;
                }

                if (!kiemTraMaSv(lSinhVien, maSv))
                {
                    cout << "Ma sinh vien khong hop le" << endl;
                    continue;
                }

                NodeMonHoc *p = timKiemMonHoc(lMonHoc, maMon);
                if (p == NULL)
                {
                    cout << "Ma mon khong hop le" << endl;
                    continue;
                }
                DiemThi *diem = lDiemThi.head;
                while (diem != NULL)
                {
                    if (diem->sinhVien.maSv == maSv && diem->sinhVien.maMon == maMon)
                    {
                        cout << "Sinh vien da thi mon nay" << endl;
                        goto smallLoop;
                    }
                    diem = diem->next;
                }

                if (p->length < soCauHoi)
                {
                    cout << "So cau hoi khong hop le" << endl;
                    continue;
                }
                if (p->length == 0)
                {
                    cout << "Mon hoc khong co cau hoi. Chua the thi" << endl;
                    continue;
                }

                CauHoiThi lCauHoi[200];
                chonNgauNhienCauHoi(p->cauHoiThi, soCauHoi, lCauHoi);
                time_t timeExpire = time(0) + soPhut * 60;
                int soCauDung = chonDapAn(lCauHoi, soCauHoi, timeExpire);
                float diemKq = soCauDung * 10.0 / soCauHoi;
                cout << "Diem: " << diemKq << endl;
                getchar();
                getchar();

                DiemThi *diemThi = new DiemThi;
                diemThi->maMon = maMon;
                diemThi->sinhVien.maSv = maSv;
                diemThi->sinhVien.maMon = maMon;
                diemThi->sinhVien.diem = diemKq;
                diemThi->next = NULL;

                themDiemThi(lDiemThi, diemThi);
                luuFileDiemThi(lDiemThi);
                isExit = true;
                goto largeLoop;
            }
        }
    }
}

bool dangNhap(int role, string userName, string password)
{

    return login(userName, password, role);
}
#endif // __MENU_H__
