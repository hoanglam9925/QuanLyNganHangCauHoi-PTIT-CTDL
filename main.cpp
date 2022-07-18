#include <bits/stdc++.h>
#include "mylib.h"
#include "menu.h"
#include "file.h"
#include "DSMonHoc.h"
#include "utils.h"
#include "DSCauHoiThi.h"

using namespace std;

int main()
{
    // mainmenu();
    CauHoiThi a[200];
    int length = 0;
    themCauHoiThi(a, length);
    themCauHoiThi(a, length);
    themCauHoiThi(a, length);
    xuatToanBoCauHoi(a, length);
    xoaCauHoiThi(a, 1, length);
     xuatToanBoCauHoi(a, length);
    return 0;
}
