#include<iostream>
#include<vector>
using namespace std;
const int maxx = 1500;

int dp[maxx][2];		//[0,1]无i节点,有i节点
vector<int>tree[maxx];

void dfs(int pre ,int now_posi){
	dp[now_posi][0] = 0;
	dp[now_posi][1] = 1;
//	for(auto son:tree[now_posi]){
	for(vector<int>::iterator iter = tree[now_posi].begin();iter != tree[now_posi].end();iter++){
		int son = *iter;
		if(son == pre)continue;
		dfs(now_posi,son);
		dp[now_posi][0] += dp[son][1];
		dp[now_posi][1] += min(dp[son][0], dp[son][1]);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n) == 1){
		for(int i = 0;i < n;i++){	
			tree[i].clear();
		}
		for(int j = 0;j < n;j++){
			int u,m,v;
			scanf("%d:(%d)",&u ,&m);
			for(int i = 0;i < m;i++){
				scanf("%d",&v);
				tree[u].push_back(v);
				tree[v].push_back(u);
			}
		}
		dfs(-1,0);
		cout<<min(dp[0][1],dp[0][0])<<endl;

	}
	return 0;
}

