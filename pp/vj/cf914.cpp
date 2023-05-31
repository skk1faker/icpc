#include<bits/stdc++.h>
using namespace std;

map<int ,set<int>> bits;  // 操作次数， 1有多少位
int op[1001];
const int mod = 1e9 + 7;
const int maxl = 1e3 + 5;
long long dp[maxl][maxl]; // 长度， 1数量 >> 含前导0的数字个数

void init(){
  op[1] = 1;
  bits[1].insert(1);
  //  op[0] = ?; 0 这种是根本不可能变化过来的
  for(int i = 2;i <= 1000;i++){
    int j  = i;
    int ans = 0;
    while(j){
      ans += (j)&1;
      j = j >> 1;
    }
    op[i] = op[ans] + 1;
    bits[op[i]].insert(i);
  }
  memset(dp,0,sizeof(dp));
  dp[0][0] = 1;
  for(int i = 1;i <= 1000;i++){
    for(int j = 0;j <= i;j++){
      if(j == 0){
        dp[i][j] = 1;
        continue;
      }
      /*
      for(int k = j;k <= i;k++){
        dp[i][j] += dp[k - 1][j - 1];
        dp[i][j] %= mod;
       // cout << dp[i][j] << endl;
      }
      */
      dp[i][j] += dp[i - 1][j];
      dp[i][j] %= mod;
      dp[i][j] += dp[i - 1][j - 1];
      dp[i][j] %= mod;

    }
  }
  
}


int k;

long long get_ans(char *data){
  if(k == 0)return 1 % mod;
  long long ans = -1 * (k == 1);    // 因为k == 1的时候
  int now_one_num = 0;
  int length = strlen(data);
  for(int i = 0;i < length;i++){
    if(data[i] == '1'){
      for(int num_1 : bits[k]){
        //if(length - 1 - i <= num_1 - now_one_num){
        if(num_1 - now_one_num >= 0){
          ans += dp[length - 1 - i][num_1 - now_one_num] ;//为0时
          ans %= mod;
        }
      }
      now_one_num ++;
    }
  }
  return (ans + (op[now_one_num] == k)) %mod;   // 注意我们没有判断数字data需要经过几次变换才能成为1，所以要补上
    
  
}

int main()
{
  init();
  char data[maxl];
  scanf("%s",data);
  scanf("%d",&k);
  cout<<get_ans(data)<<endl;
  return 0;
}
