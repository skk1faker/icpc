#include<cstring>
#include<iostream>
using namespace std;
const int maxm = (int)1e3 + 10;
const int maxn = (int)1e4 + 10;
const int INF = 0x7ffffff;
int dp[2][maxm];
int x[maxn][2];	// [0] -- >down [1] --> up
int mapp[maxn][2];
int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	for(int i = 0;i <= n - 1;i++)scanf("%d%d",&x[i][1],&x[i][0]);

	memset(mapp,-1,sizeof(mapp));

	for(int i = 0 ;i < k;i++){
		int P,L,H;
		scanf("%d%d%d",&P,&L,&H);
		mapp[P][0] = L;
		mapp[P][1] = H;
	}
	int pipe = 0;
	dp[0][0] = INF;	//
	for(int i = 1;i <= m;i++) dp[0][i] = 0;	// 没有进行点击
	for(int i = 1;i <= n;i++){	// 计算当前位置
		int h,l;
		// dp[][] = INF,不参与转移！！
		if(mapp[i][0] == -1){
			l = 1;
			h = m;
		}
		else {
			l = mapp[i][0] + 1;
			h = mapp[i][1] - 1;
		}
		for(int j = 0; j<= m;j++)dp[i % 2][j] = INF; // 初始化
		int flag = 0;
		for(int j = 1; j <= m;j++){	// 注意这里一定是1 -- m而不是 l -- h
			if(j - x[i - 1][1] >= 1)dp[i % 2][j] = min(dp[i%2][j], min(dp[(i - 1) % 2][j - x[i - 1][1]], dp[i%2][j - x[i - 1][1]]) + 1 );	// 向上		完全背包
		}	
		// 注意，01背包和完全背包要分开求，因为完全背包有一个优化要用到以前的信息，如果这个时候一起求，完全背包的数据会被覆盖，无法正确的求出。
		for(int j = l; j <= h;j++){
			if(j + x[i - 1][0] <= m)dp[i % 2][j] = min(dp[i%2][j], dp[(i - 1) % 2][j + x[i - 1][0]]);	// 向下			01背包
		}
		if(h == m){
			for(int temp = max(0,m - x[i - 1][1]);temp <= m;temp++){
				dp[i % 2][m] = min(dp[i % 2][m],min(dp[(i - 1) % 2][temp],dp[i % 2][temp]) + 1);
			}
		}
		for(int j = 0;j <= m;j++){
			if(l<=j && j<=h)continue;
			dp[i % 2][j] = INF;
		}
		for(int j = l; j <= h;j++)if(dp[i % 2][j] < INF)flag = 1;
		if(flag == 0){
			cout<<0<<endl<<pipe<<endl;
			return 0;
		}
		if(mapp[i][0] != -1)pipe++;
	}
	int ans = INF;
	for(int i = 1;i <= m;i++)ans = min(ans, dp[n % 2][i]);
	cout<<1<<endl<<ans<<endl;
	return 0;
}
/*
优化
dp[i][j] = (click >= 1)min(dp[i - 1][j - click * x[i - 1][1]] + click )
		 = min(dp[i - 1][j - x[i - 1][1]] + 1, (click >= 1)min(dp[i - 1][j - x[i - 1][1] - click * x[i - 1][1]] + click + 1))
		 = min(dp[i - 1][j - x[i - 1][1]], dp[i][j - x[i - 1][1]]) + 1
*/
/*
注意数据
3 8 3
5 4
1 6
6 7
1 1 4
2 5 7
3 3 8


0
2
*/
