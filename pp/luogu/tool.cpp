/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    tool.cpp
*   username:     skt1faker
*   create time:  22:11  2023.05.16
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/

#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

int main() {
  int n, m;
  srand(time(NULL));
  int max_val = 99;
  int output_max = 100;
  for (int tt = 0; tt <output_max; tt++) {
    n = rand() % 2 + 3;
    m = rand() % 2 + 3;
    printf("%d %d\n", n, m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m * m; j++) {
        printf("%d ", rand() % max_val + 1);
      }
      cout << endl;
    }
  }
  printf("0 0\n");

  return 0;
}
