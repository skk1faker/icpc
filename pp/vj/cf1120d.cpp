#include<bits/stdc++.h>
using namespace std;
// niu bi
const int maxx = (int)(2e5) + 10;
long long dp[maxx][2];
vector<int>G[maxx];
int root[maxx];
int val[maxx];
int vis[maxx][2];


void dfs(int now_posi, int root_posi){
  if(G[now_posi].size() == 1 && root_posi != - 1){
    dp[now_posi][0] = val[now_posi];
    dp[now_posi][1] = 0;
    return;
  }
  long long ans = 0;
  for(int i = 0;i < G[now_posi].size();i++){
    int j = G[now_posi][i];
    if(j == root_posi)continue;
    dfs(j,now_posi);
    ans += dp[j][0];
  }
  dp[now_posi][1] = ans;
  for(int i = 0;i < G[now_posi].size();i++){
    int j = G[now_posi][i];
    if(j == root_posi)continue;
    if(dp[now_posi][1] > (ans - dp[j][0] + dp[j][1])){
      dp[now_posi][1] =  ans - dp[j][0] + dp[j][1]; // 选择方式，需要记录
    }
  }
  for(int i = 0;i < G[now_posi].size();i++){
    int j = G[now_posi][i];
    if(j == root_posi)continue;
    if(dp[now_posi][1] == (ans - dp[j][0] + dp[j][1])){
      root[now_posi]++;
    }

  }
  if(ans > dp[now_posi][1] + val[now_posi]){
    dp[now_posi][0] = dp[now_posi][1] + val[now_posi];
  }
  else {
    dp[now_posi][0] = ans;
  }
}

set<int> node_list;
void dfs_choise(int now_posi,int root_posi, int choise)
{
  if(vis[now_posi][choise] == 1){     // 防止超时, 因为这里dfs的状态是,[节点位置][01] 这不是一个树，而是一个图，所以要使用vis来记录状态。
    return;
  }
  vis[now_posi][choise] = 1;
  long long ans = 0;
  for(int i = 0;i < G[now_posi].size();i++){
    int j = G[now_posi][i];
    if(j == root_posi)continue;
    ans += dp[j][0];
  }
  if(choise == 0){
    if(ans == dp[now_posi][0]){
      
      for(int i = 0;i < G[now_posi].size();i++){
        int j = G[now_posi][i];
        if(j == root_posi)continue;
        dfs_choise(j,now_posi,0);
      }

    }
    if(dp[now_posi][0] == dp[now_posi][1] + val[now_posi]){
      node_list.insert(now_posi);
    }
  }
  if((dp[now_posi][0] == dp[now_posi][1] + val[now_posi]) || (choise == 1)){
    for(int i = 0;i < G[now_posi].size();i++){
      int j = G[now_posi][i];
      if(j == root_posi)continue;
      if(dp[now_posi][1] == (ans - dp[j][0] + dp[j][1])){
        dfs_choise(j,now_posi,1);
        if(root[now_posi] > 1)dfs_choise(j,now_posi,0);
      }
      else {
        dfs_choise(j,now_posi,0);
      }
    }
  }
}

int main()
{
  int n;
  cin>>n;
  for(int i = 1;i <= n;i++){
    scanf("%d",&val[i]);
  }
  for(int i = 1;i < n;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(1,-1);
  dfs_choise(1,-1,0);
  cout<<dp[1][0]<<' '<<node_list.size()<<endl;
  //sort(node_list.begin(),node_list.end());
  //for(int i = 0;i < node_list.size();i++){
  for(set<int>::iterator iter= node_list.begin();iter != node_list.end();iter++){
    printf("%d ",*iter);
  }
  cout<<endl;
  return 0;
}
