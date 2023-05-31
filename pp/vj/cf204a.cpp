#include<bits/stdc++.h>
#include <math.h>
#define LL long long
LL dp[20];
using namespace std;

void init() {
  for (int i = 1; i < 20; i++) {
    dp[i] = pow(10, i - 1);
  }
}

int num[20];
LL solve(LL a) {
  int posi = 1;
  num[1] = 0;
  while (a) {
    num[posi] = a % 10;
    a = a / 10;
    posi++;
  }
  LL ans = 0;
  if(posi <= 2)return num[1];
  else ans = 8;
  for (int i = posi - 1; i >= 1; i--) {
    if (i == 1) {
      ans += num[posi - 1] <= num[1];
    } else {
      ans += num[i] * dp[i - 1];
    }
  }
  return ans;
}

int main() { 

  LL a,b;
  init();
  while(scanf("%lld%lld",&a,&b) == 2){
    cout<<solve(b) - solve(a - 1)<<endl;
  }
  return 0; 
}

