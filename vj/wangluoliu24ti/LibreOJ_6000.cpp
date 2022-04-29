//Dinic 算法尝试(chenggong )

#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<queue>
using namespace std;
const int maxx = 205;
int flow[maxx][maxx];
int level[maxx];

bool bfs(int n)		// 分层
{
	int st = 0,en = n+1;
	bool flag = false;
	queue<int> q;
	q.push(st);
	memset(level,-1,sizeof(level));
	level[st] = 0;

	while(!q.empty()){
		int now_posi = q.front();
		if(now_posi == en)flag = true;
		q.pop();
		for(int i = 0;i<=n+1;i++){
			if(flow[now_posi][i]>0&&level[i]==-1){
				level[i] = level[now_posi] + 1;
				q.push(i);
			}
		}
	}
	return flag;
}

int dfs(int now_posi ,int en, int min_cap)	// 寻找流
{
	if(now_posi == en){
		return min_cap;
	}
	int ans = 0;
	for(int i=0;i<=en;i++){
		if(level[now_posi]+1 == level[i]&& min(min_cap,flow[now_posi][i])>0){
			int f = dfs(i,en,min(min_cap, flow[now_posi][i]));
			flow[now_posi][i] -= f;
			flow[i][now_posi] += f;
			min_cap -= f;
			ans += f;
		}
	}
	return ans;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	// build flow
	memset(flow,0,sizeof(flow));
	for(int i=1;i<=n;i++){
		if(i<=m) flow[0][i] = 1;
		else flow[i][n+1] = 1;
	}
	int x,y;
	while(scanf("%d%d",&x,&y)==2)flow[x][y] = 1;
	int ans = 0;
	while(bfs(n)){
		ans += dfs(0,n+1,(int)1e9);
	}
	cout<<ans<<endl;
	return 0;

}





/*
// Edmonds-Karp 算法
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int max_size = 105;
int flow[max_size][max_size];
int route[max_size];
int vis[max_size];


int bfs(int n)
{
	int st = 0,en = n+1;
	queue<int> q;
	q.push(st);
	memset(route,-1,sizeof(route));
	memset(vis,0,sizeof(vis));
	vis[0] = 1;
	while(!q.empty()){
		int now_posi = q.front();
		q.pop();
		if(now_posi == en)break;
		for(int i=0;i<=n+1;i++){
			if(flow[now_posi][i] > 0&&vis[i] == 0){
				route[i] = now_posi;
				vis[i] = 1;
				q.push(i);
			}
		}
	}
	int now = en;
	int ans = 10000;
	if (vis[en] == 0){
		return 0;
	}
	while(route[now] != -1){
		ans = min(ans , flow[route[now]][now]);
		now = route[now];
	}
	now = en;
	while(route[now] != -1){
		flow[route[now]][now] -= ans;
		flow[now][route[now]] += ans;
		now = route[now];
	}
	return ans;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	
	// build flow
	for(int i=1;i<=n;i++){
		if(i<=m) flow[0][i] = 1;
		else flow[i][n+1] = 1;
	}
	int x,y;
	while(scanf("%d%d",&x,&y)==2)flow[x][y] = 1;

	int ans=0;
	int f = 0;
	while(f = bfs(n))ans += f;
	cout << ans<<endl;
	return 0;

}
*/
