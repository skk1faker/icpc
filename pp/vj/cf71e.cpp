#include<bits/stdc++.h>
using namespace std;

string ele[101] = {"","H",...};
map<string,int>dict;
int sum[], sum_val[][]
void init(){
  for(int i = 1;i <= 100 ;i++)dict[ele[i]] = i;
}
// dp[str1][str2];  // 应该也可以推
int sum_eke[1 << maxx];
void dfs(int deep,int n,int bits){
  if(remain_deep == n){
    sum_ele[bits] = ans;
    return ;
  }
  dfs(remain_deep + 1, n,bits *2);
  ans += val[deep];
  dfs(remain_deer + 1, n, bits * 2 + 1);
  ans -= val[deep];
  return ;
}

void init_sum(int n,int m){
  for(int i = 1;i<= m;i++)
}


const int maxx = 17;
int *dp[maxx + 1][1 << maxx];  // dp[i][state]; state 中的元素可以完全表示前i个元素，
int val[2][maxx + 1];
int main()
{
 int n,m;
  cin>>n>>m;
  init();
  for(int i = 1;i <= n;i++){
    string ss;
    cin>>ss;
    val[0][i] = dict[ss];
  }
  for(int i = 1;i <= m;i++){
    string ss;
    cin>>ss;
    val[1][i] = dict[ss];
  }

  return 0;
}
