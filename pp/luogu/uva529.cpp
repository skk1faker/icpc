/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva529.cpp
*   username:     skt1faker
*   create time:  09:50  2023.05.21
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;

const int maxx = (int)1e4 + 10;
int val[maxx];
int aim;
bool dfs(int deep, int maxx_deep) {
  if ((val[deep - 1] << (maxx_deep - deep)) < aim) {
    return false;
  }
  if (deep == maxx_deep) {
    if (val[deep - 1] == aim)
      return true;
    else
      return false;
  }
  for (int i = 0; i < deep; i++) {
    for (int j = i; j < deep; j++) {
      if (deep == maxx_deep - 1) {
        if (val[i] + val[j] == aim){
          val[deep] = val[i] + val[j];
          if(dfs(deep + 1, maxx_deep))
            return true;
        }
      } else if (val[i] + val[j] > val[deep - 1] && val[i] + val[j] < aim) {
        val[deep] = val[i] + val[j];
        if (dfs(deep + 1, maxx_deep))
          return true;
      }
    }
  }
  return false;
}
int main() {

  while (scanf("%d", &aim) == 1 && aim != 0) {
    int ans = 1;
    val[0] = 1;
    for (ans = 1;; ans++) {
      if (dfs(1, ans))
        break;
    }
    for(int i = 0;i< ans;i++){
      if(i != 0)cout<<' ';  // 不加会wa, 最后一个位置不能为空格
      cout<<val[i];
    }
    cout<<endl;
  }
  return 0;
}
