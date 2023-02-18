#include<vector>
#include <stdio.h>
#include <string.h>
char map_bw[8][9];
char change_right(char move_right) {
  move_right = 'W' + 'B' - move_right;
  return move_right;
}

bool out_range(int x, int y) { return !(0 <= x && x < 8 && 0 <= y && y < 8); }

int dir[8][2] = {{1, -1}, {1, 0},   {1, 1},  {0, -1},
                 {0, 1},  {-1, -1}, {-1, 0}, {-1, 1}};
bool legal_move(int x, int y, char move_right) { // 判断移动是否合法
  for (int i = 0; i < 8; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    int flag = 0; // 过程检测
    while (!out_range(nx, ny)) {
      if ((flag == 0 || flag == 1) &&
          map_bw[nx][ny] == change_right(move_right)) {
        flag = 1;
      } else if (map_bw[nx][ny] == move_right && (flag == 1)) {
        // flag == 2;break;
        return true;

      } else
        break;
      nx += dir[i][0];
      ny += dir[i][1];
    }
  }
  return false;
}

void change_map(int x, int y, char move_right) {
  for (int i = 0; i < 8; i++) {
    int nx = x + dir[i][0], ny = y + dir[i][1];
    int flag = 0;
    while (!out_range(nx, ny)) {
      if ((flag == 0 || flag == 1) &&
          map_bw[nx][ny] == change_right(move_right)) {
        flag = 1;
      } else if (flag == 1 && map_bw[nx][ny] == move_right) {
        flag = 2;
        break;
      } else
        break;
      nx += dir[i][0];
      ny += dir[i][1];
    }
    if(flag == 2){
      nx = x + dir[i][0];
      ny = y + dir[i][1];
      while(!out_range(nx,ny)){
        if(map_bw[nx][ny] == move_right)break;
        map_bw[nx][ny] = move_right;
        nx += dir[i][0];
        ny += dir[i][1];
      }
    }
  }
  map_bw[x][y] = move_right;
  int b = 0,w = 0;
  for(int i = 0;i < 8;i++){
    for(int j = 0;j < 8;j++){
      if(map_bw[i][j] == 'W')w++;
      if(map_bw[i][j] == 'B')b++;
    }
  }
  printf("Black - %2d White - %2d\n",b,w);
}

void search_legal(char move_right) {
  std::vector<std::pair<int,int>>input;
  int flag = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (map_bw[i][j] == '-' && legal_move(i, j, move_right)) {
        input.push_back(std::make_pair(i, j));
        flag = 1;
      }
    }
  }
  if(flag == 0)
    printf("No legal move.");
  else {
    for(std::vector<std::pair<int,int>>:: iterator iter = input.begin();iter != input.end();iter++){
        printf("(%d,%d)",iter->first + 1,iter->second + 1);
        if(iter + 1 != input.end())printf(" ");
      }
    }
  printf("\n");
}

void solve() {
  int T;
  scanf("%d", &T);
  char move_right;
  while (T--) {
    for (int i = 0; i < 8; i++)
      scanf("%s", map_bw[i]);
    getchar();
    scanf("%c", &move_right);
    char opt[4];
    do {
      scanf("%s", opt);
      switch (opt[0]) {
      case 'Q': {
        for(int i = 0;i < 8;i++)printf("%s\n",map_bw[i]);
        if(T>0)printf("\n");
      } break;
      case 'L': {
        search_legal(move_right);
      } break;
      case 'M': {
        int x = opt[1] - '0' - 1, y = opt[2] - '0' - 1;
        if (!legal_move(x, y, move_right)) {
          move_right = change_right(move_right);
        }
        change_map(x, y, move_right);
        move_right = change_right(move_right);
      }
      }
    } while (opt[0] != 'Q');
  }
}
int main() { solve(); }
