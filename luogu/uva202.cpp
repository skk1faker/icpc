#include <iostream>
using namespace std;

int get_next(int &a, int b) {
  int ans;
  if (a >= b) {
    ans = a / b;
    a %= b;
    a *= 10;
    return ans;
  } else {
    a *= 10;
    return 0;
  }
}

int main() {
  int ori_a, ori_b;
  while (scanf("%d%d", &ori_a, &ori_b) == 2) {
    int a[2] = {ori_a, ori_a}, b = ori_b;
    get_next(a[0], b);
    get_next(a[1], b);
    get_next(a[1], b);

    while (a[0] != a[1]) {
      get_next(a[0], b);
      get_next(a[1], b);
      get_next(a[1], b);
    }
    a[0] = ori_a;
    int length = 1;
    printf("%d/%d = %d.", ori_a,ori_b,get_next(a[0], b));
    get_next(a[1], b);
    while (a[0] != a[1]) {
      printf("%d", get_next(a[0], b));
      get_next(a[1], b);
      length++;
    }
    int xunhuan_length = 1;
    printf("(%d", get_next(a[0], b));
    while (a[0] != a[1]) {
      if (length == 50) {
        get_next(a[0], b);
        printf("...");
      } else if (length < 50) {
        printf("%d", get_next(a[0], b));
      } else {
        get_next(a[0], b);
      }
      length++;
      xunhuan_length++;
    }
    printf(")\n");
    printf("   %d = number of digits in repeating cycle\n\n", xunhuan_length);
  }
}
