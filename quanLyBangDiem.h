#ifndef __QUAN_LY_BANG_DIEM_H__
#define __QUAN_LY_BANG_DIEM_H__
#include <bits/stdc++.h>
#include "mylib.h"
#include "file.h"
#include "utils.h"
#include "DSSinhVien.h"
#include "DSLop.h"
#include "DSDiemThi.h"

void xuatBangDiemTheoLop(ListDiemThi lDiem, ListSinhVien lSinhVien, string maLop, string maMon)
{
    DiemThi *pDiem = lDiem.head;
    ListDiemThi lDiemNew;
    initListDiemThi(lDiemNew);

    SinhVien *pSinhVien = lSinhVien.head;
    while (pSinhVien != NULL)
    {
        if (pSinhVien->maLop == maLop)
        {
            while (pDiem != NULL)
            {
                if (pDiem->sinhVien.maSv == pSinhVien->maSv && pDiem->maMon == maMon)
                {
                    themDiemThi(lDiemNew, pDiem);
                }
                pDiem = pDiem->next;
            }
        }
        pSinhVien = pSinhVien->next;
    }

    DiemThi *pNewDiem = lDiemNew.head;
    while (pNewDiem != NULL)
    {
        cout << pNewDiem->sinhVien.maSv << "\t" << pNewDiem->sinhVien.diem << endl;
        // cout << pNewDiem->sinhVien.maSv << "\t" << pNewDiem->sinhVien.ho << "\t" << pNewDiem->sinhVien.ten << "\t" << pNewDiem->sinhVien.gioiTinh << "\t" << pNewDiem->maMon << "\t" << pNewDiem->diem << endl;
        pNewDiem = pNewDiem->next;
    }
}
#endif