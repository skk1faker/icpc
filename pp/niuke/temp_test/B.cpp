// 注意什么叫子串和子序列https://zh.wikipedia.org/zh-hk/%E5%AD%90%E4%B8%B2

#include <bits/stdc++.h>
#define ll long long 
using namespace std;

long long val[3];
long long  get_val(int n, int s) {
  val[s]++;
  ll sub = min(val[0], min(val[1], val[2]));
  for (int i = 0; i < 3; i++)
    val[i] -= sub;
  return val[0] + val[1] * n + val[2] * n * n;
}

const int maxx = 3e5 + 10;
char str[maxx];
int main() {
  int T, n;
  long long ans ;
  cin >> T;
  map<ll, ll> mp;
  while (T--) {
    cin>>n;
    scanf("%s", str);
    mp.clear();
    mp[0] = 1;
    val[0] = 0;
    val[1] = 0;
    val[2] = 0;
    for (int i = 0; i < n; i++)
      mp[get_val(n, str[i] - '0')]++;
    ans = 0;
    for (map<ll, ll>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
      ll a = iter->second;
      ans += (a * (a - 1)) / 2;
    }
    cout << ans << endl;
  }

  return 0;
}
