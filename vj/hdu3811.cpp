//int dp[maxx][17];//	[statue][j],statue 表示使用了那些数字,j表示到达哪一位了，dp表示有多少种情况
#include<iostream>
#include<cstring>
using namespace std;
const int maxx = 1<<17+1;

long long dp[maxx];
int g[18][18];
int cnt[maxx];
long long f[18];
void init()
{
	f[0] = 1;
	for(int i= 1;i <=17;i++){
		f[i] = f[i-1] * i;
	}
	for(int i = 0;i < maxx;i++){
		cnt[i] = 0;
		for(int j = 0;j < 17;j++){
			if(i & (1<<j))cnt[i]++;
		}
	}
}

int main()
{
	int T,Case = 1;
	init();
	cin>>T;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1; i <= n;i++)
			for(int j = 1;j <= n;j++)
				g[i][j] = 1;
		for(int _ = 0;_ < m;_++){
			int a,b;
			scanf("%d%d",&a,&b);
			g[a][b] = 0;		// 第a位是数字b
		}

		dp[0] = 1;//一个数字也没有使用，这种数字有0个,这里计算反面,但为了方便计数，这里写为1
		for(int i = 1;i < (1<<n);i++){
			dp[i] = 0;
			for(int j = 0;j < n;j++){	// j 表示数字j + 1
				if((i&(1<<j)) != 0 && g[cnt[i]][j + 1] == 1){
					dp[i] += dp[i - (1<<j)];
				}
			}
		}
		printf("Case %d: %lld\n",Case++, f[n] - dp[(1<<n)-1]);
	}
	return 0;
}
// 假设前i位已经使用了a1,a2,a3..ai数字，那么下一位为什么取决于前面的几个数组是否满足题义

