#include<bits/stdc++.h>

using namespace std;
const int maxx = 1e3 + 1;
int dp[2][maxx];

int main()
{
  int t,m;
  cin>>t>>m;
  memset(dp,0,sizeof(dp));
  int ans = 0;
  for(int i = 1;i <= m;i++) {
    int time_val,val;
    scanf("%d%d",&time_val,&val);
    for(int j = 0;j <= t;j++){
      if(j < time_val){
        dp[(i) % 2][j] = dp[(i - 1) % 2][j];
        continue;
      }
      dp[i % 2][j] = max(dp[(i- 1) % 2][j], dp[(i - 1) % 2][j - time_val] + val);
      ans = max(ans, dp[(i % 2)][j]);
    }
  }
  cout << ans<<endl;
  return 0;
}
