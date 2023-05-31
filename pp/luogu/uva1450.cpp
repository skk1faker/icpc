/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva1450.cpp
*   username:     skt1faker
*   create time:  11:13  2023.05.20
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 5005;

int t;
int A[MAXN], B[MAXN];

int judge(int n) {
    int cura = 0, curb = 0, num = 0; 
    int a, b;
    int ta = 0,tb = 0;
    for (int i = 0; i < t; i++) {
        cura += A[i]; 
        curb += B[i]; 
        a = max(cura - n, 0);
        b = max(curb - n, 0);
        if (a + b > num)
            return false; 
        if(a > ta)
            return false;
        if(b > tb)
            return false;
        if (cura + curb > num) 
            num++;   
        if (cura > ta)
            ta++;
        if(curb > tb)
            tb++;
    }
    return true;
}

int main() {
    int cas; 
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d", &t);         
        for (int i = 0; i < t; i++) 
            scanf("%d%d", &A[i], &B[i]);

        int L = 1, R = MAXN * 20, mid;
        while (L < R) {
            mid = (R + L) / 2; 
            if (judge(mid)) 
                R = mid;
            else
                L = mid + 1; 
        }
        printf("%d\n", L - 1); 
    }
    return 0;
}
