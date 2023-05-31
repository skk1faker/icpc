#include <bits/stdc++.h>

using namespace std;

const int maxx = 1e5 + 10;
int sum[maxx];

bool build(int posi) {
  int temp;
  cin >> temp;
  if (temp == -1)
    return false;
  // cout << temp << ' ' << posi <<endl;
  sum[posi] += temp;
  build(posi - 1);
  build(posi + 1);
  return true;
}

int main() {
  int num = 0;
  while (build(maxx / 2)) {
    num++;
    printf("Case %d:\n", num);
    int posi = 0;
    while (sum[posi] == 0)
      posi++;
    while (posi < maxx && sum[posi] != 0) {
      printf("%d", sum[posi]);
      sum[posi] = 0;
      if (sum[posi + 1] != 0)
        printf(" ");
      posi++;
    }
    printf("\n\n");
  }
}
