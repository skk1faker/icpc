/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva1392.cpp
*   username:     skt1faker
*   create time:  22:00  2023.05.24
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/

#include <bits/stdc++.h>
using namespace std;
const int maxx = (int)2e5 + 10;
char str[2][maxx];
struct Point {
  int sum, id;
  bool operator<(Point p) { return this->sum < p.sum; }
} po[2], q[maxx];

int main() {
  int n, p;
  int top = 0;
  int ans = 0;
  while (scanf("%d%d", &n, &p) == 2 && n != 0 && p != 0) {
    top = 0;
    ans = 0;
    scanf("%s%s", str[0], str[1]);
    po[0].sum = 0;
    for (int i = 1; i <= n; i++) {
      po[i % 2].sum = po[(i - 1) % 2].sum + 100 * (str[0][i - 1] != str[1][i - 1]) - p;
      po[i % 2].id = i;
      if (q[top].sum < po[i % 2].sum)
        q[++top] = po[i % 2];
      int l = 0, r = top;
      while (l < r) {
        int mid = (l + r) >> 1;
        if (q[mid].sum < po[i % 2].sum) {
          l = mid + 1;
        } else {
          r = mid;
        }
      }
      ans = max(ans, po[i % 2].id - q[l].id );
    }
    if(ans == 0){
      cout<<"No solution."<<endl;
    }
    else cout << ans << endl;
  }
}

