#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
const int maxt = (int)1e5+10;
int dp[11][2];
int down_pie[11][maxt];
int main()
{
    int max_T;
    int n;
    while(scanf("%d",&n) == 1&&n != 0){
        max_T = 0;
        memset(down_pie,0,sizeof(down_pie));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++){
            int posi,tim;
            scanf("%d%d",&posi,&tim);
            max_T = max(max_T, tim);
            down_pie[posi][tim]++;
        }
        int ans = 0;
        for(int t = 1;t <= max_T; t++){
            for(int posi = 0; posi < 11; posi++){
                if(5 - t > posi || posi > 5 + t)continue;   // 注意这个位置，第一个元素要从posi == 5 开始，所以要限制一下
                if(posi == 0){
                    dp[posi][t%2] = max(dp[posi][(t-1)%2], dp[posi+1][(t-1)%2]);
                }
                else if(posi == 10){
                    dp[posi][t%2] = max(dp[posi][(t-1)%2], dp[posi-1][(t-1)%2]);
                }
                else {
                    dp[posi][t%2] = max(dp[posi][(t-1)%2], dp[posi+1][(t-1)%2]);
                    dp[posi][t%2] = max(dp[posi][t%2], dp[posi-1][(t-1)%2]);
                }
                dp[posi][t%2] += down_pie[posi][t];
                ans = max(ans, dp[posi][t%2]);
            }
        }
        printf("%d\n",ans);


    }
    return 0;
}