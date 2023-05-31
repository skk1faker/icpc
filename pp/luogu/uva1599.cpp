#include<bits/stdc++.h>
#include <cmath>
#include <type_traits>

using namespace std;
int n;
const int maxx = (int )1e5 + 10;
struct Node{
  int dist;
  int color;
  int fa; // 前一个节点是什么
  Node():dist(-1),color(-1),fa(-1){}
}node[maxx];

struct Edge
{
  Edge(int to, int color):to(to),color(color){}
  int to,color;
};
vector<Edge>graph[maxx];

int vis_n = false;
void output(int posi)
{
  if(posi == n){
    return ;
  }
  cout<<node[posi].color;
  if(node[posi].fa != n)cout <<' ';
  output(node[posi].fa);
}
void bfs(int st,int en)
{
  queue<int> q;
  node[st].dist = 0;
  q.push(st);
  while(!q.empty()){
    int now_point = q.front();
    q.pop();
    for(Edge next_edge:graph[now_point]){
      int next_point = next_edge.to;
      int color = next_edge.color;
      if(node[next_point].dist == -1){
        node[next_point].dist = node[now_point].dist + 1;
        node[next_point].fa = now_point;
        node[next_point].color = color;
        q.push(next_point);
      }
      else if(node[next_point].dist == node[now_point].dist + 1){
        //cout<<next_point<<' '<<now_point<<endl;
        int now_color = color;
        int other_color = node[next_point].color;
        int pre_other = node[next_point].fa;
        int pre_now = now_point;
        //while(other_color == now_color &&(pre_now != -1 && pre_other != -1)){   // 退化成链的时候是会超时的
        while(other_color == now_color &&(pre_now != pre_other)){ 
          now_color = node[pre_now].color;
          other_color = node[pre_other].color;
          pre_now = node[pre_now].fa;
          pre_other = node[pre_other].fa;
        }
        if(now_color < other_color){
          node[next_point].fa = now_point;
          node[next_point].color = color;
        }
      }
    }
  }
  cout<<node[en].dist<<endl;
  output(en);
  cout<<endl;
}

int main()
{
  int m;

  while(cin>>n>>m){
    for(int i = 1;i <= n;i++){
      graph[i].clear();
      node[i].fa = -1;
      node[i].dist = -1;
      node[i].color = -1;
    }
    while(m--){
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      graph[a].push_back(Edge(b,c));
      graph[b].push_back(Edge(a,c));
    }
    bfs(n,1);
  }
  return 0;
}
