#include <cstring>
#include <iostream>
using namespace std;
int map[9][9][2]; // 0 -- H, 1 -- V
int have_edge[9][9][9][2];
int cal_edge(int x, int y, int length, int mode) {
  if (have_edge[x][y][length][mode] != -1)
    return have_edge[x][y][length][mode];
  if (have_edge[x][y][length - 1][mode] == 1) {
    if (mode == 0) {
      if (have_edge[x][y + length - 1][1][0] == 1)
        return have_edge[x][y][length][0] = 1;
    } else {
      if (have_edge[x + length - 1][y][1][1] == 1)
        return have_edge[x][y][length][1] = 1;
    }
  }
  return have_edge[x][y][length][mode] = 0;
}

int main() {
  int n, m;
  int Case = 0;
  while (scanf("%d%d", &n, &m) == 2) {
    if(Case)
      printf("\n**********************************\n\n");
    printf("Problem #%d\n\n",++Case);
    memset(map, 0, sizeof(map));
    memset(have_edge, -1, sizeof(have_edge));
    for(int i =0 ;i< n;i++){
      for(int j = 0;j < n;j++){
        have_edge[i][j][1][0] = 0;
        have_edge[i][j][1][1] = 0;
      }
    }
    for (int i = 0; i < m; i++) {
      char dir;
      do {
        dir = getchar();
      } while (!(dir == 'H' || dir == 'V'));
      int x, y;
      scanf("%d%d", &x, &y);
      //printf("%d %d\n",x,y);
      x--;
      y--;
      switch (dir) {
      case 'H': {
        map[x][y][0] = 1;
        have_edge[x][y][1][0] = 1;
      } break;
      case 'V': {
        swap(x,y);
        map[x][y][1] = 1;
        have_edge[x][y][1][1] = 1;
      } break;
      }
    }
    int flag = 0;
    for (int edge_length = 1; edge_length < n;
         edge_length++) { // n个点最多n - 1条边。
      int ans = 0;
      for (int i = 0; i < n - edge_length; i++) {
        for (int j = 0; j < n - edge_length; j++) {

          cal_edge(i, j, edge_length, 0);
          cal_edge(i, j, edge_length, 1);
          cal_edge(i + edge_length, j, edge_length, 0);
          cal_edge(i, j + edge_length, edge_length, 1);
          if (cal_edge(i, j, edge_length, 0) == 1 &&
              cal_edge(i, j, edge_length, 1) == 1 &&
              cal_edge(i + edge_length, j, edge_length, 0) == 1 &&
              cal_edge(i, j + edge_length, edge_length, 1) == 1) {
            ans += 1;
            flag = 1;
          }
        }
      }
      if (ans > 0)
        printf("%d square (s) of size %d\n", ans, edge_length);
    }
    if(flag == 0){
      printf("No completed squares can be found.\n");
    }
  }
  return 0;
}
