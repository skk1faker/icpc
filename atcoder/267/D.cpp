#include<iostream>
#include<cstring>
#define ll long long 
const int N = (int)2000+10;
ll dp[N][N];//[到那一个位置][前面选择了多少]，dp为当前最值
ll a[N];
ll max_dp[N][N];   // max[i][j] <= i == j的最大值
using namespace std;
int main()
{

    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(int i = 1;i <=n;i++){
        scanf("%lld",&a[i]);
    }
    memset(dp,0,sizeof(dp));
    memset(max_dp,0,sizeof(max_dp));
    for(ll j = 1;j <= m;j++){ // 长度
        for(ll i = j;i <= n;i++){ // 位置
            dp[i][j] = max_dp[i - 1][j - 1] + a[i] * j;
            if(i != j)max_dp[i][j] = max(max_dp[i-1][j],dp[i][j]);
            else max_dp[i][j] = dp[i][j];
        }
    }
    ll ans = dp[m][m];
    for(int i = m+1;i <= n;i++){
        ans = max(ans, dp[i][m]);
    }
    printf("%lld",ans);
    return 0;
}