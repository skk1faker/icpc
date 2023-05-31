#include <bits/stdc++.h>

using namespace std;

int n, k, mod;
const int maxn = 1005;
const int maxk = 105;
long long dp[maxn][maxk];
long long  pow_10[maxn];

void init(){
  pow_10[0] = 1;
  for(int i = 1;i <= n;i++){
    pow_10[i] = (pow_10[i - 1] * 10 ) % k;
  }
}

long long dp_dfs(int length,
                 int pre_mod_val) { // 前面模为pre_mod_val，子串不包含取模为0的部分，整体取模为0，后面的部分有多少种取法。
  if (dp[length][pre_mod_val] != -1)
    return dp[length][pre_mod_val];
  if (length == 0) {                // 当前长度为0
    if (pre_mod_val == 0)
      return 1;
    else
      return 0;
  }
  if (((pre_mod_val * pow_10[length]) % k) == 0)    // 当前段模为0，假设整体取模为0，如果后面部分取值不为0，那么后面部分取模为0就不符合定义了，只有后面都是0才符合定义。
    return 1; 
  long long ans = 0;
  for (int i = 0; i <= 9; i++) {
    ans += dp_dfs(length - 1, (pre_mod_val * 10 + i) % k);
    ans %= mod;
  }
  return dp[length][pre_mod_val] = ans;
}

int main() {
  scanf("%d%d%d", &n, &k, &mod);
  init();
  memset(dp, -1, sizeof(dp));
  long long ans = 0;
  long long prefix = 1;
  for (int posi = n; posi >= 1; posi--) {
    int min_val = (posi == n);
    for (int i = 1; i <= 9; i++) {  // 枚举串开始的第一个位置
      //cout << prefix * dp_dfs(posi - 1, i % k)<<endl;;
      ans += prefix * dp_dfs(posi - 1, i % k);
      ans %= mod;
    }
    if(posi == n)prefix *= 9;
    else prefix *= 10;
    prefix %= mod;
  }
  cout << ans << endl;
}
