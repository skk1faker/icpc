#include<bits/stdc++.h>
using namespace std;

const int maxx = (int)1e2 + 10;
const int INF = (int)1e6 + 10;
int flod[maxx][maxx]; // 对破坏边使用flod。
int edge_length[maxx][maxx];
int fa[maxx];
void init(){
  for(int i = 0;i < maxx;i++){
    fa[i] = i;
  }
}

int find_fa(int val){
  if(fa[val] == val)return val;
  return fa[val] = find_fa(fa[val]);
}

void merge(int a,int b){
  a = find_fa(a),b = find_fa(b);
  if(a == b)return;
  else fa[b] = a;
}

void solve()
{
  //枚举中间点
  
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      edge_length[i][j] = INF;
    }
  }
  for(int i = 0;i < m;i++){
    int a,b;
    scanf("%d%d",&a,&b);
    scanf("%d",&edge_length[a][b]);
    edge_length[b][a] = edge_length[a][b];
  }

  // init 
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++)flod[i][j] = INF;
  }
  int num;
  scanf("%d",&num);
  while(num--){
    int a,b;
    scanf("%d%d",&a,&b);
    flod[a][b] = edge_length[a][b];
    flod[b][a] = edge_length[a][b];
    edge_length[a][b] = INF;
    edge_length[b][a] = INF;
  }
  init();
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      if(edge_length[i][j] < INF){
        merge(i,j);
      }
    }
  }

  for(int k = 1;k <= n;k++){
    for(int i = 1;i <= n;i++){
      for(int j = 1;j <= n;j++){
        if(flod[i][j] > (flod[i][k] + flod[k][j])){
          flod[i][j] = min(flod[i][k] + flod[k][j],flod[i][j]); 
          if(flod[i][j] == 439)
          cout<<flod[i][j]<<endl;
        }
      }
    }
  }
  int posi1,posi2;
  scanf("%d%d",&posi1,&posi2);
  posi1 = find_fa(posi1);
  posi2 = find_fa(posi2);
  if(posi1 == posi2){
    cout<<0;
    return;
  }
  int ans = INF;
  for(int i = 1;i <= n;i++){
    for(int j = 1;j <= n;j++){
      if((find_fa(i) == posi1 && find_fa(j) == posi2 ))//||(find_fa(i) == posi2 && find_fa(j) == posi1) )
        {
        cout<<i<<' '<<j<<endl;
        ans = min(ans, flod[i][j]);
        cout<<flod[i][j]<<endl;
      }
    }
  }
    if(ans == INF){
        cout<<-1;
return;
    }
  cout<<ans;
}


int main()
{
  solve();
  return 0;
}

