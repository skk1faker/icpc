//https://zybuluo.com/ysner/note/1236827
#include<iostream>
#include<cstring>
const int maxx = (int)1e5+10;
double dp[maxx][100 + 5];		// dp[i][j]表示i架子剩下没有添过的罐子的数量j, 每次取罐子之后,注意罐子数量可能很多，但是没有添过的罐子就那么多。
// int dp_temp[100 + 1];		// 用于实现状态转移的中间过程
int L[maxx];	// 罐子的数量
int L_ori[maxx];
using namespace std;

double C(int a,int b){
	if(b == 0 || a == 0||a == b)return 1;
	double ans = 1;
	a = min(a,b - a);
	for(int i = 1;i <= a; i++){
		ans = ans * (b - i + 1) / i;
	}
	return (double)ans;
}

double P_get_clearpot(int j,int l, int u,int k){
	return C(l,j+l) * C(k - l, L[u] - j - l) / C(k,L[u]);
}

int main()
{
	int n;
	cin >> n;
	memset(dp,0,sizeof(dp));
	double ans = 0;
	for(int i = 1;i <= n;i++){
		int temp ;
		scanf("%d",&temp);
		ans += (temp == 0); 
		dp[i][temp] = 1;
		L[i] = temp;
		L_ori[i] = temp;
	}
	int q;
	cin >> q;
	while(q--){
		int u,v,k;
		scanf("%d%d%d",&u,&v,&k);
		ans -= dp[u][0];
		for(int j = 0;j <= L_ori[u];j++){	// 假设添完之后剩下的没添过的罐子。
			double temp = 0;
			for(int l = 0;l <= k && L[u] - l - j >= k - l;l++){	// l --> 取出的罐子没被添过。
				temp += dp[u][j + l] * (P_get_clearpot(j,l,u,k));
			}	
			dp[u][j] = temp;
		}
		ans += dp[u][0];
		L[v] += k;
		L[u] -= k;
		//cout<<ans<<endl;
		printf("%.15lf\n",ans);
	}
	return 0;
}
