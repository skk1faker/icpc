/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva1445.cpp
*   username:     skt1faker
*   create time:  16:43  2023.05.27
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;

int view[2][10];
int num[2][21];
int ans = 0;
/*
void arrange(int w,int d)
{
  for(int i =0 ;i< w;i++){
    int the_best_posi;
    for(int j  =0;j < d;j++){
      if(view[0][i] > view[1][j]){
        the_best_posi = i;
      }
      else if(view[0][i] == view[1][j]){
        the_best_posi = i;
        vis[1][the_best_posi] = 1;
        break;
      }
    }
    vis[0][i] = 1;
    ans+=view[0][i];
  }
  for(int i = 0;i < d;i++){
    if(vis[1][i] == 1)continue;
    ans+=view[1][i];
  }

  for(int i = 0;i < d;i++){
    if(vis[1][i] == 1)continue;
    int the_best_posi;
    for(int j =0 ;j < w;j++){
      if(view[1][i] > view[0][j]){
        the_best_posi = i;
      }
      else if(view[1][i] == view[0][j]){
        the_best_posi = i;
        break;
      }

    }
  }
}
  */
int main() {
  int d, w;
  while (scanf("%d%d", &d, &w) == 2 && d != 0) {
    memset(num,0,sizeof(num));
    for (int i = 0; i < d + w; i++) {
      int temp;
      scanf("%d", &temp);
      num[i < d][temp]++;
    }
    int ans = 0;
    for(int i = 1;i <= 20;i++){
      ans+=max(num[0][i],num[1][i]) * i;
    }
    cout<<ans<<endl;
  }
  return 0;
}
