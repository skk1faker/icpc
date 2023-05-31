#include <bits/stdc++.h>
using namespace std;
const int maxx = (int)1e7 + 10;
long long dp[maxx];
int main() {
  int t, m;
  cin >> t >> m;
  long long  ans = 0;
  for (int i = 0; i < m; i++) {
    int val_t, p;
    scanf("%d%d", &val_t, &p);
    for (int j = 0; j <= t; j++) {
      if (j - val_t >= 0)
        dp[j] = max(dp[j], dp[j - val_t] + p);
      ans = max(ans, dp[j]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
