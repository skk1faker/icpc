#include<iostream>
using namespace std;

int number[11];
int dp[11];

int main()
{
  int n;
  scanf("%d",&n);
  dp[0] = 1;
  for(int i =1 ;i<=10;i++)dp[i] = dp[i - 1] * 9;
  int length = 0;
  while(n){
    number[length ++] = n %10;
    n /= 10;
  }
  int ans = 0;
  int now_val = 1;
  for(int i = length - 1;i >= 0;i--){
    if(number[i] == 0)break;
    if(i == length - 1 && (number[i] == 1))ans = max(ans, now_val * dp[i]);
    else ans = max(ans,now_val * (number[i] - 1) *dp[i]);
    now_val *= number[i];
  }
  ans = max(ans, now_val);
  cout<<ans<<endl;
  return 0;
}
