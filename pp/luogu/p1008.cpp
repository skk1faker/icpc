#include<iostream>
#include<cstring>
using namespace std;
int posi[10];
int ans[3];
void dfs(int finish)
{
	if(finish==9){
		if((ans[1] == (2*ans[0]))&&(ans[2] == (3*ans[0]))){
			printf("%d %d %d\n",ans[0],ans[1],ans[2]);
		}
		return ;
	}
	for(int i=1;i<=9;i++){
		if(posi[i]==1)continue;

		posi[i]=1;
		ans[(finish)/3]*=10;
		ans[(finish)/3]+=i;

		dfs(finish+1);

		ans[(finish)/3]-=i;
		ans[(finish)/3]/=10;
		posi[i]=0;
	}
	return ;
}
int main()
{
	memset(ans,0,sizeof(ans));
	memset(posi,0,sizeof(posi));
	dfs(0);
	return 0;
}
