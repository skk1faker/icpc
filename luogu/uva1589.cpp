#include <cstring>
#include <iostream>
using namespace std;
int attack[11][10]; // 1--10, 1--9
char chess_map[11][10];
int chess[8][3];
int dir[5][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {0, 0}};
const int h_edge = 10, w_edge = 9;
int which_chess(char val) {
  switch (val) {
  case 'G':
    return 1; // 将
  case 'R':
    return 2; // 车
  case 'H':
    return 3; // 马
  case 'C':
    return 4; // 炮
  }
  return -1;
}
bool outOfRange(int x, int y) {
  return !(1 <= x && x <= h_edge && 1 <= y && y <= w_edge);
}
void attack_scan(int chess, int x, int y) {
  switch (chess) {
  case 1: { // 将
    for (int i = x - 1; i >= 1; i--) {
      attack[i][y] = 1;
      if (chess_map[i][y] == 1)
        break;
    }
  } break;
  case 2: { // 车
    for (int i = 0; i < 4; i++) {
      for (int newx = x + dir[i][0], newy = y + dir[i][1];
           !outOfRange(newx, newy); newx += dir[i][0], newy += dir[i][1]) {
        attack[newx][newy] = 1;
        if (chess_map[newx][newy] == 1)
          break;
      }
    }
  } break;
  case 3: { // 马
    for (int i = 0; i < 4; i++) {
      int new_x = x + dir[i][0], new_y = y + dir[i][1];
      if (outOfRange(new_x, new_y) || chess_map[new_x][new_y] == 1)
        continue;
      int newx, newy;
      for (int j = 0; j < 2; j++) {
        if (dir[i][0] != 0)
          newx = x + dir[i][0] * 2;
        else
          newx = x + 2 * j - 1;
        if (dir[i][1] != 0)
          newy = y + dir[i][1] * 2;
        else
          newy = y + 2 * j - 1;
        if (!outOfRange(newx, newy))
          attack[newx][newy] = 1;
      }
    }
  } break;
  case 4: { // 炮

    for (int i = 0; i < 4; i++) { // 4个方向
      int num = 1;
      for (int newx = x + dir[i][0], newy = y + dir[i][1];
           !outOfRange(newx, newy); newx += dir[i][0], newy += dir[i][1]) {
        if (num == 0)
          attack[newx][newy] = 1;
        if (chess_map[newx][newy] == 1) {
          if (num == 0)
            break;
          num--;
        }
      }
    }
  } break;
  }
}

int main() {
  int N, x, y;
  while (scanf("%d%d%d", &N, &x, &y) == 3 && (N + x + y) != 0) {
    memset(chess, 0, sizeof(chess));
    memset(chess_map, 0, sizeof(chess_map));
    memset(attack, 0, sizeof(attack));
    for (int i = 0; i < N; i++) {
      char temp_chess;
      do {
        temp_chess = getchar();
      } while (which_chess(temp_chess) == -1);
      scanf("%d %d", &chess[i][1], &chess[i][2]);
      chess_map[chess[i][1]][chess[i][2]] = 1;
      chess[i][0] = which_chess(temp_chess);
    }
    for (int i = 0; i < N; i++) {
      attack_scan(chess[i][0], chess[i][1], chess[i][2]);
    }
    int flag = 0;
    for (int i = 0; i < 5; i++) {
      int newx = x + dir[i][0], newy = y + dir[i][1];
      if (!(1 <= newx && newx <= 3 && 4 <= newy && newy <= 6))
        continue;
      if (attack[newx][newy] == 0)
        flag = 1;
    }
    if (flag == 0)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;

    /*
    printf("chess map : \n");
    for (int i = 1; i < 11; i++) {
      for (int j = 1; j < 10; j++) {
        printf("%d", chess_map[i][j]);
      }
      printf("\n");
    }
    printf("\n");

    printf("attack_map : \n");
    for (int i = 1; i < 11; i++) {
      for (int j = 1; j < 10; j++) {
        printf("%d", attack[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    */
  }
  return 0;
}
