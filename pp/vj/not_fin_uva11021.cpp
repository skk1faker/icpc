#include<iostream>
#include<cstring>

int dp[101][101];
int dp2[101][101];
using namespace std;

int main()
{
    char a[102], b[102];
    int l[101],r[101];
    while(scanf("%s%s",a + 1,b + 1) == 2){
        memset(dp,0x3f3f3f3f,sizeof(dp));
        memset(dp2,0x3f3f3f3f,sizeof(dp2));
        int n = strlen(a+1);
        for(int i = 1,j = n; i <= n;i++,j--){
            if(b[i] == b[i - 1])r[i] = r[i - 1];
            else r[i] = i;

            if(b[j] == b[j + 1])l[j] = l[j + 1];
            else l[j] = j;
        }
        for(int length = 1; length<=n;length++){
            for(int stat_posi = 1,end_posi = length; end_posi <= n; stat_posi++,end_posi++){
                if(length == 1){
                    dp2[stat_posi][stat_posi] = 1;
                    printf("dp2[%d][%d] = %d\n",stat_posi,end_posi,dp2[stat_posi][end_posi]);
                    continue;
                }
                for(int k = stat_posi; k <= end_posi - 1;k++){
                    dp2[stat_posi][end_posi] = min(dp2[stat_posi][end_posi], dp2[stat_posi][k] + dp2[k + 1][end_posi]);
                }
                if(b[stat_posi] == b[end_posi]){
                    if(l[stat_posi] + 1 <= r[end_posi] - 1)
                        dp2[stat_posi][end_posi] = min(dp2[stat_posi][end_posi], dp2[l[stat_posi] + 1][r[end_posi] - 1] + 1);
                    else 
                        dp2[stat_posi][end_posi] = min(dp2[stat_posi][end_posi], 1);
                }
                printf("dp2[%d][%d] = %d\n",stat_posi,end_posi,dp2[stat_posi][end_posi]);
            }
        }

        for(int length = 1; length <= n;length++){
            for(int stat_posi = 1; stat_posi + length - 1 <= n; stat_posi++){
                if(length == 1){
                    if(a[stat_posi] == b[stat_posi])dp[stat_posi][stat_posi] = 0;   // 不需要粉刷
                    else dp[stat_posi][stat_posi] = 1;
                    dp[stat_posi][stat_posi] = min(dp[stat_posi][stat_posi],dp2[stat_posi][stat_posi]);
                    continue;
                }
                int end_posi = stat_posi + length - 1;
                
                //需不需要耍
                bool need_brush = false;
                for(int i = stat_posi; i <= end_posi; i++){
                    if(a[i]!=b[i]){
                        need_brush = true;
                        break;
                    }
                }
                if(!need_brush){    // 不需要刷新
                    dp[stat_posi][end_posi] = 0;
                    continue;   //跳出
                }


                // 假定粉刷过程是有两个区间组成的
                for(int k = stat_posi; k <= end_posi - 1; k++){
                    dp[stat_posi][end_posi] = min(dp[stat_posi][end_posi], dp[stat_posi][k] + dp[k+1][end_posi]);   
                }              
                // 假定粉刷过程为 先刷一遍大区间，再刷小区间,此条件下一定要有b[stat_posi] == b[end_posi]
                if(b[stat_posi] == b[end_posi]){
                    if(l[stat_posi] + 1 <= r[end_posi] - 1)
                        dp[stat_posi][end_posi] = min(dp[stat_posi][end_posi], dp2[l[stat_posi] + 1][r[end_posi] - 1] + 1);
                    else 
                        dp[stat_posi][end_posi] = min(dp[stat_posi][end_posi], 1);
                }
                dp[stat_posi][end_posi] = min(dp[stat_posi][end_posi],dp2[stat_posi][end_posi]);
                
            }
        }
        cout<<dp[1][n]<<endl;
    }

    return 0;
}