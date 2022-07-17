#ifndef __MENU_H__
#define __MENU_H__
#include "mylib.h"
#include "file.h"
#include "utils.h"
using namespace std;
bool dangNhap();

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
            if (dangNhap())
            {
//                menuGV();
            }
            getchar();
        }
        if (a == 2)
        {
            if (dangNhap())
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
}

bool dangNhap()
{
    string userName, password;
    cout << "Nhap user name: ";
    cin >> userName;
    getchar();
    cout << "Nhap password: ";
    cin >> password;
    return loginSV(userName, password);
}
#endif // __MENU_H__
