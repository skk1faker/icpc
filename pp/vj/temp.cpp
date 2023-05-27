#include<bits/stdc++.h>
using namespace std;
const int maxx = (int)5e4  + 10;
long long  sum[maxx];
long long a[maxx];


int bin_find(int n, long long  val)
{
  int l = 0,r = n;
  while(l < r){
    int mid = (l + r) / 2;
    if(sum[mid] < val){
      l = mid + 1;
    }
    else{
      r = mid ;
    }
  }
  if(sum[l] > val)l--;
  return l;
}

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i = 0;i < n;i++){
    scanf("%lld",&a[i]);
  }
  sort(a,a+n);
  sum[0] = 0;
  for(int i = 0;i < n;i++){
    sum[i + 1] = sum[i] + a[i] * a[i];
  }

  for(int i = 0;i < m;i++){
    long long q;
    scanf("%lld",&q);
    int len = bin_find(n,q);
    cout<<len<<" ";
  }

}
/*
#include<bits/stdc++.h>

using namespace std;

const int maxx = (int)5e4 + 10;

int dp[maxx][2]; // dp[i]选择了i号糖果
int a[maxx];
int main(){
  int n;
  scanf("%d",&n);
  for(int i = 0;i < n;i++){
    scanf("%d",&a[i]);
    if(i >= 3){
    dp[i][1] = a[i] +  max(dp[i - 3][1], dp[i - 3][0]);
    dp[i][0] = max(dp[i - 1][0], dp[i-  1][1]);
    }
    else {
    dp[i][1] = a[i];
    dp[i][0] = (dp[i - 1][0] ,dp[i - 1][1]);
    }
  }
  cout<<max(dp[n - 1][0], dp[n - 1][1])<<endl;
}

*/
