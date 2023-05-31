/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    p1090.cpp
*   username:     skt1faker
*   create time:  22:18  2023.05.29
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  priority_queue<int,vector<int>,greater<int>> q;
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      q.push(temp);
    }
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int a, b;
      a = q.top();
      q.pop();
      b = q.top();
      q.pop();
      //cout<<a<<' '<<b<<endl;
      ans += (a + b);
      q.push(a + b);
    }
    //ans += q.top();
    q.pop();
    cout<<ans<<endl;
  }
}
