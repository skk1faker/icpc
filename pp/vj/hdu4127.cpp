#include <cstring>
#include <iostream>
using namespace std;
int pad[8][8];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void dfs_change(int pad[][8], int colour, int ori_colour, int x, int y, int n) {
  if (pad[x][y] != ori_colour) {
    return;
  }
  pad[x][y] = colour;
  for (int i = 0; i < 4; i++) {
    int newx = x + dir[i][0];
    int newy = y + dir[i][1];
    if (!(0 <= newx && newx < n && 0 <= newy && newy < n))
      continue;
    dfs_change(pad, colour, ori_colour, newx, newy, n);
  }
}
int vis_map[8][8];
int g(int n, int temp_pad[][8]) {
  int vis[6] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++){
      if(vis_map[i][j] == 1)continue;
      vis[temp_pad[i][j]] = 1;
    }
  }
  int ans = 0;
  for (int i = 0; i < 6; i++)
    ans += vis[i];
  return ans;
}

void get_need_vis(int pad[][8], int ori_colour, int x, int y, int n, int *need_vis) {
  if(vis_map[x][y] == 1)return ;
  if (pad[x][y] != ori_colour) {
    need_vis[pad[x][y]] = 1;
    return;
  }
  vis_map[x][y] = 1;
  for (int i = 0; i < 4; i++) {
    int newx = x + dir[i][0];
    int newy = y + dir[i][1];
    if (!(0 <= newx && newx < n && 0 <= newy && newy < n))
      continue;
    get_need_vis(pad, ori_colour, newx, newy, n, need_vis);
  }
}
bool dfs(int ans, int now_ans, int n, int ori_pad[][8]) {
  int need_vis[6] = {0};
  memset(vis_map,0,sizeof(vis_map));
  get_need_vis(ori_pad, ori_pad[0][0], 0, 0, n,need_vis);
  int guest_value = g(n, ori_pad);
  if (ans == now_ans) {
    if (guest_value == 0)
      return true;
    else
      return false;
  }
  if (now_ans + guest_value > ans)
    return false;
  for (int colour = 0; colour < 6; colour++) {
    if (colour == ori_pad[0][0] || need_vis[colour] == 0) 
      continue;
    int temp_pad[8][8];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp_pad[i][j] = ori_pad[i][j];
      }
    }
    dfs_change(temp_pad, colour, temp_pad[0][0], 0, 0, n);
    if (dfs(ans, now_ans + 1, n, temp_pad))
      return true;
  }
  return false;
}

int main() {
  int N;
  while (scanf("%d", &N) == 1 && N != 0) {

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &pad[i][j]);
      }
    }
    for (int ans = 0; ans <= N * N; ans++) {
      if (dfs(ans, 0, N, pad)) {
        cout << ans << endl;
        break;
      };
    }
  }
  return 0;
}
