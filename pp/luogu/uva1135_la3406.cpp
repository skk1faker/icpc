/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva1135_la3406.cpp
*   username:     skt1faker
*   create time:  08:38  2023.05.15
    email:        skk1faker@163.com
*   descripe:
*
* https://blog.csdn.net/qq_34446253/article/details/53052961
================================================================*/

#include <bits/stdc++.h>
#include <valarray>
#define DEBUG 0
#define DEBUGa 0
using namespace std;

// 减枝 + 跳层。
int n, m;
int matrix_[5][5][5];
int vis[105]; // 0 -- pre, 1 -- now
int choise_list[5];
int ans[2];

void print() {
  for (int i = 0; i <= 99; i++) {
    if (vis[i] == 1)
      printf("%-3d", i);
  }
  cout << endl;
  for (int i = 0; i < m; i++) {
    for (int k = 0; k < n; k++) {
      for (int j = 0; j < m; j++) {
        int val_temp = matrix_[k][i][j];
        if (vis[val_temp] == 1)
          val_temp *= -1;
        printf("%-4d", val_temp);
      }
      printf("  ");
    }
    cout << endl;
  }
}
void digit2status(int stat[][2], int now_posi) {
  if (now_posi < 2) { //  对角线
    for (int i = 0; i < m; i++) {
      stat[i][0] = i;
      if (now_posi == 0)
        stat[i][1] = i;
      else
        stat[i][1] = m - 1 - i;
    }
  } else if (((now_posi - 2) / m) == 0) {
    int p = (now_posi - 2) % m;
    for (int i = 0; i < m; i++) {
      stat[i][0] = p;
      stat[i][1] = i;
    }
  } else {
    int p = (now_posi - 2) % m;
    for (int i = 0; i < m; i++) {
      stat[i][1] = p;
      stat[i][0] = i;
    }
  }
}
bool check(int posi) {
  int xy[4][2];
  for (int i = 0; i < 2 * m + 2; i++) {
    digit2status(xy, i);
    int flag = 0;
    for (int j = 0; j < m; j++) {
      if (vis[matrix_[posi][xy[j][0]][xy[j][1]]] == 0) {
        flag = 1;
      }
    }
    if (flag == 0)
      return true;
  }
  return false;
}
bool check_inter(int posi1, int posi2){
  int stat[4][2];
  for(int i = posi1;i <= posi2;i++){
    digit2status(stat, choise_list[i]);
    for(int j = 0;j < m;j++){
      //if(vis[matrix_[i][stat[j][0]][stat[j][1]]] == 0)ans[0]++;
      vis[matrix_[i][stat[j][0]][stat[j][1]]] = 1;
    }
  }
  digit2status(stat, choise_list[posi1]);
  for(int k = 0;k < m;k++){
    int flag = 0;
    int val = matrix_[posi1][stat[k][0]][stat[k][1]];
    vis[val] = 0;
    for(int i = posi1;i <= posi2;i++){
      if(check(i)){
        flag = 1;
        break;
      }
    }
    vis[val] = 1;
    if(flag == 0)return true;
  }
  return false;
}
void dfs(int finish) {
  if (finish == n) {
    int stat[4][2];
    memset(vis,0,sizeof(vis));
    ans[0] = 0;
    for(int i = 0;i < n;i++){
      digit2status(stat, choise_list[i]);
      for(int j = 0;j < m;j++){
        //if(vis[matrix_[i][stat[j][0]][stat[j][1]]] == 0)ans[0]++;
        vis[matrix_[i][stat[j][0]][stat[j][1]]] = 1;
      }
      int k1,k2;
      for(k1 = 1;k1 < n;k1++){
        if(!check(k1))break;
      }
      k1--;
      for(k2 = n - 1;k2 >=0;k2--){
        if(check(k2))break;
      }
      if(k1 != k2){
        if(!check_inter(i,k2)){
          return;
        }
      }
      //i = k2;
      /*
      bool pre_stat ;
      bool now_stat = true;
      int k;
      int k1;
      for(k =i;k< n;k++){
        pre_stat = now_stat;
        now_stat = check(k);
        if(now_stat && pre_stat)k1 = k;
        if(now_stat &&  !pre_stat){
          break;
        }
      }
      if(now_stat &&  !pre_stat){
        for(k = n - 1;k>= 0;k--)
          if(check(k))break;
        if(!check_inter(k1,k)){
          return ;
        }
        //i = k;
      }
      */
    }
    ans[0] = 0;
    for(int i =0;i < 100;i++)ans[0]+=vis[i];
    if(DEBUGa){
      if(ans[1] > ans[0]){
        cout<<"start"<<endl;
        cout<<ans[0] << endl;;
        print();
        cout<<endl;
      }
    }
    ans[1] = min(ans[0], ans[1]);
    return;
  }
  for (int st = 0; st < 2 * m + 2; st++) {
    choise_list[finish] = st;
    dfs(finish + 1);
  }
}

int main() {
  int Case = 0;
  while (scanf("%d%d", &n, &m) == 2 && m * n != 0) {
    Case++;
    bool output_input = false;//(Case == 58  ||Case == 62||Case == 1);
    if(DEBUG && output_input){
        printf("%d %d\n",n,m);
    }
    ans[0] = 0;
    ans[1] = n * m + 1;
    memset(vis, 0, sizeof(vis));
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          scanf("%d", &matrix_[k][i][j]);
          if(DEBUG && output_input){
              printf("%d ", matrix_[k][i][j]);
          }
        }
      }
      if(DEBUG && output_input){
          cout<<endl;
      }
    }
    dfs(0);
    if(!DEBUG){
    if (ans[1] == n * m + 1) {
      cout << 0 << endl;
    } else {
      cout << ans[1] << endl;
    }
    }
  }
  return 0;
}
