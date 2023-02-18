#include<iostream>
#include<cstring>
using namespace std;
int n[2][100];

bool justify(int l[],int st[])
{
  int now_posi[2];
  for(now_posi[0] = st[0], now_posi[1] = st[1];now_posi[0] < l[0] && now_posi[1] < l[1];now_posi[0]++,now_posi[1]++){
    if(n[0][now_posi[0]] + n[1][now_posi[1]] > 3)return false;
  }
  return true;
}

int main()
{
  char input[2][101];
  while(scanf("%s%s",input[0],input[1]) == 2){
    for(int i =0 ;input[0][i] != 0;i++){
      n[0][i] = input[0][i] - '0';
    }
    for(int  i=0 ;input[1][i] != 0;i++){
      n[1][i] = input[1][i] - '0';
    }
    int l[2],st[2] = {0};
    l[0] = strlen(&input[0][0]);
    l[1] = strlen(&input[1][0]);
    
    int ans = l[0] + l[1];
    st[1] = 0;
    for(st[0] = 0;st[0] < l[0];st[0]++){
      if(justify(l,st)){
        ans = min(ans,max(l[0] + st[1], l[1] + st[0]));
      }
    }
    st[0] = 0;

    for(st[1] = 0;st[1] < l[1];st[1]++){
      if(justify(l,st)){
        ans = min(ans,max(l[0] + st[1], l[1] + st[0]));
      }
    }
    cout<<ans<<endl;
  }
}
