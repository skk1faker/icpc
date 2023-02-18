#include<iostream>
#define ll long long 
using namespace std;
const int max_n = (int)1e6 + 10;
const int max_m = (int)2;
ll dp[max_m][max_n];
ll dp_max[max_m][max_n];
ll sum[max_n];
int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n) == 2){
		sum[0] = 0;// 必须有这句，不然下面没有办法继续
		for(int i = 1;i <= n;i++){
			ll temp_ele;
			scanf("%lld",&temp_ele);
			sum[i] = sum[i - 1] + temp_ele;
		}
		// 对dp初始化的时候就考虑dp的含义就可以，至于初始化哪个状态，这要看状态转移公式第一个需要的值是谁，如果不清楚第一个值是谁，可以画图看计算方向（将每个状态用坐标表示，观察计算方向）。
		for(int i = 0;i <= n; ++i){
			dp[0][i] = 0;//段长为0，值为0
			dp_max[0][i] = max(dp_max[0][i - 1], dp[0][i] - sum[i]);
		}
		for(int i = 1;i <= m;i++){
			dp[i%2][i] = sum[i];	// dp初始化，每段只有一个元素
			dp_max[i%2][i] = dp[i%2][i] - sum[i];
			for(int j = i+1;j <= n;j++){
				dp[i%2][j] = max(dp[i%2][j-1], dp_max[(i-1)%2][j - 1] + sum[j]); 
				dp_max[i%2][j] = max(dp_max[i%2][j - 1], dp[i%2][j] - sum[j]);
			}
		}
		cout<<dp[m%2][n]<<endl;
	}
	return 0;
}
