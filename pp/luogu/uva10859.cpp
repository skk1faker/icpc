/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva10859.cpp
*   username:     skt1faker
*   create time:  16:20  2023.05.14
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

const int maxx = (int)1e3 + 10;
int dp[maxx][2], f[maxx][2];  // 
int vis[maxx];
vector<int> G[maxx];
void dfs(int now_posi,int root_posi){
  vis[now_posi] = 1;
  dp[now_posi][1] = 1;
  dp[now_posi][0] = 0;
  f[now_posi][1] = 0; // now_posi亮, f[now_posi][1]表示子的双边值
  f[now_posi][0] = 0; // now_posi暗, f[now_posi][0]表示子的双边值
  for(int i = 0;i < G[now_posi].size();i++){
    int j = G[now_posi][i];
    if(j == root_posi)
      continue;
    dfs(j,now_posi);
    dp[now_posi][0] += dp[j][1];
    f[now_posi][0] += f[j][1];
    if(dp[j][1] == dp[j][0]){
      if(f[j][0] > f[j][1] + 1){
        dp[now_posi][1] += dp[j][0];
        f[now_posi][1] += f[j][0];
      }
      else {
        dp[now_posi][1] += dp[j][1];
        f[now_posi][1] += f[j][1] + 1;
      }
    }
    else{
      if(dp[j][1] < dp[j][0]){
        dp[now_posi][1] += dp[j][1];
        f[now_posi][1] += f[j][1] + 1;
      }
      else {
        dp[now_posi][1] += dp[j][0];
        f[now_posi][1] += f[j][0];
      }
    }

  }

}

int main(){
  int T;
  cin>>T;
  while(T--){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i< n;i++)G[i].clear();
    for(int i =0;i < m;i++){
      int a,b;
      scanf("%d%d",&a,&b);
      G[a].push_back(b);
      G[b].push_back(a);
    }
    memset(vis,0,sizeof(vis));
    int ans1 = 0, ans2 = 0;
    for(int i = 0;i < n;i++){
      if(vis[i] == 0){
        dfs(i, -1);
        if(dp[i][0] == dp[i][1]){
          if(f[i][0] > f[i][1]){
            ans1 += dp[i][0];
            ans2 += f[i][0];
          }
          else {
            ans1 += dp[i][1];
            ans2 += f[i][1];
          }
        }
        else {
          if(dp[i][0] < dp[i][1]){

            ans1 += dp[i][0];
            ans2 += f[i][0];
          }
          else {
            ans1 += dp[i][1];
            ans2 += f[i][1];
          }
        }
      }
    }
    printf("%d %d %d\n",ans1, ans2, m - ans2);
  }
  return 0;
}
