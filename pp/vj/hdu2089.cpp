#include<iostream>
using namespace std;

const int max_length = 7;
int dp[10][max_length];

int dp_val(int the_val)   // 计算x<=the_val中有多少x满足题意
{
    int ans = 0;
    int get_val_tool = (int)1e6;

    int pre_val = -1;
    int flag = 1;       // 最后不要忘了加本位！!!!!!!!!!!!!!!!!!!!!!!!!
    for(int length = max_length;length >=1;length--){   //length 用于表示当前位数
        int this_posi_val = (the_val / get_val_tool) %10;
        // cout<<this_posi_val;
        
        for(int i = this_posi_val-1;i>=0;i--){    // 表示当前位置可以取到的更小的值，但是不包括本位值，本位值不变的时候需要判断下一个位的情况
            if(pre_val == 6 && i == 2)continue;
            ans += dp[i][length];
            // cout<<i<<' '<<ans<<endl;
        }
        if((this_posi_val == 2 && pre_val == 6) || this_posi_val == 4){
            flag = 0;
            break;
        }
        pre_val = this_posi_val;
        get_val_tool /= 10;
    }
    ans += flag;
    return ans;
}

int main()
{
    int n,m;
    for(int i = 0;i<=9;i++)dp[i][1] = 1;
    dp[4][1] = 0;
    for(int length = 2;length <= 7;length++){
        for(int i = 0; i <= 9; i++){
            dp[i][length] = 0;
            if(i == 4)continue;
            for(int j = 0;j<=9;j++){
                if(i == 6&&j==2)dp[i][length] += 0;
                else dp[i][length] += dp[j][length-1];
            }
        }
    }
    while(scanf("%d%d",&n,&m) == 2){
        if(m == 0&& n== 0)break;
        cout<<dp_val(m) - dp_val(n-1)<<endl;
        // cout<<dp_val(m)<<endl;
    }
    return 0;
}


