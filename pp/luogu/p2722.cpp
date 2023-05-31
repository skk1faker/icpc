#include <bits/stdc++.h>
using namespace std;
const int maxx = 1e4 + 10;

int dp[maxx];

int main() {
  int m, n;
  cin >> m >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int p, t;
    scanf("%d%d", &p, &t);
    for (int j = 1; j <= m; j++) {
      if (j - t >= 0)
        dp[j] = max(dp[j], dp[j - t] + p);
      ans = max(ans, dp[j]);
    }
  }
  cout<<ans<<endl;
}
