








/*
//Dinic	未成功！！！原因未知。。。
#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

const int maxx = 200+5;
int flow[maxx][maxx];
int level[maxx];
bool bfs(int st,int en)
{
	bool flag = false;		//如果找到终点设置==true
	queue<int> q;
	memset(level,-1,sizeof(level));
	level[st]=0;
	q.push(st);
	while(!q.empty()){
		int now_point = q.front();
		q.pop();
		if(now_point == en)flag = true;
		for(int i=0 ; i<=en; i++){
			if(level[i]==-1&&flow[now_point][i] > 0){
				level[i] = level[now_point] + 1;
				q.push(i);
			}
		}
	}
	
	return flag;
}


int dfs(int now_posi,int en, int min_cap)
{
	if(now_posi == en){
		return min_cap;
	}
	int ans = 0;
	for(int i=0; i<=en; i++){
		if(flow[now_posi][i]>0 && level[i] == level[now_posi]+1){
			int f = dfs(i,en,min(min_cap,flow[now_posi][i]));
			ans += f;
			flow[now_posi][i] -= f;
			flow[i][now_posi] += f;
			min_cap -= f;
			if(min_cap == 0)break;
		}
	}
	return ans;
}

int solve(int n ,int m)
{
	memset(flow,0,sizeof(flow));
	for(int i=0;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		scanf("%d",&flow[x][y]);
	}
	int ans = 0;
	while(bfs(0,m-1))	//网络流可以到达终点
	{
		ans += dfs(0,m-1,1e9);
	}
	return ans;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)==2){
		cout<<solve(n,m)<<endl;
	}
	return 0;
}
*/



/*
bool bfs(int st,int en)
{
	bool flag = false;		//如果找到终点设置==true
	int queue[maxx];
	memset(level,-1,sizeof(level));
	level[st]=0;
	int front = 0, tail = 0;
	queue[front] = st;
	front = front+1;
	while(tail != front){
		int now_point = queue[tail];
		tail = (tail + 1) % maxx;	// 队列对其最大长度取模即可！这里的maxx一定是队列的最大长度！
		if(now_point == en)flag = true;
		for(int i=0 ; i<=en; i++){
			if(level[i]==-1&&flow[now_point][i] > 0){
				level[i] = level[now_point] + 1;
				queue[front] = i;
				front = (front + 1) % maxx;
			}
		}
	}
	
	return flag;
}
*/

