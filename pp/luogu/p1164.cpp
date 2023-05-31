#include<iostream>

using namespace std;

const int maxx = 10000 + 1;
long long dp[100 + 1][maxx];  // dp[i][j]表示的是前i中菜点到j元有多少种
int main()
{
  int n,m;
  cin>>n>>m;
  dp[0][0] = 1;
  for(int i = 1;i<=n;i++){
    int val;
    scanf("%d",&val);
    for(int j = 0;j <= m;j++){
      dp[i][j] = dp[i - 1][j];
      if(j - val < 0)continue;
      dp[i][j] = dp[i - 1][j - val] + dp[i - 1][j];

    }
  }
  cout<<dp[n][m]<<endl;
  return 0;
}
// 下面是经过优化的代码。
/*
#include<iostream>

using namespace std;

const int maxx = 10000 + 1;
long long dp[maxx];
int main()
{
  int n,m;
  cin>>n>>m;
  dp[0] = 1;
  for(int i = 1;i<=n;i++){
    int val;
    scanf("%d",&val);
    for(int j = m;j >= 0;j--){
      if(j - val < 0)break;
      dp[j] += dp[j - val];

    }
  }
  cout<<dp[m]<<endl;
  return 0;
}
*/

