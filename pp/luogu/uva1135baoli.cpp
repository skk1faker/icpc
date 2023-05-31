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
using namespace std;
#define DEBUG 0

// 减枝 + 跳层。
int n, m;
int matrix_[4][4][4];
int vis[105]; // 0 -- pre, 1 -- now

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

// bool check(int posi, int &need_select){
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
int ans[2];
void dfs(int finish) {
  if (finish == n) {
    for (int i = 0; i < n; i++) {
      if (!check(i)) {
        return;
      }
    }
    ans[0] = 0;
    for (int i = 0; i < 100; i++) {
      ans[0] += vis[i];
    }
    if (DEBUG) {
      if (ans[1] > ans[0])
      // if(false)
      {
        cout << ans[0] << endl;
        print();
        cout << endl;
      }
    }
    ans[1] = min(ans[0], ans[1]);
    return;
  }
  int temp_vis[5];
  int status[4][2];
  for (int st = 0; st < 2 * m + 2; st++) {
    digit2status(status, st);
    int st_fir= 0;
    if(finish == n - 1)st_fir= (1<<m) - 1;
    for (int choise = st_fir; choise <m; choise++) {
      for (int i = 0; i < m; i++) {
        if (((1 << i) & choise) == 0)
          continue;
        temp_vis[i] = vis[matrix_[finish][status[i][0]][status[i][1]]];
        vis[matrix_[finish][status[i][0]][status[i][1]]] = 1;
      }

      bool now_bool = true;
      bool pre_bool;
      int ret = 0;
      int jump = finish + 1;
      for (int i = 0; i < n; i++) {
        pre_bool = now_bool;
        now_bool = check(i);
        if (pre_bool && !now_bool && jump == finish + 1 && i > jump) {
          jump = i;
        }
        if (now_bool && !pre_bool) {
          ret = 1;
          break;
        }
      }
      if (ret == 0) {
        dfs(finish + 1);
      }
      for (int i = 0; i < m; i++) {
        if (((1 << i) & choise) == 0)
          continue;
        vis[matrix_[finish][status[i][0]][status[i][1]]] = temp_vis[i];
      }
    }
  }
}

int main() {
  while (scanf("%d%d", &n, &m) == 2 && m * n != 0) {
    ans[0] = 0;
    ans[1] = n * m + 1;
    memset(vis, 0, sizeof(vis));
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
          scanf("%d", &matrix_[k][i][j]);
        }
      }
    }
    dfs(0);
    if (ans[1] == n * m + 1) {
      cout << 0 << endl;
    } else {
      cout << ans[1] << endl;
    }
    // cout<<ans[1]<<endl;
  }
  return 0;
}
