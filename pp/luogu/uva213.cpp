#include <iostream>
using namespace std;
int getchar_01() {
  char ans;
  do {
    ans = getchar();
  } while (!(ans == '0' || ans == '1'));
  return ans - '0';
}

char coding[7][256];
int main() {
  char input[265];
  while (fgets(input, 256, stdin) != 0) {
    //printf("%s\n",input);
    int length = 1, num = 0;
    for (int i = 0; input[i] != 0; i++) {
      coding[length - 1][num] = input[i];
      num++;
      if(num == (1<<length) - 1){
        length++;
        num = 0;
      }
    }
    while (true) {
      length = 0;
      for (int i = 0; i < 3; i++) {
        length *= 2;
        length += getchar_01();
      }
      if(length == 0)break;
      while (true) {
        int code = 0;
        for (int i = 0; i < length; i++) {
          code *= 2;
          code += getchar_01();
        }
        if(code == (1 << length) - 1)break;
        else cout<<coding[length - 1][code];
      }
    }
    printf("\n");
    getchar();
    getchar();
  }
  return 0;
}
