#include<iostream>
#include<cstring>
using namespace std;
const int maxn = 12;
const int maxstat = 1<<12;
long long dp[maxn][maxstat];		// dp[i][s]表示i行上面摆放状态位s，s位1的位置长方形竖直，0的位置未知

bool just_succssful(int status, int m){
	int length = 0;
	for(int i = 0;i < m;i++){
		if((status & (1<<i)) == 0){
			length++;
		}
		else {
			if((length % 2) == 1)return  false;
			length = 0;
		}
	}
	return (length % 2) == 0;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) == 2){	// 行列
		if(n == 0 && m == 0)break;

		// initialze
		memset(dp,0,sizeof(dp));
		dp[0][0] = 1;
		for(int i = 1;i < n;i++){	// /共n行
			for(int s1 = 0;s1 < (1<<m);s1++){
				int mask = (s1) ^ ((1<<m) - 1);
				for(int s2 = mask;s2 > 0;s2 = ((s2 - 1) & (mask))){
					// 注意这个地方s2 == 0会导致循环
					if(dp[i - 1][s2] == 0 || !just_succssful(s1+s2,m))continue;	// 是否可以正确摆放,或者上一次有没有这个状态
					dp[i][s1] += dp[i - 1][s2];
				}
				if(just_succssful(s1,m)){
					dp[i][s1] += dp[i - 1][0];
				}
			}
		}
		long long ans = 0;
		for(int s1 = 0;s1 < (1 << m);s1++){
			if(just_succssful(s1 ,m))ans += dp[n - 1][s1];
		}
		//cout<<dp[n][0]<<endl;
		cout<<ans<<endl;
	}
	return 0;
}


/*

1 2
1 3
1 4
2 2
2 3
2 4
2 11
4 11
0 0

1
0
1
2
3
5
144
51205
poj2411

*/
