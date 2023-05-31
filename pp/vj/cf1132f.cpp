#include <iostream>

using namespace std;
const int maxx = (5e2) + 10;
int dp[maxx][maxx];
string str;

int main() {
  // 与刷串思路一致
  // 刷串的思路我以前写过
  int n;
  cin >> n;
  cin >> str;
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  }
  for (int length = 2; length <= n; length++) {
    for (int st = 0, en = st + length - 1; en < n; st++, en++) {
      int &ans = dp[st][en];
      ans = maxx;
      if (str[st] == str[en]) {
        ans = min(dp[st + 1][en], dp[st][en - 1]);  // 不与以前的操作合并
      } else {
        for (int i = st; i < en; i++) {
          ans = min(ans, dp[st][i] + dp[i + 1][en]);  // 与以前的操作合并
        }
      }
    }
  }
  cout<<dp[0][n - 1]<<endl;
  return 0;
}
