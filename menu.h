#ifndef __MENU_H__
#define __MENU_H__
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "quanLySinhVien.h"
#include "quanLyMonHoc.h"
#include "quanLyCauHoi.h"

using namespace std;
bool dangNhap(int);
void menuGV();
void mainmenu();
void menuSV();

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
            if (dangNhap(1))
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
            if (dangNhap(2))
            {
                //                menuSV();
            }
            getchar();
        }
        if (a == 3)
        {
            is_Exit = true; // thoat
        }
    }
}
void menuSV()
{
    clrscr();
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
        cout << "5. Quan ly bang diem" << endl;
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
        }
        if (a == 6)
        {
            isExit = true;
        }
    }
}

bool dangNhap(int role)
{
    string userName, password;
    userName = nhapchuoi("Nhap username: ");
    password = nhapchuoi("Nhap mat khau: ");
    return login(userName, password, role);
}
#endif // __MENU_H__
