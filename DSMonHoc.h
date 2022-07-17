#ifndef __DS_MON_HOC_H__
#define __DS_MON_HOC_H__
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "utils.h"

typedef struct NodeMonHoc
{
    string maMon; // use str.resize(15) to fix the size of maMon
    string tenMon;
    // Ds cau hoi thi
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
    int n = nhapso("Nhap so luong mon hoc: ");
    for (int i = 1; i <= n; i++)
    {
        string maMon, tenMon;
        cout << "Nhap thong tin mon hoc thu " << i << endl;
        maMon = nhapchuoi("Nhap ma mon: ");
        cout << "Nhap ten mon: ";
        getline(cin, tenMon);
        NodeMonHoc *p = taoMonHocMoi(maMon, tenMon);
        themMonHocVaoDanhSachMonHoc(root, p);
    }
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
// void LNR(DanhSachMonHoc root)
// {
//     if (root != NULL)
//     {
//         // su dung de quy de duyet tiep cay con trai
//         LNR(root->left);
//         // xy ly NodeMonHoc goc
//         printf("%d \t", root->data);
//         // su dung de quy de duyet tiep cay con phai
//         LNR(root->right);
//     }
// }
// void LRN(DanhSachMonHoc root)
// {
//     if (root != NULL)
//     {
//         // su dung de quy de duyet tiep cay con trai
//         LRN(root->left);
//         // su dung de quy de duyet tiep cay con phai
//         LRN(root->right);
//         // xu ly NodeMonHoc goc
//         printf("%d \t", root->data);
//     }
// }

#endif