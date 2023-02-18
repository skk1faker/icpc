#include<iostream>

using namespace std;
const int max_n = (int)1e5+10;
int dp[max_n][2];
int B[max_n];

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&B[i]);
    }
    dp[0][0] = 0;//表示最开始选择为1
    dp[0][1] = 0;//表示最开始选择为最大值
    for(int i=1;i<n;i++){
        dp[i][0] = max(dp[i-1][0] + abs(1-1), dp[i-1][1] + abs(B[i-1] - 1));
        dp[i][1] = max(dp[i-1][0] + abs(B[i] - 1), dp[i-1][1] + abs(B[i] - B[i-1]));
    }
    cout<<max(dp[n-1][0],dp[n-1][1])<<endl;
    return 0;
}