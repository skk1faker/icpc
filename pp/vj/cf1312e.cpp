#include<bits/stdc++.h>
// 双dp， 有些dp不能一下子就得到当前任务的解，这个时候可能会需要其他方法辅助，可以是双dp
using namespace std;

const int maxx = 500 + 10;
int dp_merge[maxx][maxx];
int merge_val[maxx][maxx];
int dp_length[maxx];


int main()
{
  int n;
  cin>>n;
  for(int i =0;i < n;i++){
    scanf("%d",&merge_val[i][i]);
    dp_merge[i][i] = 1;
  }
  for(int length = 2;length <= n;length++){
    for(int st = 0,en = st + length - 1;en < n;st++,en++){
      dp_merge[st][en] = 0;
      for(int posi = st;posi <= en;posi++){
        if(dp_merge[st][posi] == 1 && dp_merge[posi+1][en] == 1 && merge_val[st][posi] == merge_val[posi + 1][en]){
          dp_merge[st][en] = 1;
          merge_val[st][en] = merge_val[st][posi] + 1;
          break;
        }
      }
    }
  }
  
  dp_length[0] = 1;
  for(int i = 1;i < n;i++){
    int &ans = dp_length[i];
    if(dp_merge[0][i] == 1){
      ans = 1;
      continue;
    }
    ans = dp_length[i - 1] + 1;
    for(int posi = 0;posi < i;posi++){
      if(dp_merge[posi + 1][i] == 1){
        ans = min(ans, dp_length[posi] + 1);
      }
    }
  }
  cout<<dp_length[n - 1]<<endl;
  return 0;
}
