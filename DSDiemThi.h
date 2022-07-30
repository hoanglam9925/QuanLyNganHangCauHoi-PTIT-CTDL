#ifndef __DS_DIEM_THI__
#define __DS_DIEM_THI__
#include <bits/stdc++.h>
#include "utils.h"

struct DiemSinhVien
{
    string maSv;
    string maMon;
    int diem;
};

struct DiemThi
{
    DiemSinhVien sinhVien;
    string maMon;
    DiemThi *next;
};

struct ListDiemThi
{
    DiemThi *head;
    DiemThi *tail;
};

void initListDiemThi(ListDiemThi &l)
{
    l.head = NULL;
    l.tail = NULL;
}

void themDiemThi(ListDiemThi &l, DiemThi dt)
{
    if (l.head == NULL)
    {
        l.head = new DiemThi;
        l.head = dt;
        l.tail = l.head;
    }
    else
    {
        l.tail->next = new DiemThi;
        l.tail = l.tail->next;
        l.tail = dt;
    }
}

void xoaDiemThi(ListDiemThi &l, string maSv, string maMon)
{
    DiemThi *p = l.head;
    DiemThi *q = NULL;
    while (p != NULL)
    {
        if (p->sinhVien.maSv == maSv && p->maMon == maMon)
        {
            if (p == l.head)
            {
                l.head = p->next;
            }
            else
            {
                q->next = p->next;
            }
        }
        q = p;
        p = p->next;
    }
}

void xuatDiemThi(ListDiemThi l)
{
    DiemThi *p = l.head;
    while (p != NULL)
    {
        cout << p->sinhVien.maSv << " " << p->maMon << " " << p->sinhVien.diem << endl;
        p = p->next;
    }
}

void suaDiemThi(ListDiemThi &l, string maSv, string maMon, int diem)
{
    DiemThi *p = l.head;
    while (p != NULL)
    {
        if (p->sinhVien.maSv == maSv && p->maMon == maMon)
        {
            p->sinhVien.diem = diem;
        }
        p = p->next;
    }
}

void nhapDiemThi(ListDiemThi &l)
{
    DiemThi dt;
    string maSv, maMon;
    int diem;
    maSv = nhapchuoi("Nhap ma sinh vien: ");
    maMon = nhapchuoi("Nhap ma mon: ");
    diem = nhapso("Nhap diem: ");
    dt.sinhVien.maSv = maSv;
    dt.sinhVien.diem = diem;
    dt.sinhVien.maMon = maMon;
    dt.maMon = maMon;
    themDiemThi(l, dt);
}
#endif