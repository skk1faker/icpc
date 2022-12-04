#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

class Status {
public:
  int x[4], set_id; // set_id 在那个set中
  Status() {
    for (int i = 0; i < 4; i++) {
      this->x[i] = 0;
    }
    set_id = -1;
  }
  void operator=(const Status &temp) {
    for (int i = 0; i < 4; i++)
      this->x[i] = temp.x[i];
    this->set_id = temp.set_id;
  }
  int hash() {
    int a[4];
    memcpy(a, x, sizeof(x));
    sort(a, a + 4);
    int ans = 0;
    for (int i = 0; i < 4; i++) {
      ans *= 64;
      ans += a[i];
    }
    return ans;
  }
  bool check(int posi) {
    for (int i = 0; i < 4; i++) {
      if (posi == this->x[i])
        return true;
    }
    return false;
  }
};
unordered_set<int> vis[2];
// bug : int dir[4] = {-8, 8, 1, -1};
// 我真的疯了！！！
//
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool dbfs(Status st, Status en) {
  if (st.hash() == en.hash())
    return true;
  st.set_id = 0;
  en.set_id = 1;
  vis[0].clear();
  vis[1].clear();
  queue<Status> q[2];
  q[0].push(st);
  q[0].push(en);
  vis[st.set_id].insert(st.hash());
  vis[en.set_id].insert(en.hash());
  int length = 0; // 当前最短路径长度
  int set_id = 0;
  while (length < 8 && !(q[0].empty() && q[1].empty())) {
    if ((!q[set_id].empty()) && length < 8) {
      while (!q[set_id].empty()) {
        Status now_status = q[set_id].front();
        q[set_id].pop();
        for (int i = 0; i < 4; i++) { // 4个点
          int ori_posi = now_status.x[i];
          for (int j = 0; j < 4; j++) { // 4个方向
            int nx = ori_posi / 8 + dir[j][0];
            int ny = ori_posi % 8 + dir[j][1];
            
            if (!(0 <= nx && nx < 8 && 0 <= ny && ny < 8))
              continue;
            if (now_status.check(nx * 8 + ny)) { // 交汇
              nx += dir[j][0];
              ny += dir[j][1];
              if ((!(0 <= nx && nx < 8 && 0 <= ny && ny < 8)) ||
                  now_status.check(nx * 8 + ny))
                continue;
            }
            now_status.x[i] = nx * 8 + ny;
            int new_code = now_status.hash();
            if (vis[now_status.set_id ^ 1].count(new_code) == 1) {
              //printf("length = %d\n", length);
              return true;
            }
            if (vis[now_status.set_id].count(new_code) == 1) {
              now_status.x[i] = ori_posi;
              continue;
            }
            q[set_id ^ 1].push(now_status);
            vis[now_status.set_id].insert(new_code);
            now_status.x[i] = ori_posi;
          }
        }
      }
      length += 2;
    }
    set_id ^= 1;
  }

  return false;
}

int main() {
  Status st, en;
  while (true) {
    for (int _ = 0; _ < 2; _++) {
      for (int i = 0; i < 4; i++) {
        int x, y;
        if (scanf("%d%d", &x, &y) != 2)
          exit(0);
        if (_ == 0)
          st.x[i] = ((x - 1) * 8 + (y - 1));
        else
          en.x[i] = ((x - 1) * 8 + (y - 1));
      }
    }
    if (dbfs(st, en)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
