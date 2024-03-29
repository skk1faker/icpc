#include <bits/stdc++.h>
using namespace std;
const int maxx = (int)2e3 + 5;
const int mod = (int)1e9 + 7;
long long
    dp[maxx]
      [maxx]; // 开头位置为i，开头mod为j的情况下，后面有多少满足题义的组合。
char l[maxx], r[maxx];

int d, m,n;
long long dfs(int posi, int mod_val, bool up, char *data) {

  if (posi == n) {
    return (mod_val == 0);
  }
  if (!up && dp[posi][mod_val] != -1)
    return dp[posi][mod_val]; // 未达到上界，可以任意取值
  int max_val = data[posi] - '0';
  if (!up)
    max_val = 9;
  long long ans = 0;
  if ((posi & 1) == 0) { // 不为d
    for (int i = 0; i <= max_val; i++) {
      if(i == d)continue;
      ans +=
          dfs(posi + 1, (mod_val * 10 + i) % m, up && (max_val == i), data);
      ans %= mod;
    }

  } else { // 为d
    if (max_val >= d){ 
      ans +=
          dfs(posi + 1, (mod_val * 10 + d) % m, up && (max_val == d), data);
      ans %= mod;
    }
      
  }
  if (!up)
    dp[posi][mod_val] = ans;
  return ans;
}

void convert(char data[]) {
  for (int i = 0; data[i]; i++) {
    data[i] -= '0';
  }
}
long long check(char data[]){
  int ans = 0;
  for(int i = 0;data[i];i++){
    ans *= 10;
    ans += data[i] - '0';
    ans %= m;
    if(i & 1){  // 偶数
      if((data[i] - '0') != d)return 0;
    }
    else {
      if((data[i] - '0') == d)return 0;
    }
  }
  if(ans != 0)return 0;
  return 1;
}
int main() {
  memset(dp, -1, sizeof(dp));
  scanf("%d%d%s%s", &m, &d, l, r);
  n = strlen(l);
  cout<<(dfs(0,0,true,r) - dfs(0,0,true,l) + check(l) + mod ) % mod<<endl;
  return 0;
}
