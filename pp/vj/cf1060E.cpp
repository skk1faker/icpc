/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    cf1060E.cpp
*   username:     skt1faker
*   create time:  20:59  2023.05.12
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
#define ll long long 
using namespace std;

const int maxx = (int)2e5 + 10;
int dp[maxx][2];
vector<int> G[maxx];
ll val[maxx];

void dfs_dp(int now_posi, int root_posi){
  dp[now_posi][0] = 1; // bi到达now_posi使用跳跃节点的方式（下一步一定会增加1距离, 所以now_posi也算在这里）
  dp[now_posi][1] = 0; // 
  for(int i = 0;i < G[now_posi].size();i++){
    int j = G[now_posi][i];
    if(j == root_posi)continue;
    dfs_dp(j,now_posi);
    dp[now_posi][0] += dp[j][1];
    dp[now_posi][1] += dp[j][0];
    val[now_posi] += val[j] + dp[j][0];
  }
}


ll ans = 0;
void dfs_val(int now_posi,int root_posi)
{
  ans += val[now_posi];
  for(int i = 0;i < G[now_posi].size();i++){
    int j = G[now_posi][i];
    if(j == root_posi)continue;
    // 一些数组的维护可以视为下面的两个阶段
    // 首先将树分开，分为两个树
    // 将森林合并，根节点交换父子关系
    //
    // 1. 先分开为两个树
    // 分开父节点
    dp[now_posi][0] -= dp[j][1];
    dp[now_posi][1] -= dp[j][0];
    val[now_posi] -= dp[j][0] + val[j];
    // 2. 重新生成树
    // 差生新的父子关系
    dp[j][0] += dp[now_posi][1];
    dp[j][1] += dp[now_posi][0];
    val[j] += val[now_posi] + dp[now_posi][0];
    dfs_val(j,now_posi);
    dp[j][0] -= dp[now_posi][1];
    dp[j][1] -= dp[now_posi][0];
    val[j] -= val[now_posi] + dp[now_posi][0];
    dp[now_posi][0] += dp[j][1];
    dp[now_posi][1] += dp[j][0];
    val[now_posi] += dp[j][0] + val[j];
  }
}

int main(){
  int n;
  cin>>n;
  for(int i = 0;i < n - 1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs_dp(1,-1);
  dfs_val(1,-1);
  cout<<ans/2<<endl;
  return 0;
}
