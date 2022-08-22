#ifndef __DS_CAU_HOI_THI_H__
#define __DS_CAU_HOI_THI_H__
#include <bits/stdc++.h>
#include "mylib.h"
#include "utils.h"
#include <ctime>

using namespace std;
typedef struct CauHoiThi
{
    string noiDung;
    string a;
    string b;
    string c;
    string d;
    string dapAn;
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
    cauHoiThi[length].dapAn = nhapchuoi("Nhap dap an:");
    if (cauHoiThi[length].dapAn.compare("A") < 0 || cauHoiThi[length].dapAn.compare("D") > 0)
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
    cauHoiThi[i].dapAn = "";

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
DAPAN:
    string dapAn = nhapchuoi("Nhap dap an: ");
    if (dapAn.compare("A") < 0 || dapAn.compare("D") > 0)
    {
        cout << "Dap an khong hop le. Nhap lai: " << endl;
        goto DAPAN;
    }
    cauHoiThi[index].noiDung = noiDung;
    cauHoiThi[index].a = dapAnA;
    cauHoiThi[index].b = dapAnB;
    cauHoiThi[index].c = dapAnC;
    cauHoiThi[index].d = dapAnD;
    cauHoiThi[index].dapAn = dapAn;
}

void chonNgauNhienCauHoi(CauHoiThi cauHoiThi[], int soLuong, CauHoiThi kq[])
{
    for (int i = 0; i < soLuong; i++)
    {
        int index = rand() % soLuong;
    newLoop:
        for (int j = 0; j < i; j++)
        {
            if (kq[j].noiDung == cauHoiThi[index].noiDung)
            {
                index = rand() % soLuong;
                goto newLoop;
            }
        }
        kq[i] = cauHoiThi[index];
    }
}

int chonDapAn(CauHoiThi cauHoiThi[], int soLuong, time_t timeExpire)
{
    int soCauDung = 0;
    for (int i = 0; i < soLuong; i++)
    {
        clrscr();
        gotoxy(35, 5);
        time_t now = time(0);
        if (now - timeExpire > 0)
        {
            return soCauDung;
        }
        cout << "Thoi gian con lai " << timeExpire - now << " giay" << endl;
        cout << "Cau hoi thu " << i + 1 << endl;
        cout << "Noi dung cau hoi: " << cauHoiThi[i].noiDung << endl;
        cout << "1: " << cauHoiThi[i].a << endl;
        cout << "2: " << cauHoiThi[i].b << endl;
        cout << "3: " << cauHoiThi[i].c << endl;
        cout << "4: " << cauHoiThi[i].d << endl;
        // cout << "Dap an: " << cauHoiThi[i].dapAn << endl;
        string dapAn = nhapchuoi("Nhap dap an: ");
        if (dapAn.compare(cauHoiThi[i].dapAn) == 0)
        {
            soCauDung++;
        }
    }
    return soCauDung;
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
