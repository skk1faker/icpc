/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    p5691.cpp
*   username:     skt1faker
*   create time:  22:26  2023.05.23
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
const int maxx = 150 * 150 * 150 + 10;
int val[2][maxx];
int p[7],k[7];
int n,m;
int x[7];

int fun(int mode)
{
  int ret = 0;
  if(mode == 0){
    for(int i = 0;i < n / 2;i++){
      ret += k[i] *pow(x[i], p[i]);
    }
  }
  else {
    for(int i = n / 2,j = 0;i < n;i++,j++){
      ret += k[i] *pow(x[j], p[i]);
    }
    ret *= -1;
  }
  return ret;
}

int posi[2];
void dfs(int deep, int need_deep,int mode){
  if(deep == need_deep){
    int ans = fun(mode);
    val[mode][posi[mode]] = ans;
    posi[mode]++;
    return ;
  }
  for(x[deep] = 1;x[deep] <= m;x[deep]++){
    dfs(deep + 1, need_deep, mode);
  }
}


long long  solve(){
  posi[0] = 0;
  posi[1] = 0;
  dfs(0,n / 2,0);
  dfs(0,n - n / 2,1);
  std::sort(val[0],val[0] + posi[0]);
  std::sort(val[1],val[1] + posi[1]);

  long long ret = 0;
  int l = -1,r = 0;
  while(l < posi[0] && r < posi[1]){
    int temp_[2] = {0};
    l++;
    while(val[0][l] == val[0][l + 1] && l + 1 < posi[0]){
      l++;
      temp_[0]++;
    }
    while(val[1][r] <= val[0][l] && r < posi[1]){
      if(val[1][r] == val[0][l]){
        temp_[1]++;
      }
      r++;
    }
    ret += (temp_[0] + 1) * temp_[1];
  }
  return ret;
}

int main()
{
  scanf("%d",&n);
  scanf("%d",&m);
  for(int i =0 ;i< n;i++){
    scanf("%d%d",&k[i],&p[i]);
  }
  cout<<solve();

  return 0;
}
