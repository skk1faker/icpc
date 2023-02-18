#include<iostream>
#include<cstring>
using namespace std;
int map[10][10];
int dp[9][9][9][9];//(x1,y1),(x2,y2)
int nnext[2][2]={{0,1},{1,0}};	//[操作][坐标]
bool out_filed(int *x,int *y,int N)
{
	return !(x[0]<N&&x[1]<N&&y[0]<N&&y[1]<N);
}
int N;
int dfs(int *x,int *y)
{
	if(dp[x[0]][y[0]][x[1]][y[1]]!=-1)	return dp[x[0]][y[0]][x[1]][y[1]];
	int new_x[2],new_y[2];
	int & ans = dp[x[0]][y[0]][x[1]][y[1]];
	int extra;
	for(int p1 = 0; p1<2; p1++){
		for(int p2 = 0; p2 < 2; p2++){
			new_x[0] = x[0]+nnext[p1][0];
			new_y[0] = y[0]+nnext[p1][1];
			new_x[1] = x[1]+nnext[p2][0];
			new_y[1] = y[1]+nnext[p2][1];
			if(x[0]==x[1]&&y[0]==y[1])extra = map[x[0]][y[0]];
			else extra = map[x[0]][y[0]] + map[x[1]][y[1]];
			if(out_filed(new_x,new_y,N))continue;//超界除去
			ans = max(ans, extra + dfs(new_x,new_y));
		}
	}
	return ans;
}
int main()
{

	scanf("%d",&N);
	int x,y,v;
	while(scanf("%d%d%d",&x,&y,&v)==3&&(!(x==0&&y==0&&v==0))){
		x--,y--;
		map[x][y]=v;
	}

	memset(dp,-1,sizeof(dp));
	dp[N-1][N-1][N-1][N-1] = map[N-1][N-1];
	int temp_x[2]={0,0};
	int temp_y[2]={0,0};
	cout<<dfs(temp_x,temp_y)<<endl;;
	return 0;
}
