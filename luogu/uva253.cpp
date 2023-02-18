#include <iostream>

using namespace std;

int id_mode[3][6] = {{0,2,4,1,3,5},{1,5,2,3,0,4},{3,1,0,5,4,2}};

void rotate(int mode, char *s) {
  char ans[6];
  for (int i = 0; i < 6; i++) {
    ans[i] = s[id_mode[mode][i]];
  }
  for (int i = 0; i < 6; i++) {
    s[i] = ans[i];
  }
}
int main() {
  char s[2][7];
  char input[13];
  s[0][6] = 0;
  s[1][6] = 0;
  while (scanf("%s", input) == 1) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 6; j++) {
        s[i][j] = input[i * 6 + j];
      }
    }
    int flag = 1;
    for (int i = 0; i < 4 && flag; i++) {
      rotate(0, &s[1][0]);
      for (int j = 0; j < 4 && flag; j++) {
        rotate(1, &s[1][0]);
        for (int k = 0; k < 4 && flag; k++) {
          rotate(2, &s[1][0]);
          int temp_flag = 0;
          for (int l = 0; l < 6; l++) {
            if (s[0][l] != s[1][l]) {
              temp_flag = 1;
              break;
            }
          }
          flag = temp_flag;
        }
      }
    }
    if (flag == 0) {    // 相等
      cout<<"TRUE"<<endl;
    } else {
      cout<<"FALSE"<<endl;
    }
  }
  return 0;
}
