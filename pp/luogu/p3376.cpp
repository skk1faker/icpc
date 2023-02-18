#include<iostream>
#include<cstring>
using namespace std;
#define LL long long 

const long long maxx = 200+5;
LL res_flow[maxx][maxx];		//表示能推多少流
long long que_next(long long posi){return (posi+1)%maxx;}
bool bfs(long long st,long long en ,long long n,long long *level)
{
	long long queue[maxx];
	long long front = 0,tail = 0;
	memset(level,-1,n*sizeof(long long));
	queue[front] = st;
	level[st] = 1;
	front = que_next(front);	//指向下一个空位置！
	bool flag = false;
	while(tail != front){
		long long nowposi = queue[tail];
		tail = que_next(tail);
		for(long long i=0;i<n;i++){
			if(res_flow[nowposi][i]>0&&level[i]==-1){
				level[i] = level[nowposi] + 1;
				queue[front] = i;
				front = que_next(front);	
				if(i==en)flag = true;
			}
				
		}
	}
	return flag;
}

LL dfs(long long now_posi,long long en ,long long n,long long *level, LL cap)	 //cap 代表当前能推过去的流，dfs表示从now_posi能推出去多少流
{
	if(now_posi == en){
		return cap;
	}
	LL ans=0;
	for(long long i=0;i<n;i++){
		if(res_flow[now_posi][i]>0&&level[now_posi] == level[i] - 1){
			long long flow = dfs(i,en,n,level,min(cap,res_flow[now_posi][i]));
			cap -= flow;	// 注意此时的flow小于cap
			res_flow[now_posi][i] -= flow;
			res_flow[i][now_posi] += flow;
			ans += flow;
		}
	}
	return ans;
}

long long solve(long long n,long long s,long long t)
{
	LL inf = 2147483647;
	long long ans = 0;
	long long level[maxx];
	while(bfs(s,t,n,level)){
		ans += dfs(s,t,n,level,inf);
	}
	return ans;
}

int main()
{
	long long n,m,s,t;
	cin>>n>>m>>s>>t;
	s--,t--;
	for(long long i=0 ;i<m;i++){
		long long x,y;
		cin>>x>>y;
		x--,y--;
		cin>>res_flow[x][y];
	}
	cout<<solve(n,s,t)<<endl;
	return 0;
}

