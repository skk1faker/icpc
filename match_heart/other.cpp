#include <bits/stdc++.h>
#include<vector>
using namespace std;
const int maxx = 102;
long long dp[maxx][maxx][maxx];
int main() {

  int N, K, D;
  cin >> N >> K >> D;

  vector<int> a(N);
  for (int i = 0; i < N; i++)
    cin >> a[i];

  //vector dp(N + 1, vector(K + 1, vector<long long>(D, -1)));
  memset(dp,-1,sizeof(dp));
  dp[0][0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < K + 1; j++) {
      for (int k = 0; k < D; k++) {
        if (dp[i][j][k] == -1)
          continue;

        // transition when a_i isn't chosen
        dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);

        // transition when a_i is chosen
        if (j != K) {
          dp[i + 1][j + 1][(k + a[i]) % D] =
              max(dp[i + 1][j + 1][(k + a[i]) % D], dp[i][j][k] + a[i]);
        }
      }
    }
  }

  cout << dp[N][K][0] << endl;

  return 0;
}
