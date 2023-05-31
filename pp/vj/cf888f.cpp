#include <iostream>
#define add_val(a, b, n) ((a + b) % n)
#define minus_val(a, b, n) ((a - b + n) % n)

using namespace std;

const int maxx = 500 + 10;
const int mod = (int)1e9 + 7;
int dp[maxx][maxx][2];
int link_map[maxx][maxx];

// 假设状态之后，在推理的过程中发现因为某一个特殊条件会导致/推导无法进行，那么将这个状态加入dp中。
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      scanf("%d", &link_map[i][j]);
  }

  for (int i = 0; i < n; i++) {
    dp[i][add_val(i,1,n)][1] = link_map[i][add_val(i,1,n)];
    dp[i][add_val(i,1,n)][0] = 0;
    dp[i][i][1] = 0;
    dp[i][i][0] = 1;
  }
  // 每类状态由不同的特征就会不重复
  for (int length = 3; length <= n; length++) {
    for (int st = 0; st <= n - 1; st++) { // 端点st与en已经链接
      int en = add_val(st, length - 1, n);
      for (int posi = st; posi != minus_val(en, -1, n);
           posi = add_val(posi,1,n)) // 由st发出的
      {
        if (link_map[st][posi] == 1)
          //dp[st][en][0] += dp[st][posi][1] * (dp[posi][en][0] + dp[posi][en][1] * (link_map[posi][en] == 1));
          dp[st][en][0] += dp[st][posi][1] * (dp[posi][en][0] + dp[posi][en][1]);
        if (link_map[st][en] == 1) {
          //dp[st][en][1] += (dp[st][posi][0] + dp[st][posi][1] * (link_map[st][posi] == 1)) * (dp[posi + 1][en][0] + dp[posi + 1][en][1] * (link_map[posi + 1][en] == 1));
          dp[st][en][1] += (dp[st][posi][0] + dp[st][posi][1]) * (dp[posi + 1][en][0] + dp[posi + 1][en][1]);
        }
      }
    }
  }
  cout<<dp[0][n - 1][0] + dp[0][n - 1][1]<<endl;

  return 0;
}
