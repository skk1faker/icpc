#include<bits/stdc++.h>
using namespace std;
const int maxx = 1024 * 1024;
const int maxn = 1024 * 1024 + 1;
double dp[maxn];    // 2 ** 10 * 2 ** 10; // 体积剩余
int n;

long long max_val = 0;
struct pade 
{
  int w;
  double s;
}pad[maxx];
void solve()
{
  for(int i = 0;i <= max_val;i++)dp[i] = 0;
  for(int i = 1;i <= n;i++){
    for(int v = 0;v <= max_val;v += 8){  // v 表示剩余空间
      for(int scale = 1;scale <= (pad[i].w / 8);scale = scale << 1){
        int now_v = (pad[i].w / scale) * (pad[i].w / scale);
        if(v + now_v > max_val)continue;
        double now_score = pad[i].s / (scale * scale);
        dp[v] = max(dp[v + now_v] + now_score , dp[v]);
      }
    }
  }
  double ans = 0;
  for(int i = 0;i <= max_val;i++){
    ans = max(ans, dp[i]);
  }
  ans = (double)(int((ans + 0.005) * 100)) / 100;
  cout<<ans<<endl;
}
int main()
{
  cin>>n;
  for(int i =1 ;i<= n;i++){
    scanf("%d%lf",&pad[i].w,&pad[i].s);
    max_val += (pad[i].w * pad[i].w);
  }
  max_val = min(max_val,(long long )maxx);
  solve();
}
