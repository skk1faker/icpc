#include <bits/stdc++.h>

using namespace std;

int main() {

  int n, a, b;
  int T;
  cin >> T;
  while (T--) {
    cin >> n >> a >> b;
    int mode = 0;
    if ((a <= n && b <= n) || (a > n && b > n))
      mode = 0;
    else
      mode = 1;
    if (mode == 0) {
      for (int st = 1; st <= 2 * n; st++) {
        if(st == a) printf("%d ",b);
        else if(st == b)printf("%d ",a);
        else printf("%d ", st);
      }
    }
    else {
    
      for (int st = 1; st <= 2 * n; st++) {
        int output_val = st;
        if(st <= n )output_val += n;
        else output_val -= n;
        if(st == a)printf("%d ",b);
        else if(a > n && st == b + n)printf("%d ",a - n);
        else if(a <= n && st == b - n)printf("%d ",a + n);
        else printf("%d ", output_val);
      }
    }
    cout<<endl;
  }
  return 0;
}
