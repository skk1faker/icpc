#include <cstring>
#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;
const int maxx = 100;
char pazz[5][10];
char move_list[maxx];
int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int move_dir(char dir_char) {
  switch (dir_char) {
  case 'A': {
    return 0;
  }
  case 'B': {
    return 1;
  }
  case 'L': {
    return 2;
  }
  case 'R': {
    return 3;
  }
  default: {
    return -1;
  }
  }
}
bool out_range(int i, int j) {
  // printf("%d %d\n",i,j);
  return (0 <= i) && (i <= 4) && (0 <= j) && (j <= 4);
}
int main() {
  int Case = 1;
  while (true) {
    int x, y;
    for (int i = 0; i < 5; i++) {
      fgets(pazz[i], 10, stdin); // TODO fget 行为 ?
      if (pazz[i][4] == 0)
        pazz[i][4] = ' ';
      pazz[i][5] = 0;
      // printf("%s\n",pazz[i]);
      if (pazz[0][0] == 'Z') {
        exit(0);
      }
      for (int j = 0; j < 5; j++)
        if (pazz[i][j] == ' ') {
          x = i;
          y = j;
          // printf("ori = %d %d\n",x,y);
        }
    }
    if(Case != 1)printf("\n");
    printf("Puzzle #%d:\n", Case++);
    move_list[0] = 0; //  清空字符串
    while (true) {
      scanf("%s", move_list + strlen(move_list));
      if (move_list[strlen(move_list) - 1] == '0')
        break;
    }
    getchar(); // TODO：
               // scanf之后会有一个\n没有收到,所以要将其收到，否则下一轮接受pazz的时候会出现问题。
    // printf("%s\n", move_list);
    int flag = 1;
    for (int i = 0; i < strlen(move_list) - 1; i++) {
      // TODO move
      int dir = move_dir(move_list[i]);
      if (dir == -1) {
        flag = 0;
        break;
      }
      int new_x = x + dirs[dir][0];
      int new_y = y + dirs[dir][1];

      if (!out_range(new_x, new_y) && flag == 1) {
        flag = 0;
        break;
      } else {
        swap(pazz[x][y], pazz[new_x][new_y]);
        x = new_x;
        y = new_y;
      }
    }
    if (flag == 1) {
      for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
          printf("%c", pazz[i][j]);
          if (j != 4)
            printf(" ");
        }
        printf("\n");
      }
    } else
      printf("This puzzle has no final configuration.\n");
  }
  return 0;
}

/*
Puzzle #1:
This puzzle has no final configuration.

Puzzle #2:
This puzzle has no final configuration.

Puzzle #3:
T R G S J
X O K L I
M D V B N
W P   A E
U Q H C F

Puzzle #4:
This puzzle has no final configuration.

Puzzle #5:
This puzzle has no final configuration.

Puzzle #6:
This puzzle has no final configuration.
*/
