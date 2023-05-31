/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva1377.cpp
*   username:     skt1faker
*   create time:  18:50  2023.05.27
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/
#include <bits/stdc++.h>
using namespace std;

// https://blog.nowcoder.net/n/e09a505323f040dca5d655ff12e0e2ad?from=nowcoder_improve
// 所有题解都没有证明一件事，尺子长度最小时解法唯一，但是所有人都用了这个条件，记录状态的时候没有记录解法，二是记录了测量长度。导致虽然能计算出最小刻度数，但是无法保证尺子最小。

const int maxx = (1 << 21);
const int maxn = 51;
int tar[(int)1e6 + 1];
int vis[maxx];
int val[maxn];
int n;
struct node {
  int status;   // 表示了多少
  set<int> ans; // 刻度
};

void bfs() {
  node st;
  st.status = 0;
  st.ans.insert(0);
  queue<node> q;
  q.push(st);
  vis[0] = 1;
  while (!q.empty()) {
    node now = q.front();
    q.pop();
    for (int i = 0; i < n; i++) {
      if ((now.status & (1 << n)) != 0)
        continue;
      for (set<int>::iterator iter = now.ans.begin(); iter != now.ans.end();
           iter++) {
        // minus
        int posi_ = *iter - val[i];
        node new_n = now;
        if (posi_ > 0) {
          for (set<int>::iterator iter_ = now.ans.begin();
               iter_ != now.ans.end(); iter_++) {
            if (tar[abs(*iter_ - posi_)] > -1) {
              new_n.status = new_n.status | (1 << tar[abs(*iter_ - posi_)]);
            }
          }
        }
        if (vis[new_n.status] == 0) {
          new_n.ans.insert(posi_);
          if (new_n.status == (1 << n) - 1) {
            cout << new_n.ans.size() << endl;
            for (set<int>::iterator iter_ = new_n.ans.begin();
                 iter_ != new_n.ans.end(); iter_++) {
              if(iter_ != new_n.ans.begin())printf(" ");
              printf("%d", *iter_);
            }
            cout << endl;
            return;
          }
          vis[new_n.status] = 1;
          q.push(new_n);
        }
        // add
        new_n = now;
        posi_ = *iter + val[i];
        if(posi_ > val[n - 1])continue;     /// 加了这个会过，但是我认为这时不对的
        ///对于数据
        ///9
        ///1 2 4 8 3 6 12 7 14
        ///不加的输出是对的。
        for (set<int>::iterator iter_ = now.ans.begin(); iter_ != now.ans.end();
             iter_++) {
          if (tar[abs(*iter_ - posi_)] > -1) {
            new_n.status = new_n.status | (1 << tar[abs(*iter_ - posi_)]);
          }
        }
        if (vis[new_n.status] == 0) {
          new_n.ans.insert(posi_);
          if (new_n.status == (1 << n) - 1) {
            cout << new_n.ans.size() << endl;
            for (set<int>::iterator iter_ = new_n.ans.begin();
                 iter_ != new_n.ans.end(); iter_++) {
              if(iter_ != new_n.ans.begin())printf(" ");
              printf("%d", *iter_);
            }
            cout << endl;
            return;
          }
          vis[new_n.status] = 1;
          q.push(new_n);
        }
      }
    }
  }
}

int main() {
  int Case = 1;
  while (scanf("%d", &n) == 1 && n != 0) {
    printf("Case %d:\n", Case++);
    memset(tar, -1, sizeof(tar));
    memset(vis, 0, sizeof(vis));

    for (int i = 0; i < n; i++) {
      scanf("%d", &val[i]);
    }
    sort(val, val + n);
    int new_n = 0;
    tar[val[new_n]] = new_n;
    for (int i = 1; i < n; i++) {
      if (val[new_n] != val[i]) {
        new_n++;
      }
      val[new_n] = val[i];
      tar[val[new_n]] = new_n;
    }
    n = new_n + 1;
    bfs();
  }
  return 0;
}
