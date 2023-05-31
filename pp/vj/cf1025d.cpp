#include <bits/stdc++.h>
using namespace std;

const int maxx = (7e2) + 5;

int dp[maxx][maxx][2];    // dp[a][b][k] 会造成信息的冗余。具体是什么冗余，我不清楚。
int val[maxx];
int gcd(int a,int b){ // (a < b)
  if(a == 0)return b;
  return gcd(b % a, a);
}


int dp_dfs(int l, int r, int mode) { // mode == 0 左子树， mode == 1 右子树
  if(l > r){    // 空树成立！！！，不论左右子树
    return 1;
  }
  int &ans = dp[l][r][mode];  // 注意l > r  时存在l == -1 的时候，c++为了效率不会进行越界检查，所以要自己注意。
  if (ans != -1)
    return ans;
  if (l == r) {
    /*
    if (gcd(val[l], val[l + 1 - 2 * mode]) == 1)
      ans = 0;
    else
      ans = 1;
    */
    return ans = (gcd(val[l],val[l + 1 - 2 * mode]) != 1);
  }
  for (int i = l ; i <= r; i++) {
    if ((mode == 0 && gcd(val[i], val[r + 1]) != 1) ||
        (mode == 1 && gcd(val[i], val[l - 1]) != 1)) {    // i 是否可以作为树根。
      if (dp_dfs(l, i - 1, 0) == 1 && dp_dfs(i + 1, r, 1) == 1) {
        return ans = 1;
      }
    }
  }
  return ans = 0;
}

void solve() {
  int n; 
  cin>>n;
  for(int i = 0;i < n;i++){
    scanf("%d",&val[i]);
  }
  memset(dp,-1,sizeof(dp));
  for(int i = 0;i < n ;i++){
    if(dp_dfs(0,i - 1,0) == 1 && dp_dfs(i + 1,n - 1,1) == 1){
      cout<<"Yes"<<endl;
      return ;
    }
  }
  cout<<"No"<<endl;
}


int main() { 
  solve();
  return 0; 
}
