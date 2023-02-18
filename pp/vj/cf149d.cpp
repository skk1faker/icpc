#include <bits/stdc++.h>
using namespace std;
const int maxx = 7e2 + 10;
const int mod = 1e9 + 7;

long long dp[maxx][maxx][3][3]; // 染色模式    012， 012
int mapval[maxx];
int mapposi[maxx];

long long dp_dfs(const int p1, const int p2, const int lmode,
           const int rmode) { // -1 表示没有进行计算
  if (dp[p1][p2][lmode][rmode] != -1)
    return dp[p1][p2][lmode][rmode];
  if (p2 - p1 == 1) { //  空串无法染色，总方案数为1
    if ((lmode == 0 && rmode == 0) || (lmode != 0 && rmode != 0))
      return dp[p1][p2][lmode][rmode] = 0;
    return dp[p1][p2][lmode][rmode] = 1;
  }
  long long &ans = dp[p1][p2][lmode][rmode];
  ans = 0;
  if (mapposi[p1] == p2) {
    // 此种情况不合法，方案数为0
    if ((lmode != 0 && rmode != 0) || (lmode == 0 && rmode == 0))
      return ans = 0;
    // 注意计算好相邻模式
    for (int l = 0; l < 3; l++) {
      for (int r = 0; r < 3; r++) {
        if ((lmode != 0 && lmode == l) || (rmode != 0 && rmode == r))
          continue;
        long long temp = dp_dfs(p1 + 1, p2 - 1, l, r);
        // printf("%d %d %d lmode = %d l = %d r = %d  rmode = %d\n",p1 + 1,p2 -
        // 1,temp,lmode,l,r,rmode);
        ans += temp;
        ans %= mod;
      }
    }
    return ans;
  }
  // for (int posi = p1 + 1; posi <= p2 - 1; posi++) {
  // if (mapval[posi] == mapval[p1] - 1) {
  int posi = mapposi[p1];     // TODO 防止重复 ()()(),在划分上() ()(),  ()() ()这两种情况在计算的时候会发生重复。
  // 重复的原因是，最终两种拆分形式的表达式是一致的
  if (mapposi[posi] == p1) {
    for (int l = 0; l < 3; l++) {
      for (int r = 0; r < 3; r++) {
        if (l != 0 && l == r)
          continue;
        // if (mapposi[posi] == p1 &&
        //  ((l == 0 && lmode == 0) || (l != 0 && lmode != 0)))
        // continue;
        // if (mapposi[posi + 1] == p2 &&
        //((r == 0 && rmode == 0) || (r != 0 && rmode != 0)))
        // continue;
        ans += (dp_dfs(p1, posi, lmode, l) * dp_dfs(posi + 1, p2, r, rmode)) % mod;
        ans %= mod;
      }
    }
  }
  return ans;
}

int main() {
  string s;
  cin >> s;
  mapval[0] = 1;
  memset(mapposi, -1, sizeof(mapposi));
  memset(dp, -1, sizeof(dp));
  for (int i = 1; i < s.length(); i++) {
    mapval[i] = mapval[i - 1];
    if (s[i] == '(') {
      mapval[i]++;
    } else {
      mapval[i]--;
      for (int j = i - 1; j >= 0; j--) {
        if (mapval[i] == mapval[j] - 1 && s[j] == '(') { // TODO:
          mapposi[i] = j;
          mapposi[j] = i;
          break;
        }
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < 9; i++) {
    if (mapposi[0] == s.length() - 1) {
      if (i == 0 || (i % 3 != 0 && i / 3 != 0))
        continue;
    }
    ans += dp_dfs(0, s.length() - 1, i / 3, i % 3);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
