#include <bits/stdc++.h>
using namespace std;
const int maxx = (int)1e6 + 10;
int a[maxx];
int val(int posi) { return ((posi + 1) / 2) * (posi % 2 == 0 ? -1 : 1); }
int main() {
  int n;
  cin >> n;
  for(int i = 0;i < n;i++)scanf("%d",&a[i]);
  int st = 0;
  int en = 0;
  int ans = 1;
  while (en + 1 < n) {
    if (a[en + 1] == a[st] + val(en + 1 - st)) {
      en++;
      ans = max(ans, (en - st + 1));
    } else {
      if(st == en) en++;
      st = en;
    }
  }
  cout << ans << endl;
  return 0;
}
