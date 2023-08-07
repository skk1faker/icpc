# 题目

有一个有向图， 从s点出发，一个路径的low值为路径中边权最小的值， 到达所有点u的值为d[u], 这个值为从s到达u中所有路径中low最大值，求所有d[u], 无法到达的点和当前S点的值为-1

# 分析

当前需要解决：low值随着路径中边的增加而减小，到达同一点的路径low值选择最大的作为最优

dijstra解决：路径长度随着边的增加而增大，到达同一点的路径长度选择最短的作为最优。

于是反向使用dijstra，使用最大堆。

```cpp
/*================================================================

*   Copyright (C) 2023 Wangxinpeng. All rights reserved.
*   
*   filename：    D.cpp
*   username:     skt1faker
*   create time:  17:56  2023.06.22
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

//https://ac.nowcoder.com/acm/contest/44749/D
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int INF = (int)1e9;

const int maxx = (int)1e5 + 10;
struct Status
{
  int length;
  int posi;
  bool operator < (const Status & temp) const {
    return length < temp.length;
  }
};
struct Edge{
  int v;
  int length;
};
vector<Edge>G[maxx];
int dis[maxx];
int vis[maxx];
void dijstra(int s){
  priority_queue<Status> q;
  memset(dis,-1,sizeof(dis));
  memset(vis,0,sizeof(vis));
  dis[s] = INF;
  q.push(Status{dis[s], s});
  while(!q.empty()){
    Status st = q.top();
    int u = st.posi;
    q.pop();
    //if(dis[u] > st.length)continue;
    if(vis[u] == 1)continue;
    vis[u] = 1;
    for(int i = 0;i < G[u].size();i++){
      int v = G[u][i].v;
      int length = G[u][i].length;
      if(dis[v] < min(dis[u], length)){
        dis[v] = min(dis[u], length);
        q.push(Status{dis[v], v});
      }
    }
  }
}
int main()
{
  int n,m,s;
  cin>>n>>m>>s;
  for(int i =0;i< m;i++){
    int u,v,w;
    scanf("%d%d%d",&u,&v,&w);
    G[u].push_back(Edge{v,w});
  }
  dijstra(s);
  dis[s] = -1;
  for(int i = 1;i <= n;i++){
    printf("%d ",dis[i]);
  }
  return 0;
}

```