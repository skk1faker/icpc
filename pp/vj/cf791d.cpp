/*
换根之后，两个交换身份节点包括其之间节点的身份会发生对调。
如果我们将交换身份节点之间的距离减小，那么影响就会小一些，我们仅改变两个参与交换的节点信息即可。
这就是换根dp的主要思路。
*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = (int)2e5 + 10;
int dp[maxn][5];
long long val[maxn];  //以当前节点为根，子树到其距离和为多少

int n,m;      //  一次跳m步
int to[maxn * 2],next_posi[maxn * 2], head_posi[maxn];
int now_posi = 1;
void add_edge(int a,int b){ // 头插法 可以记录一个图。
  to[now_posi] = b;
  next_posi[now_posi] = head_posi[a]; // head_posi[a]初始值为0，初始的时候head没有指向内容， 所以next_posi == 0 的时候表示没有指向内容
  head_posi[a] = now_posi;
  now_posi++;
}
void dfs(int now_posi, int root_posi){
  dp[now_posi][0] = 1;
  //for(int i =0 ;i < G[now_posi].size();i++){
  for(int posi = head_posi[now_posi];posi != 0;posi = next_posi[posi]){
    int j = to[posi];
    if(j == root_posi)continue;
    dfs(j, now_posi);
    for(int i = 0;i < m;i++)
      dp[now_posi][i] += dp[j][(i - 1 + m)% m];
    val[now_posi] += val[j] + dp[j][0]; //(nm + 0) / m = n,(nm + 1) / m = n + 1,(nm + 2) / m = n + 1, (nm + m - 1) / m = n + 1, 所以变化的地方就知道在哪了
  }
}
long long ans;
void dfs_(int now_posi, int root_posi)  // 换根计算
{
  ans += val[now_posi];
  for(int posi = head_posi[now_posi];posi != 0;posi = next_posi[posi]){
    int j = to[posi];
    if(j == root_posi)continue;

    for(int x = 0;x < m;x++)
      dp[now_posi][x] -= dp[j][(x - 1 + m) % m];
    val[now_posi] = val[now_posi] - val[j] - dp[j][0];
    for(int x = 0;x < m;x++)
      dp[j][x] += dp[now_posi][(x - 1 + m) % m];
    val[j] += (val[now_posi] + dp[now_posi][0]);
    dfs_(j,now_posi);
    val[j] -= (val[now_posi] + dp[now_posi][0]);
    for(int x = 0;x < m;x++){
      dp[j][x] -= dp[now_posi][(x - 1 + m) % m];
    }
    val[now_posi] = val[now_posi] + val[j] + dp[j][0];
    for(int x = 0;x < m;x++)
      dp[now_posi][x] += dp[j][(x - 1 + m) % m];
  }
}

int main()
{
  cin>>n>>m;
  for(int i = 0;i < n - 1;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    //G[a].push_back(b);
    //G[b].push_back(a);
    add_edge(a,b);
    add_edge(b,a);
  }
  ans = 0;
  dfs(1,-1);
  dfs_(1,-1);
  ans /= 2;
  cout<<ans<<endl;
  return 0;
}

