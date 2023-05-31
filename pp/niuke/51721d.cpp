#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = (int)1e9 + 7;
int main() {
  multiset<ll> se;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d",&val);
    se.insert(val);
  }
  for(int i = 0;i < k;i++){
    multiset<ll>::iterator iter[2] = {se.begin(),se.end()};
    iter[1]--;
    //printf("%d %d\n",*iter[0], *iter[1]);
    ll val[2] = {*iter[0],*iter[1]};
    if(val[1] * val[0] > (val[0] + m ) * (val[1] - m))break;
    se.insert(val[0] + m);
    se.insert(val[1] - m);
    se.erase(iter[0]);
    se.erase(iter[1]);
  }
  ll ans = 1;
  for(multiset<ll>::iterator iter = se.begin();iter != se.end();iter++){
    ans *= *iter;
    ans %= mod;
  }
  cout<<ans<<endl;
  return 0;
}
// https://ac.nowcoder.com/acm/contest/51721/D
