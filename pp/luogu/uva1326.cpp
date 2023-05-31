/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva1326.cpp
*   username:     skt1faker
*   create time:  08:08  2023.05.29
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
int n,str[24];

map<int,int>mapp[2];
map<int,int>chois[2];

void dfs(int now_posi,int max_posi,int choise_num, int sta,int choise_stat){
  if(now_posi == max_posi){
    if(mapp[max_posi== n].count(sta) == 0){
      mapp[max_posi == n][sta] = choise_num;
      chois[max_posi == n][sta] = choise_stat;
    }
    else if(mapp[max_posi == n][sta] < choise_num){
      mapp[max_posi == n][sta] = choise_num;
      chois[max_posi == n][sta] = choise_stat;
    }
    return ;
  }
  dfs(now_posi + 1,max_posi,choise_num,sta,choise_stat) ;
  dfs(now_posi + 1,max_posi,choise_num + 1,sta ^ str[now_posi], choise_stat | (1<<now_posi)) ;
}

void solve()
{
  memset(str,0,sizeof(str));
  mapp[0].clear();
  mapp[1].clear();
  chois[0].clear();
  chois[1].clear();
  for(int i = 0;i< n;i++ ){
    char s[100];
    scanf("%s",s);
    for(int j =0 ;s[j];j++){
      str[i] ^= (1<<(s[j] - 'A'));
    }
  }
  dfs(0,n / 2,0,0,0);
  dfs(n / 2, n,0,0,0);
  int ans = 0;
  int ans_stat = 0;
  for(map<int,int>::iterator iter = mapp[0].begin();iter != mapp[0].end();iter++){
    int i = iter->first;
    if(mapp[1].count(i) == 1)
      if(ans < mapp[0][i] + mapp[1][i]){
        ans = mapp[0][i] + mapp[1][i];
        ans_stat = chois[0][i] | chois[1][i];
      }
  }
  cout<<ans<<endl;
  for(int i = 0;i < n;i++){
    if(ans_stat &(1 << i)){
      cout<<i + 1<<' ';
    }
  }
  cout<<endl;
}

int main()
{
  while(scanf("%d",&n) == 1){
    solve();
  }
  return 0;
}
