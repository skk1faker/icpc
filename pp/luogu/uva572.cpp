#include <bits/stdc++.h>

using namespace std;

const int maxx = 100 + 1;
char map_oil[maxx][maxx];
bool vis[maxx][maxx];

int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1},
                 {0, 1},   {1, -1}, {1, 0},  {1, 1}};

int n, m;
bool outrange(int x,int y){
    if(0 <= x && x < n && 0 <= y && y < m)return false;
    else return true;

}

void dfs(int x, int y) {
  if(outrange(x,y))return ;
  if(vis[x][y] == true)return ;
  vis[x][y] = true;
  if(map_oil[x][y] == '*')return ;
  for(int i = 0;i< 8; i++){
    int new_x = x + dir[i][0];
    int new_y = y + dir[i][1];
    dfs(new_x,new_y);

  }
}

int main() {
  while (scanf("%d%d", &n, &m) == 2 && n != 0) {
    for (int i = 0; i < n; i++) {
      scanf("%s", map_oil[i]);
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (map_oil[i][j] == '@' && vis[i][j] == 0) {
          ans++;
          dfs(i, j);
        }
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
