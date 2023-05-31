#include <iostream>

const int maxx = 20001;
int dp[201][maxx];

int main() {
  int V, n;
  std::cin >> V >> n;
  dp[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    int v;
    scanf("%d", &v);
    for (int j = 0; j <= V; j++) {
      dp[i % 2][j] = dp[(i - 1) % 2][j];
      if (j - v < 0)
        continue;
      dp[i % 2][j] = dp[(i - 1) % 2][j] | dp[(i - 1) % 2][j - v];
    }
  }
  for (int i = V; i >= 0; i--) {
    if (dp[(n) % 2][i]) {
      std::cout << V - i << std::endl;
      return 0;
    }
  }
  return 0;
}
