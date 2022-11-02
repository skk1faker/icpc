#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>

using namespace std;

const int point_max = 50001;
int dp[point_max][501];	// dp[i][j]，i树下到i节点的距离为j的有多少
vector<int> tree[point_max];
int n,k;
int ans;

void dfs(int fa,int now_posi)
{
	if(tree[now_posi].size() == 1 && tree[now_posi][0] == fa){
		dp[now_posi][0] = 1;
		return ;
	}
	for(auto sun: tree[now_posi]){	// now_posi 的子
		
		if(sun == fa)continue;
		dfs(now_posi,sun);
		dp[now_posi][0] = 1;
		for(int i = 1;i <= k - 1;i++){
			ans += dp[now_posi][i] * dp[sun][k - i - 1];
		}
		for(int i = 1;i <= k;i++){
			dp[now_posi][i] += dp[sun][i - 1];
		}

	}
	ans += dp[now_posi][k];

	return ;
}

int main()
{
	cin>>n>>k;
	memset(dp,0,sizeof(dp));
	for(int i = 0;i < n - 1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	ans = 0;
	dfs(-1,1);
	cout<<ans<<endl;
	return 0;
}
