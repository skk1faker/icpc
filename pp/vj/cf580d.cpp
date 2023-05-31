#include <bits/stdc++.h>
using namespace std;

const int maxx = 18;
long long dp[maxx][(1 << maxx) + 10];
int add_dic[maxx][maxx];
int length(int val) {
  int ans = 0;
  while (val) {
    ans += (val & 1);
    val = val >> 1;
  }
  return ans;
}
int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%lld", &dp[i][1 << i]);
  for (int i = 0; i < k; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--,y--;
    scanf("%d", &add_dic[x][y]);
  }
  long long ans = 0;
  for (int str = 1; str < (1 << n); str++) {
    int l = length(str);
    if (l > m)
      continue;
    if (l == m) {
      for (int i = 0; i < n; i++) {
        // if(((1 << i) & str) != 0)
        ans = max(ans, dp[i][str]);
      }
      continue;
    }
    for (int i = 0; i < n; i++) {
      if (((1 << i) & str) == 0)
        continue;
      for (int j = 0; j < n; j++) {
        if (((1 << j) & str) != 0)
          continue;
        dp[j][str + (1 << j)] =
            max(dp[j][str + (1 << j)],
                dp[i][str] + add_dic[i][j] + dp[j][(1 << j)]);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
