# dp + 整数分块

1. 整数分块

2. 取整函数a = floor(n / b)，已知n,a则b的范围为多少.

3. https://www.luogu.com.cn/problem/P5307

   ```cpp
   /*================================================================
   *   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
   *
   *   filename：    p5307.cpp
   *   username:     skt1faker
   *   create time:  22:10  2023.05.31
       email:        skk1faker@163.com
   *   descripe:
   *
   ================================================================*/
   
   #include <bits/stdc++.h>
   
   using namespace std;
   const int maxx = 2e3 + 10;
   const int maxn = 310;
   const long long mod = (int)1e9 + 7;
   
   int val[maxn][maxn];
   long long dp[2][maxn][maxx];
   
   int d[maxx];
   int rd[(int)1e6 + 10];
   
   int main() {
     int l, c, s;
     while (scanf("%d%d%d", &l, &c, &s) == 3) {
       for (int i = 1; i <= l; i++) {
         for (int j = 1; j <= c; j++) {
           scanf("%d", &val[i][j]);
         }
       }
       // 分块
       int cnt = 0;
       for (int i = s; i >= 1; i--) {
         int val_d = ((s + i - 1) / i); // val * i >= s
         rd[val_d] = cnt;
         d[cnt++] = val_d;
         i = ((s + val_d - 1)/ val_d);
         //cout<<i<<endl;
       }
       memset(dp, 0, sizeof(dp));
       dp[1][1][rd[(s + val[1][1] - 1) / val[1][1]]] = 1;
       for (int i = 1; i <= l; i++) {
         if(i != 1)memset(dp[i % 2],0,sizeof(dp[i % 2]));
         for (int j = 1; j <= c; j++) {
           if(i == 1 && j == 1)continue;
           for (int k = 0; k < cnt; k++) {
             //int now_mo = ((s + d[k] - 1) / d[k]) * val[i][j];
             //int now_k = rd[(s + now_mo - 1) / now_mo];
             int now_k = rd[(d[k] + val[i][j] - 1)/ val[i][j]];
             dp[i % 2][j][now_k] += dp[(i - 1) % 2][j][k] + dp[i % 2][j -1][k];
             dp[i % 2][j][now_k] %= mod;
           }
         }
       }
       cout << dp[l % 2][c][rd[1]] << endl;
     }
     return 0;
   }
   
   ```

   

