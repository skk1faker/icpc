#include<iostream>

using namespace std;
const int maxx = 2000+10;
int dp[maxx][maxx]; // dp[i][j]表示左i右j序列价值和的最大
int val[maxx];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        scanf("%d",&val[i]);
    }
    for(int i = 0;i<n;i++){
        dp[i][i] = n * val[i];
    }
    for(int length=2;length<=n;length++){  
        for(int i = 0; i + length - 1 < n; i++){
            int j = i + length - 1;
            int i_pre = i+1, j_pre = j-1;
            // if(i_pre < n && j_pre >= 0){
            dp[i][j] = max(dp[i_pre][j] + (n + 1 - length) * val[i] ,dp[i][j_pre] + (n + 1 - length) * val[j]);
            // }
            // else if(i_pre < n){

            //     dp[i][j] = dp[i_pre][j] + length * val[i];
            // }
            // else if(j_pre >= 0){

            //     dp[i][j] = dp[i][j_pre] + length * val[i];
            // }
        }
    }
    cout<<dp[0][n-1]<<endl;
    return 0;
}