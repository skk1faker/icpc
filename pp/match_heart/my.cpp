#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
const long long  maxx = 105;
struct DP {
  long long data;
  long long  remain[maxx];
} dp[maxx][maxx];
int main() {
  long long n, k, d;
  scanf("%lld%lld%lld", &n, &k, &d);
  vector<long long> ele[maxx];
  for (long long i = 0; i < n; i++) {
    long long temp;
    scanf("%lld", &temp);
    ele[temp % d].push_back(temp);
  }
  for (long long  i = 0; i < d; i++) {
    sort(ele[i].begin(), ele[i].end());
  }
  //memset(dp, -1, sizeof(dp));
  dp[0][0].data = 0;
  for (long long  j = 0; j < d; j++) {
    dp[0][0].remain[j] = ele[j].size();
  }
  for(int j = 1;j < d;j++){
    dp[0][j].data = -1;
  }
  for (long long  i = 1; i <= k; i++) {
    for (long long  j = 0; j < d; j++) {
      dp[i][j].data = -1;
      memset(dp[i][j].remain,0,sizeof(dp[i][j].remain));
      long long  posi_use = -1;
      long long  posi_jj = -1;
      long long ans = -1;
      for (long long  jj = 0; jj < d; jj++) {
        long long  need_check = (j - jj + d) % d;
        if (dp[i - 1][jj].data == -1)
          continue;
        if (dp[i - 1][jj].remain[need_check] <= 0)
          continue;
        if (ans < dp[i - 1][jj].data +
                      ele[need_check][dp[i - 1][jj].remain[need_check] - 1]) {
          ans = dp[i - 1][jj].data +
                ele[need_check][dp[i - 1][jj].remain[need_check] - 1];
          posi_use = need_check;
          posi_jj = jj;
        }
      }
      if (posi_use == -1)
        continue;
      dp[i][j].data = ans;
      for (long long  jj = 0; jj < d; jj++) {
        dp[i][j].remain[jj] = dp[i - 1][posi_jj].remain[jj] - (jj == posi_use);
      }
    }
  }
  printf("%lld\n", dp[k][0].data);
  return 0;
}

