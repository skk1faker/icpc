#include <bits/stdc++.h>

// 规定数域
#define minus1(a, n) ((a - 2 + n) % n + 1)
#define add1(a, n) ((a + n) % n + 1)
#define ll long long

using namespace std;

const int maxx = 5e2 + 10;
const long long INF = 1e15;
ll dp[maxx][maxx]; // 顺时针！！
// 想想这个状态应该怎么定
// dp[a][b]表示的是从a -- b顺时针组成的多边形，由于每一条边都会组成多边形, 所以我们每次枚举[a,b]为某一三角形的一条边，然后找这个边对应的顶点。

int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) { // length == 3
    dp[i][i + 1] = 0;
  }

  for (int length = 3; length <= n; length++) {
    for (int st = 1; st <= n; st++) {
      int en = (st + length - 2 + n) % n + 1;
      ll ans = INF;
      for (int i = 1; i <= length - 2; i++) {
        int mid = (st + i + n - 1) % n + 1;
        ans = min(ans, dp[st][mid] + dp[mid][en] + st * en * mid);
      }
      dp[st][en] = ans;
    }
  }
  cout << dp[2][1] << endl;
  return 0;
}
