/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva10891.cpp
*   username:     skt1faker
*   create time:  23:59  2023.05.13
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
int n;
const int maxx = 101;
int val[maxx];
int sum_val[maxx];


int get_sum(int i,int j){
  return sum_val[j] - sum_val[i - 1];
}

int dp[maxx][maxx]; //表示先手得分最大值
int vis[maxx][maxx];

int dfs(int i, int j){
  if(i > j)return 0;
  if(vis[i][j] == 1)return dp[i][j];
  vis[i][j] = 1;
  int &ans = dp[i][j];
  ans = get_sum(i,j);
  for(int length = 1;length <= j - i;length++){
    ans = max(ans, get_sum(i,j) - dfs(i + length, j));
    ans = max(ans, get_sum(i,j) - dfs(i, j - length));
  }
  return dp[i][j] = ans;
}

int main()
{
  int n;
  while(scanf("%d",&n) == 1){
    if(n == 0)return 0;
    memset(vis,0,sizeof(vis));
    sum_val[0] = 0;
    for(int i = 1;i <= n;i++){
      scanf("%d",&val[i]);
      sum_val[i] = sum_val[i - 1];
      sum_val[i] += val[i];
    }
    cout<<2 * dfs(1,n) - sum_val[n]<<endl;

  }
  return 0;
}

