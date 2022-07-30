#ifndef __DS_LOP_H__
#define __DS_LOP_H__
#include <bits/stdc++.h>
#include "utils.h"
#include "mylib.h"
#include "DSSinhVien.h"

using namespace std;

struct Lop
{
    string maLop;
    string tenLop;
    ListSinhVien listSinhVien;
};

typedef struct DanhSachLop
{
    Lop *lop;
    int length;
} DanhSachLop;

void khoiTaoDanhSachLop(DanhSachLop &ds)
{
    ds.lop = new Lop[999];
    ds.length = 0;
}

void themLop(DanhSachLop &ds, Lop lop)
{
    ds.lop[ds.length] = lop;
    ds.length++;
}

void xoaLop(DanhSachLop &ds, string maLop)
{
    for (int i = 0; i < ds.length; i++)
    {
        if (ds.lop[i].maLop == maLop)
        {
            for (int j = i; j < ds.length - 1; j++)
            {
                ds.lop[j] = ds.lop[j + 1];
            }
            ds.length--;
            break;
        }
    }
}

Lop nhapLop(ListSinhVien &l)
{
    Lop lop;
    lop.maLop = nhapchuoi("Nhap ma lop: ");
    lop.tenLop = nhapchuoi("Nhap ten lop: ");
    lop.listSinhVien = l;
    return lop;
}

#endif // __DS_LOP_H__