#include <bits/stdc++.h>

using namespace std;

const int maxm = 30000 + 1;
int dp[maxm];

int main() {
  int n, m;
  cin >> m >> n;
  dp[0] = 0;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int v, p;
    scanf("%d%d", &v, &p);
    for (int j = m; j >= 0; j--) {
      if (j - v < 0)
        break;
      dp[j] = max(dp[j], dp[j - v] + v * p);
      ans = max(ans, dp[j]);
    }
  }
  cout << ans << endl;
  return 0;
}
