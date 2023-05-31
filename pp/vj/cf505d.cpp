#include<bits/stdc++.h>
#include <type_traits>
using namespace std;
const int maxx = (int)1e5 + 10;
struct Node{
  int fa;
  int in;
  bool topological;
  int vis;
  int have_circle;
}node[maxx];

vector<int>graph[maxx];

int ans = 0;
void init(int n)
{
  for(int i =0 ;i<= n;i++){
    node[i].fa = i;
    node[i].in = 0;
    node[i].topological = false;
    node[i].vis = 0 ;
    node[i].have_circle = 0;
  }
}

int find(int a){
  if(node[a].fa == a)return a;
  return node[a].fa = find(node[a].fa); // 1. 因为后面查找不会用到node[a].fa, 2. 次表达式会在查找结束的时候将node[a].fa改变，宗上所以这样写。
}

void merge(int a,int b)
{
  node[b].in++;
  if(node[a].vis == false)ans++;
  if(node[b].vis == false)ans++;
  node[a].vis = true;
  node[b].vis = true;
  a = find(a);
  b = find(b);
  if(a == b)return ;
  node[a].fa = b;
}

int main()
{
  int n,m;
  cin>>n>>m;
  init(n);
  for(int i = 0;i < m;i++){  
    int a,b;
    scanf("%d%d",&a,&b);  // a-->b
    graph[a].push_back(b);
    merge(a,b);   
  }
  queue<int> q;
  for(int i = 1;i <= n;i++){
    if(node[i].in == 0 && node[i].vis == 1){
      q.push(i);
      node[i].topological = true;
    }
  }
  while(!q.empty()){
    int a = q.front();
    q.pop();
    for(int b : graph[a]){
      node[b].in --;
      if(node[b].in == 0) {
        q.push(b);
        node[b].topological = true;
      }
    }
  }

  for(int i = 1;i <= n;i++ ){
    if(node[i].vis && !node[i].topological)node[find(i)].have_circle = 1;       // 注意，代表一个连通块的节点可能会在拓扑排序中被处理掉。
  }
  for(int i = 1;i <= n;i++ ){
    if(node[i].vis && find(i) == i && node[i].have_circle == 0)ans--;
  }
  cout<<ans<<endl;
  return 0; 
}
