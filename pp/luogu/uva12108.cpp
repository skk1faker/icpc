#include <iostream>
using namespace std;

const int maxx = 2520;
struct status {
  int A, B, C, now_st, pre_st; // 1 -- sleep 0 -- not sleep
} s[10];

int main() {
  int n;
  int Case = 1;
  while (scanf("%d", &n) == 1 && n != 0) {
    printf("Case %d: ",Case++);
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &s[i].A, &s[i].B, &s[i].C);
      s[i].C--;
      // printf("%d %d %d\n",s[i].A, s[i].B, s[i].C);
      s[i].pre_st = 1;
    }
    int sum = 0, t;
    for (t = 0; t <= maxx; t++) {
      sum = 0;
      for (int i = 0; i < n; i++)
        sum += s[i].pre_st;
      if (sum == 0) {
        printf("%d\n", t);
        break;
      }
      int flag = (sum > n - sum);
      for (int i = 0; i < n; i++) {
        if (s[i].pre_st == 1) {
          s[i].pre_st = (((s[i].C + t) % (s[i].A + s[i].B)) >= s[i].A);
        } else {
          if (flag == 0)
            s[i].pre_st = 0;
          else
            s[i].pre_st = (((s[i].C + t) % (s[i].A + s[i].B)) >= s[i].A);
        }
      }
    }
    if (t == maxx + 1)
      printf("-1\n");
  }
  return 0;
}
