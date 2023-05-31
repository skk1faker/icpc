/*
 *
// 这部分代码也能过。
#include <bits/stdc++.h>
#include <complex>
using namespace std;
const int maxx = 1000 + 10;
int vis[maxx][maxx];
char mp[maxx][maxx];
pair<int, int> mark[maxx][maxx];
int ans[2];
int dxy[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m;
bool in_range(int x, int y) { return (0 <= x && x <= n) && (0 <= y && y <= m); }
void dfs(int x, int y, int mode, int is_ori) {
  // printf("%d %d %d \n",x,y,mode);
  vis[x][y] = 1;
  if (mode == 0){
    (mark[x][y]).first = ans[0];
    mark[x][y].second = -1;
  }
  else
    (mark[x][y]).second = ans[1];
  for (int i = 0 + mode * 2; i < 2 + mode * 2; i++) {
    if (is_ori == 0 && i == 1 + mode * 2)
      continue;
    int newx = x + dxy[i][0];
    int newy = y + dxy[i][1];
    if (in_range(newx, newy) && vis[newx][newy] == 0 && mp[newx][newy] == '#') {
      if (is_ori == 1 && i == 1 + mode * 2)
        dfs(newx, newy, mode, 1);
      else
        dfs(newx, newy, mode, 0);
    }
  }
}
int main() {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%s", mp[i]);
    // printf("%s\n",mp[i]);
  }
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == '#' && vis[i][j] == 0) {
        // printf("%d %d\n",i,j);
        ans[0]++;
        dfs(i, j, 0, 1);
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      if (mp[i][j] == '#' && vis[i][j] == 0) {
        // printf("%d %d\n",i,j);
        ans[1]++;
        dfs(i, j, 1, 1);
      }
    }
  }
  set<pair<int, int>> se;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == '#')
        se.insert(mark[i][j]);
    }
  }
  if (ans[0] != se.size() || ans[0] != ans[1]) {
    printf("Bad placement.");
    ////std::cout<<ans[0] <<' ' <<ans[1]<<std::endl;
  } else {
    printf("There are %d ships.", ans[0]);
  }
  return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int maxx = 1000 + 10;
char mp[maxx][maxx];
int n, m;
bool in_range(int x, int y) { return (0 <= x && x < n) && (0 <= y && y < m); }
bool check(int x,
           int y) { // 不规则图形像素表示,两个像素成对角线摆放就可能会出现弧线。
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (in_range(x + i, y + j) && mp[x + i][y + j] == '#') {
        ans++;
      }
    }
  }
  return ans == 3;
}
int vis[maxx][maxx];
int dxy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y) {
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int newx = x + dxy[i][0];
    int newy = y + dxy[i][1];
    if (in_range(newx, newy) && vis[newx][newy] == 0 && mp[newx][newy] == '#') {
      dfs(newx, newy);
    }
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    scanf("%s", mp[i]);
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (check(i, j)) {
        printf("Bad placement.");
        return 0;
      }
    }
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == '#' && vis[i][j] == 0) {
        ans++;
        dfs(i, j);
      }
    }
  }
  printf("There are %d ships.", ans);
  return 0;
}
