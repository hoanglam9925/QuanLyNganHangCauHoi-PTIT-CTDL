#ifndef __DS_SINH_VIEN__
#define __DS_SINH_VIEN__
#include <bits/stdc++.h>
#include "utils.h"
#include "DSDiemThi.h"
using namespace std;

struct SinhVien
{
    string maSv;
    string ho;
    string ten;
    string gioiTinh; // 0: nu, 1: nam
    string password;
    DiemThi *diem;
    SinhVien *next;
};

struct ListSinhVien
{
    SinhVien *head;
    SinhVien *tail;
};

void initListSinhVien(ListSinhVien &l)
{
    l.head = NULL;
    l.tail = NULL;
}
int kiemTraDoDai(ListSinhVien l);
void sapXepSinhVien(ListSinhVien &l);
void themSinhVien(ListSinhVien &l, SinhVien *sv)
{
    if (kiemTraDoDai == 0)
        initListSinhVien(l);
    if (l.head == NULL)
    {
        l.head = sv;
        l.tail = l.head;
    }
    else
    {
        l.tail->next = sv;
        l.tail = sv;
    }
    // sapXepSinhVien(l);
}
SinhVien *taoSinhVien(string maSv, string ho, string ten, string gioiTinh, string pw)
{
    SinhVien *sv = new SinhVien;
    if (sv == NULL)
    {
        cout << "Khong du bo nho" << endl;
        return sv;
    }
    sv->maSv = maSv;
    sv->ho = ho;
    sv->ten = ten;
    sv->gioiTinh = gioiTinh;
    sv->password = pw;
    sv->next = NULL;
    return sv;
}
void xoaSinhVien(ListSinhVien &l, string maSv)
{
    SinhVien *p = l.head;
    SinhVien *q = NULL;
    while (p != NULL)
    {
        if (p->maSv == maSv)
        {
            if (p == l.head)
            {
                l.head = p->next;
            }
            else
            {
                q->next = p->next;
            }
            delete p;
            break;
        }
        q = p;
        p = p->next;
    }
}

int kiemTraDoDai(ListSinhVien l)
{
    int count = 0;
    SinhVien *p = l.head;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    cout << "So sinh vien: " << count << endl;
    return count;
}
void xuatSinhVien(ListSinhVien l)
{
    SinhVien *p = l.head;
    cout << "Do dai danh sach: ";
    kiemTraDoDai(l);
    while (p != NULL)
    {
        cout << p->maSv << " " << p->ho << " " << p->ten << " " << p->gioiTinh << " " << p->password << endl;
        p = p->next;
    }
}
void nhapSinhVien(SinhVien &sv)
{
    // sv.maSv = nhapchuoi("Nhap ma sinh vien: ", 15);
    sv.ho = nhapchuoi("Nhap ho sinh vien: ");
    sv.ten = nhapchuoi("Nhap ten sinh vien: ");
    sv.gioiTinh = nhapchuoi("Nhap gioi tinh sinh vien: ");
    sv.password = nhapchuoi("Nhap password sinh vien: ");
}

void suaSinhVien(ListSinhVien &l, string maSv)
{
    SinhVien *p = l.head;
    while (p != NULL)
    {
        if (p->maSv == maSv)
        {
            nhapSinhVien(*p);
            break;
        }
        p = p->next;
    }
}

bool kiemTraMaSv(ListSinhVien l, string maSv)
{
    SinhVien *p = l.head;
    while (p != NULL)
    {
        if (p->maSv == maSv)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

void sapXepSinhVien(ListSinhVien &l)
{
    SinhVien *p = l.head;
    while (p != NULL)
    {
        SinhVien *q = p->next;
        while (q != NULL)
        {
            if (p->maSv > q->maSv)
            {
                swap(p->maSv, q->maSv);
                swap(p->ho, q->ho);
                swap(p->ten, q->ten);
                swap(p->gioiTinh, q->gioiTinh);
                swap(p->password, q->password);
            }
            q = q->next;
        }
        p = p->next;
    }
}

#endif
