#include <bits/stdc++.h>
using namespace std;

const int maxx = 500 + 10;
int dp[maxx][maxx];
int ele[maxx];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &ele[i]);
    dp[i][i] = 1;
    if (i - 1 >= 0) {
      if (ele[i - 1] == ele[i])
        dp[i - 1][i] = 1;
      else
        dp[i - 1][i] = 2;
    }
  }

  for (int length = 3; length <= n; length++) {
    for (int st = 0; st + length - 1 < n; st++) {
      int &temp_dp = dp[st][st + length - 1];
      temp_dp = maxx;
      for (int sublength = 1; sublength < length; sublength++) {
        temp_dp = min(temp_dp, dp[st][st + sublength - 1] +
                                   dp[st + sublength][st + length - 1]);
        //printf("%d %d %d\n",dp[st][st + sublength - 1], st, st + sublength - 1);
      }
      if (ele[st] == ele[st + length - 1])
        temp_dp = min(temp_dp, dp[st + 1][length - 2 + st + 1 - 1]);
      //printf("%d %d %d\n",st,st + length - 1, dp[st][st + length - 1]);
    }
  }
  printf("%d\n", dp[0][n - 1]);
  return 0;
}
