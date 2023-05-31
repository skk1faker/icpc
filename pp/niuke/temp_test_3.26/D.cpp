#include<bits/stdc++.h>

using namespace std;

// zhengming 

const int maxx = (int)4e4 + 10;
long long ans[maxx];
int fa[maxx];
void init(int n)
{
  for(int i = 1;i <= n;i++){
    fa[i] = i;
  }
}

int find(int a){ // 返回根 
  if(a == fa[a])return a;
  fa[a] = find(fa[a]);
  return fa[a];
}

bool merge(int a,int b){
  a = find(a);
  b = find(b);
  if(a != b){
    fa[a] = b;
    return true;
  }
  return false;
}

struct edge
{
  int a,b,val;
  edge(int a,int b,int val):a(a),b(b),val(val){}
  bool operator > (const edge &temp) const {
    return val > temp.val;
  }
};

int main()
{
  int n,m;
  long long c;
  scanf("%d%d%lld",&n,&m,&c);
  priority_queue<edge, vector<edge>, greater<edge> > pq;
  for(int i = 0;i < m;i++){
    int x,y,val;
    scanf("%d%d%d",&x,&y,&val);
    pq.push(edge(x,y,val));
  }
  init(n);
  int num = n - 1;
  while(num){
    edge temp = pq.top();
    pq.pop();
    if(merge(temp.a,temp.b)){
      ans[num--] = temp.val; 
    }
  }
  int flag = 0;
  for(int i = 1;i <= n - 1;i++){
    //cout<<ans[i]<<endl;
    c -= ans[i] * i;
    if(c < 0){
      flag = ans[i];
      break;
    }
  }
  cout<<flag<<endl;
  return 0;
}
