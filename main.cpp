#include <bits/stdc++.h>
#include "mylib.h"
#include "menu.h"
#include "file.h"
#include "DSMonHoc.h"
#include "utils.h"
using namespace std;

int main()
{
    // mainmenu();

    DanhSachMonHoc root;
    khoiTaoDanhSachMonHoc(root);
    nhapMonHoc(root);
    printf("Duyet cay theo NLR\n");
    xuatDanhSachMonHoc(root);
    cout << "Tim Node:" << endl;
    string maMon = nhapchuoi("Nhap ma mon: ");
    NodeMonHoc *p = timKiemMonHoc(root, maMon);
    if (p != NULL)
    {
        cout << "Tim thay mon hoc: " << p->maMon << " - " << p->tenMon << endl;
    }
    else
    {
        cout << "Khong tim thay mon hoc" << endl;
    }
    return 0;
}
