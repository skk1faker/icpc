#include <bits/stdc++.h>

using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
char map_ori[202][52];
int circle[6];
int vis[202][208];
int n, m;

int get_val(int x, int y) { return (map_ori[x][y / 4] >> (3 - (y % 4)) & 1); }

bool out_range(int x, int y) {
  if (0 <= x && x <= n + 1 && 0 <= y && y <= 4 * (m + 1) - 1 + 1)
    return false;
  return true;
}

void dfs2(int x, int y) { // 访问白块
  if (vis[x][y] == 1)
    return;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int newx = x + dir[i][0];
    int newy = y + dir[i][1];
    if (out_range(newx, newy))
      continue;
    if (get_val(newx, newy) == 0)
      dfs2(newx, newy);
  }
}

int dfs1(int x, int y) { // 访问黑块
  int ans = 0;
  if (vis[x][y] == 1)
    return 0;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int newx = x + dir[i][0];
    int newy = y + dir[i][1];
    if (out_range(newx, newy) || vis[newx][newy] == 1)
      continue;
    if (get_val(newx, newy) == 1)
      ans += dfs1(newx, newy);
    else {
      ans++;
      dfs2(newx, newy);
    }
  }
  return ans;
}

int main() {
  int Case = 1;
  while (scanf("%d%d", &n, &m) == 2 && n != 0) {
    memset(vis, 0, sizeof(vis));
    memset(circle, 0, sizeof(circle));
    memset(map_ori,0,sizeof(map_ori));
    for (int i = 1; i <= n; i++) {
      scanf("%s", map_ori[i] + 1);
      for (int j = 1; j <= m; j++) {
        if ('0' <= map_ori[i][j] && map_ori[i][j] <= '9') {
          map_ori[i][j] -= '0';
        } else
          map_ori[i][j] -= 'a' - 10;
      }
    }
    dfs2(0, 0); // 访问白块
    for (int i = 1; i <= n; i++) {
      for (int j = 1 * 4; j <= 4 * (m + 1) - 1; j++) {
        if (get_val(i, j) == 1 && vis[i][j] == 0)
          circle[dfs1(i, j)]++;
      }
    }
    printf("Case %d: ", Case++);
    while (circle[1]--)
      cout << 'A';
    while (circle[5]--)
      cout << 'D';
    while (circle[3]--)
      cout << 'J';
    while (circle[2]--)
      cout << 'K';
    while (circle[4]--)
      cout << 'S';
    while (circle[0]--)
      cout << 'W';
    cout << endl;
  }
}
