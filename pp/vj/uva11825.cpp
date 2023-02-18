#include<iostream>

const int max_statue = (1<<16) + 1;
int dp[max_statue];
int cover[max_statue];

int main()
{
    int n;
    int Case = 1;
    while(scanf("%d",&n) == 1 && n != 0){

        for(int i = 0;i <= (1<<n) - 1;i++){
            cover[i] = 0;
            dp[i] = 0;
        }
        for(int i = 0; i < n;i++){
            int m;
            scanf("%d",&m);
            cover[1<<i] = 1<<i;
            for(int j = 0;j < m;j++){
                int temp_posi;
                scanf("%d",&temp_posi);
                cover[1<<i] |= (1<<temp_posi);
            }
        }
        for(int i = 0;i < n;i++){
            for(int s = 1;s <= (1<<i) - 1;s++){
                cover[s|(1<<i)] = cover[(1<<i)] | cover[s];
            }
        }



        for(int S = 1;S <= (1<<n) - 1; S++){
            for(int S0 = S;S0;S0 = (S0 - 1)&S){// S 的子集合
                if(cover[S0] == (1<<n) - 1){
                    dp[S] = std::max(dp[S], dp[S ^ S0] + 1);
                }
            }
        }
        printf("Case %d: %d\n",Case++, dp[(1<<n) - 1]);

    }
    return 0;
}


//题解：
/*
    最开始我想到一种dp方式，dp[i][S]
*/
