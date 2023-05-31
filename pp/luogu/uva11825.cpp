/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva11825.cpp
*   username:     skt1faker
*   create time:  21:45  2023.05.14
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
const int maxx = 65536;
int dp[maxx];
int val[maxx];
int n;
void dfs(int deep, int now_posi){
  if(deep == n){
    return;
  }
  for(int i = 0;i < 2;i++){
    val[now_posi + (i << deep)] = val[i << deep] | val[now_posi];
    dfs(deep + 1, now_posi + (i << deep));
  }
}
void solve()
{
  dp[0] = 0;
  for(int S = 1;S < (1<<n);S++){
    dp[S] = (val[S] == ((1 << n) - 1));
    for(int S0 = S;S0 > 0;S0 = (S0 - 1) & S){
      dp[S] = max(dp[S], dp[S0] + (val[S - S0] == ((1 << n) - 1)));
    }
  }

}

int main()
{
  int Case = 0;
  while(scanf("%d",&n) == 1 && n != 0){
    for(int i = 0;i < n;i++){
      int m;
      scanf("%d",&m);
      val[1<<i] = 1<<i;
      for(int j =0;j < m;j++){
        int temp;
        scanf("%d",&temp);
        val[1<<i] |= 1<<temp;
      }
    }
    dfs(0,0);
    solve();
    printf("Case %d: %d\n",++Case, dp[(1<<n) - 1]);
  }

}
