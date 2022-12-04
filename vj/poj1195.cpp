// [二维树状数组]https://www.cnblogs.com/ZJXXCN/p/12242478.html
//
#include <iostream>
const int maxx = 1024 + 10;
int tree[maxx][maxx];
int n;
void add(int x, int y, int a) {
  for (int i = x; i <= n; i += (i & (-i))) {
    for (int j = y; j <= n; j += (j & (-j))) {
      tree[i][j] += a;
    }
  }
}
int check(int x, int y) {
  int ans = 0;
  for (int i = x; i > 0; i -= (i & (-i))) {
    for (int j = y; j > 0; j -= (j & (-j))) {
      ans += tree[i][j];
    }
  }
  return ans;
}
int check(int x1, int y1, int x2, int y2) {
  return check(x2, y2) - check(x1 - 1, y2) + check(x1 - 1, y1 - 1) -
         check(x2, y1 - 1);
}
void init(int S) {
  n = S;
  for (int i = 0; i <= S; i++) {
    for (int j = 0; j <= S; j++) {
      tree[i][j] = 0;
    }
  }
}
void solve() {
  while (true) {
    int opt;
    scanf("%d", &opt);
    int val[4];
    switch (opt) {
    case 0: {
      scanf("%d", &val[0]);
      init(val[0]);
    } break;
    case 1: {
      for (int i = 0; i < 3; i++) {
        scanf("%d", &val[i]);
        val[i]++;
      }
      val[2]--;
      add(val[0], val[1], val[2]);
    } break;
    case 2: {
      for (int i = 0; i < 4; i++) {
        scanf("%d", &val[i]);
        val[i]++;
      }
      printf("%d\n", check(val[0], val[1], val[2], val[3]));
    } break;
    case 3: {
      return;
    } break;
    }
  }
  return;
}
int main() {
  solve();
  return 0;
}
