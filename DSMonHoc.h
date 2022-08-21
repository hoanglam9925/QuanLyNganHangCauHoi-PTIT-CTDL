#ifndef __DS_MON_HOC_H__
#define __DS_MON_HOC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "utils.h"
#include "DSCauHoiThi.h"
#include "DSLop.h"
typedef struct NodeMonHoc
{
    string maMon; // use str.resize(15) to fix the size of maMon
    string tenMon;
    CauHoiThi cauHoiThi[200];
    int length = 0;
    NodeMonHoc *left;
    NodeMonHoc *right;
};
typedef struct NodeMonHoc *DanhSachMonHoc;
DanhSachMonHoc root;

void khoiTaoDanhSachMonHoc(DanhSachMonHoc &root)
{
    root = NULL;
}
NodeMonHoc *taoMonHocMoi(string maMon, string tenMon)
{
    NodeMonHoc *p = new NodeMonHoc;
    if (p != NULL)
    {
        p->left = NULL;
        p->right = NULL;
        p->maMon = maMon;
        p->tenMon = tenMon;
    }
    return p;
}
int themMonHocVaoDanhSachMonHoc(DanhSachMonHoc &root, NodeMonHoc *p)
{
    if (root != NULL)
    {
        /**
        int string::compare (const string& str) const
        Returns:
        0 : if both strings are equal.
        A value < 0 : if *this is shorter than str or,
        first character that doesn't match is smaller than str.
        A value > 0 : if *this is longer than str or,
        first character that doesn't match is greater
         *
         */
        if (root->maMon.compare(p->maMon) > 0)
        {
            themMonHocVaoDanhSachMonHoc(root->left, p);
        }
        else if (root->maMon.compare(p->maMon) < 0)
        {
            themMonHocVaoDanhSachMonHoc(root->right, p);
        }
        else if (root->maMon.compare(p->maMon) == 0)
        {
            cout << "Khong the them mon hoc co ma mon da ton tai" << endl;
            getchar();
            getchar();
            return 0;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        root = p;
    }
}
void nhapMonHoc(DanhSachMonHoc &root)
{
    // int n = nhapso("Nhap so luong mon hoc: ");
    // for (int i = 1; i <= n; i++)
    // {
    string maMon, tenMon;
    cout << "Nhap thong tin mon hoc" << endl;
    maMon = nhapchuoi("Nhap ma mon: ", 15);
    tenMon = nhapchuoi("Nhap ten mon: ");
    NodeMonHoc *p = taoMonHocMoi(maMon, tenMon);
    themMonHocVaoDanhSachMonHoc(root, p);
    // }
}
void xuatDanhSachMonHoc(DanhSachMonHoc root)
{
    if (root != NULL)
    {
        cout << root->maMon << " " << root->tenMon << endl;
        xuatDanhSachMonHoc(root->left);
        xuatDanhSachMonHoc(root->right);
    }
}

NodeMonHoc *timKiemMonHoc(DanhSachMonHoc root, string maMon)
{
    if (root != NULL)
    {
        if (root->maMon.compare(maMon) > 0)
        {
            return timKiemMonHoc(root->left, maMon);
        }
        else if (root->maMon.compare(maMon) < 0)
        {
            return timKiemMonHoc(root->right, maMon);
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

void FindReplNode(DanhSachMonHoc &p, DanhSachMonHoc &q)
{
    if (q->left)
    {
        FindReplNode(p, q->left);
    }
    else
    {
        p->maMon = q->maMon;
        p->tenMon = q->tenMon;
        p = q;
        q = q->right;
    }
}
void xoaMonHocTrongDanhSach(DanhSachMonHoc &root, string maMon)
{
    if (root == NULL)
    {
        return;
    }
    if (root->maMon.compare(maMon) > 0)
    {
        xoaMonHocTrongDanhSach(root->left, maMon);
    }
    else if (root->maMon.compare(maMon) < 0)
    {
        xoaMonHocTrongDanhSach(root->right, maMon);
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            DanhSachMonHoc p = root;
            root = root->right;
            delete p;
        }
        else if (root->right == NULL)
        {
            DanhSachMonHoc p = root;
            root = root->left;
            delete p;
        }
        else
        {
            DanhSachMonHoc p = root;
            FindReplNode(p, p->right);
            delete p;
        }
    }
}
// DanhSachMonHoc root;
//     khoiTaoDanhSachMonHoc(root);
//     nhapMonHoc(root);
//     printf("Duyet cay theo NLR\n");
//     xuatDanhSachMonHoc(root);
//     cout << "Tim Node:" << endl;
//     string maMon = nhapchuoi("Nhap ma mon: ");
//     NodeMonHoc *p = timKiemMonHoc(root, maMon);
//     if (p != NULL)
//     {
//         cout << "Tim thay mon hoc: " << p->maMon << " - " << p->tenMon << endl;
//         xoaMonHocTrongDanhSach(root, maMon);
//         xuatDanhSachMonHoc(root);
//     }
//     else
//     {
//         cout << "Khong tim thay mon hoc" << endl;
//     }

void taoMonHoc(DanhSachMonHoc &root, string maMon, string tenMon, CauHoiThi cauHoiThi[], int length)
{
    NodeMonHoc *p = taoMonHocMoi(maMon, tenMon);
    if (p != NULL)
    {
        for (int i = 0; i < length; i++)
        {
            p->cauHoiThi[i] = cauHoiThi[i];
        }
        p->length = length;
        themMonHocVaoDanhSachMonHoc(root, p);
    }
}
void suaMonHoc(NodeMonHoc *p, string tenMon)
{
    p->tenMon = tenMon;
}

bool kiemTraMaMonHoc(DanhSachMonHoc root, string maMon)
{
    if (root != NULL)
    {
        if (root->maMon.compare(maMon) > 0)
        {
            return kiemTraMaMonHoc(root->left, maMon);
        }
        else if (root->maMon.compare(maMon) < 0)
        {
            return kiemTraMaMonHoc(root->right, maMon);
        }
        else
        {
            return true;
        }
    }
    return false;
}
#endif