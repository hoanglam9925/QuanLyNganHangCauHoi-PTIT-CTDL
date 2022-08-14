#ifndef __DS_CAU_HOI_THI_H__
#define __DS_CAU_HOI_THI_H__
#include <bits/stdc++.h>
#include "mylib.h"
#include "utils.h"
using namespace std;
typedef struct CauHoiThi
{
    string noiDung;
    string a;
    string b;
    string c;
    string d;
    int dapAn;
};

void themCauHoiThi(CauHoiThi cauHoiThi[], int &length)
{
    clrscr();
    fflush(stdin);
    if (length >= 200) // neu da co 200 cau hoi thi thong bao loi
    {
        cout << "Da co 200 cau hoi thi. Khong the them nua." << endl;
        getchar();
        return;
    }
    cout << "Nhap noi dung cau hoi: ";
    getline(cin, cauHoiThi[length].noiDung);
    cout << "Nhap a: ";
    getline(cin, cauHoiThi[length].a);
    cout << "Nhap b: ";
    getline(cin, cauHoiThi[length].b);
    cout << "Nhap c: ";
    getline(cin, cauHoiThi[length].c);
    cout << "Nhap d: ";
    getline(cin, cauHoiThi[length].d);
dapan:
    fflush(stdin);
    cauHoiThi[length].dapAn = nhapso("Nhap dap an:");
    if (cauHoiThi[length].dapAn < 1 || cauHoiThi[length].dapAn > 4)
    {
        cout << "Dap an khong hop le. Nhap lai: " << endl;
        goto dapan;
    }
    length++;
}
/*
    @param: cauHoiThi: danh sach cau hoi thi can tac dong
    @param: index: vi tri can xoa
    @param: length: so luong cau hoi thuc te
*/
void xoaCauHoiThi(CauHoiThi cauHoiThi[], int index, int &length)
{

    int i = index;
    for (i = index; i < length; i++)
    {
        cauHoiThi[i] = cauHoiThi[i + 1];
    }
    cauHoiThi[i].noiDung = "";
    cauHoiThi[i].a = "";
    cauHoiThi[i].b = "";
    cauHoiThi[i].c = "";
    cauHoiThi[i].d = "";
    cauHoiThi[i].dapAn = 0;

    length--;
}
void xuatCauHoiThi(CauHoiThi cauHoiThi[], int index)
{
    cout << "Noi dung cau hoi: " << cauHoiThi[index].noiDung << endl;
    cout << "A: " << cauHoiThi[index].a << endl;
    cout << "B: " << cauHoiThi[index].b << endl;
    cout << "C: " << cauHoiThi[index].c << endl;
    cout << "D: " << cauHoiThi[index].d << endl;
}
void xuatToanBoCauHoi(CauHoiThi cauHoiThi[], int length)
{
    clrscr();
    cout << "Danh sach cac cau hoi thi:" << endl;
    for (int i = 0; i < length; i++)
    {
        cout << "Cau hoi thu " << i + 1 << endl;
        cout << "Noi dung cau hoi: " << cauHoiThi[i].noiDung << endl;
        cout << "A: " << cauHoiThi[i].a << endl;
        cout << "B: " << cauHoiThi[i].b << endl;
        cout << "C: " << cauHoiThi[i].c << endl;
        cout << "D: " << cauHoiThi[i].d << endl;
        cout << "Dap an: " << cauHoiThi[i].dapAn << endl;
    }
}

void suaCauHoi(CauHoiThi cauHoiThi[], int index)
{
    clrscr();
    cout << "Noi dung cau hoi: " << cauHoiThi[index].noiDung << endl;
    cout << "A: " << cauHoiThi[index].a << endl;
    cout << "B: " << cauHoiThi[index].b << endl;
    cout << "C: " << cauHoiThi[index].c << endl;
    cout << "D: " << cauHoiThi[index].d << endl;
    cout << "Dap an: " << cauHoiThi[index].dapAn << endl;
    fflush(stdin);
    string noiDung = nhapchuoi("Nhap noi dung cau hoi: ");
    string dapAnA = nhapchuoi("Nhap dap an A: ");
    string dapAnB = nhapchuoi("Nhap dap an B: ");
    string dapAnC = nhapchuoi("Nhap dap an C: ");
    string dapAnD = nhapchuoi("Nhap dap an D: ");
    int dapAn = nhapso("Nhap dap an: ");
    cauHoiThi[index].noiDung = noiDung;
    cauHoiThi[index].a = dapAnA;
    cauHoiThi[index].b = dapAnB;
    cauHoiThi[index].c = dapAnC;
    cauHoiThi[index].d = dapAnD;
    cauHoiThi[index].dapAn = dapAn;
}

// CauHoiThi a[200];
//     int length = 0;
//     themCauHoiThi(a, length);
//     themCauHoiThi(a, length);
//     themCauHoiThi(a, length);
//     xuatToanBoCauHoi(a, length);
//     xoaCauHoiThi(a, 1, length);
//      xuatToanBoCauHoi(a, length);
#endif
