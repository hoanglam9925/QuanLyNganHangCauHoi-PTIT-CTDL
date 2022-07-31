#ifndef __MENU_H__
#define __MENU_H__
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "quanLySinhVien.h"

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
    while (!isExit)
    {
        clrscr();
        gotoxy(35, 3);
        cout << "CHUONG TRINH QUAN LY NGAN HANG CAU HOI" << endl;
        gotoxy(35, 4);
        cout << "1. Quan ly sinh vien" << endl;
        gotoxy(35, 5);
        cout << "2. Quan ly cau hoi" << endl;
        gotoxy(35, 6);
        cout << "3. Quan ly bang diem" << endl;
        gotoxy(35, 7);
        cout << "4. Thoat" << endl;
        int a = nhapso("Chon chuc nang: ");
        fflush(stdin);
        if (a == 1)
        {
            clrscr();
            quanLySv();
        }
        if (a == 2)
        {
        }
        if (a == 3)
        {
        }
        if (a == 4)
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
