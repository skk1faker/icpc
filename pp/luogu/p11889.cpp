/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    p11889.cpp
*   username:     skt1faker
*   create time:  11:01  2023.05.21
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
const int maxx = 1001;
const int maxn = 51;
int dir[maxx][2];

char mapp[maxn][maxn];
int n,m,length;
int vis[maxx][maxn][maxn];
void dfs(int finish, int x,int y){  // finish， 即将要走的方向
  if(mapp[x][y] == 'X')return;
  if(vis[finish][x][y] == 1)return ;
  vis[finish][x][y] = 1;
  if(finish == length){
    mapp[x][y] = '*';
    return ;
  }
  int new_x = x + dir[finish][0];
  int new_y = y + dir[finish][1];
  if(0 <= new_x && new_x < n && 0 <= new_y &&new_y < m){
    dfs(finish + 1,new_x,new_y);
    dfs(finish, new_x,new_y);
  }
  
}

int main()
{
  int st[2];
  while(scanf("%d%d",&n,&m) == 2){
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n;i++){
      scanf("%s",mapp[i]);
      for(int j = 0;j < m;j++){
        if(mapp[i][j] == '*'){
          st[0] = i;
          st[1] = j;
          mapp[i][j] = '.';
        }
      }
    }
    scanf("%d",&length);
    for(int i = 0;i < length;i++){
      char dir_str[10];
      scanf("%s",dir_str);
      if(dir_str[0] == 'N'){
        dir[i][0] = -1;
        dir[i][1] = 0;
      }
      else if(dir_str[0] == 'S'){
        dir[i][0] = 1;
        dir[i][1] = 0;
      }
      else if(dir_str[0] == 'W'){
        dir[i][0] = 0;
        dir[i][1] = -1;
      }
      else if(dir_str[0] == 'E'){
        dir[i][0] = 0;
        dir[i][1] = 1;
      }
    }
    dfs(0,st[0],st[1]);
    for(int i = 0;i < n;i++){
      printf("%s\n",mapp[i]);
    }
  }
}
