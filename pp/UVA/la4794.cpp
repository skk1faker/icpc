#include<iostream>
#include<cstring>
using namespace std;
const int maxn = (1<<15)+10;
int area[maxn];
int dp[maxn][105];
int dfs(int set,int x)
{
	if(dp[set][x] != -1)return dp[set][x];
	if(area[set]%x != 0){
		dp[set][x]=0;
		return 0;
	}
	int y = area[set] / x;
	if((set&(set-1))==0){
		dp[set][x]=1;
		dp[set][y]=1;
	}
	if(dp[set][y] != -1)return dp[set][y];
	for(int sub_set = set&(set-1);sub_set;sub_set = (sub_set-1)&set){	//注意，这里set-1 表示不是全集！！
		int com_sub_set = set - sub_set;
		dp[set][y] = (int)((dfs(sub_set,y) == 1&& dfs(com_sub_set,y) == 1)||(dfs(sub_set,x) ==1 && dfs(com_sub_set,x) == 1));
		dp[set][x] = dp[set][y];	
		if(dp[set][x]==1)return 1;


	}
	dp[set][x]=0;
	dp[set][y]=0;
	return dp[set][x];
}

int Case = 0;

int main()
{
	int n,x,y;
	while(scanf("%d",&n)==1&&n!=0){
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&x,&y);
		for(int i=0 ;i<n;i++){
			scanf("%d",&area[1<<i]);
		}
		for(int i=1;i<(1<<n);i++){
			if((i&(i-1))==0)continue;
			int temp_i=i;
			int posi = 0;
			area[i] = 0;
			while(temp_i){
				if(temp_i%2){
					area[i] += area[1<<posi];
				}
				posi++;
				temp_i/=2;
			}
		}
		
		printf("Case %d: ",++Case);
		/*
		if(area[(1<<n)-1] != x*y){
			printf("No\n");
			continue;
		}*/
		if(dfs((1<<n)-1,x) == 1){
			printf("Yes\n");
		}
		else printf("No\n");
	}
	return 0;
}
