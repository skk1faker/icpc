#include<iostream>
#include<cstring>
#include<vector>

using namespace std;
const int maxx = (int)1e4+10;

struct edge
{
	int p,l;
	edge(int p,int l):p(p),l(l){}
};

vector<edge>tree[maxx];
int dp[maxx][3];// [0,1,2] ==> [big, second big, fa]

void dfs(int pre,int now_p){
	if(tree[now_p].size() == 1 && tree[now_p][0].p == pre){
		dp[now_p][0] = 0;
		dp[now_p][1] = 0;
		return ;
	}
	for(auto sun_edge: tree[now_p]){
		int sun = sun_edge.p;
		if(sun == pre)continue;
		dfs(now_p,sun);
		if(dp[now_p][0] < dp[sun][0] + sun_edge.l){
			dp[now_p][1] = dp[now_p][0];
			dp[now_p][0] = dp[sun][0] + sun_edge.l;
		}
		else if(dp[now_p][1] < dp[sun][0] + sun_edge.l){
			dp[now_p][1] = dp[sun][0] + sun_edge.l;
		}
	}
}

void dfs_fa(int pre, int now_p){
	
	for(auto sun_edge: tree[now_p]){
		int sun = sun_edge.p;
		int length = sun_edge.l;
		if(sun == pre)continue;
		dp[sun][2] = dp[now_p][2] + length;
		if(dp[now_p][0] == dp[sun][0] + length){
			dp[sun][2] = max(dp[sun][2], dp[now_p][1] + length);
		}
		else{
			dp[sun][2] = max(dp[sun][2], dp[now_p][0] + length);
		}
		dfs_fa(now_p, sun);
	}
		
}

int main()
{
	int n;
	while(scanf("%d",&n) == 1){
		memset(dp,0,sizeof(dp));
		for(int i = 1;i <= n;i++)tree[i].clear();
		for(int u = 2;u <= n;u++){
			int v,w;
			scanf("%d%d",&v,&w);
			tree[u].push_back(edge(v,w));
			tree[v].push_back(edge(u,w));
		}
		dfs(-1,1);
		dp[1][2] = 0;
		dfs_fa(-1,1);
		for(int i = 1;i <= n;i++ ){
			cout<<max(dp[i][0],dp[i][2])<<endl;
		}
	}
	return 0;
}
