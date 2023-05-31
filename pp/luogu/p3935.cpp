#include <iostream>
using namespace std;

const int maxx = 101;
int dp[maxx][maxx * 4];
int v[maxx], p[maxx];

// dp[i][j] v = i * max_val + j;

int main() {
  int n, w;
  cin >> n >> w;
  int min_val = (int)2e9;
  int length = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &v[i], &p[i]);
    min_val = min(v[i],min_val);
  }
  int ans =0;
  for(int i = 1;i <= n;i++){
    v[i] -= min_val;
    length += v[i];
    for (int j = i; j >= 1; j--) {
      for (int k = length; k >= 0; k--) {
        if(j * min_val + k > w)continue;
        if (k - v[i] < 0)
          break;
        dp[j][k] = max(dp[j][k], dp[j - 1][k - v[i]] + p[i]);
        ans = max(ans, dp[j][k]);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
