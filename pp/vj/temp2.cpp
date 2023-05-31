#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int zen[10] = {255, 254, 252, 248, 240, 224, 192, 128, 0};
int num[10][1010];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= n; i++) {
      scanf("%d.%d.%d.%d", &num[1][i], &num[2][i], &num[3][i], &num[4][i]);
    }
    bool flag = false;
    int change = 0, mark = 0;
    for (int k = 1; k <= 4; k++) {
      for (int i = 1; i < n; i++) {
        if (num[k][i] != num[k][i + 1]) {
          change = k;
          flag = true;
          break;
        }
      }
      if (flag)
        break;
    }
    if (n == 1 || !flag){
      printf("%d.%d.%d.%d\n255.255.255.255\n", num[1][1], num[2][1], num[3][1],
             num[4][1]);
      continue;
    }
    sort(num[change] + 1, num[change] + 1 + n);
    int minn = num[change][1];
    int maxn = num[change][n];
    for (int i = 1; i <= 8; i++) {
      if ((minn % 2) != (maxn % 2))
        mark = i;
      minn /= 2;
      maxn /= 2;
    }
    int aa[6], bb[6];
    memset(aa, 0, sizeof(aa));
    memset(bb, 0, sizeof(bb));
    for (int i = 1; i <= 4; i++) {
      if (i < change) {
        aa[i] = num[i][1];
        bb[i] = zen[0];
      }
      if (i == change) {
        aa[i] = num[change][1] & zen[mark];
        bb[i] = zen[mark];
      }
      if (i > change) {
        aa[i] = 0;
        bb[i] = 0;
      }
    }
    printf("%d.%d.%d.%d\n%d.%d.%d.%d\n", aa[1], aa[2], aa[3], aa[4], bb[1],
           bb[2], bb[3], bb[4]);
  }
  return 0;
}
