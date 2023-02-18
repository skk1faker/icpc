#include<iostream>
using namespace std;
int ans[9];
int vis[9];
void dfs(int not_finish){
	if(not_finish == 0){
		for(int i = 0;i < 8;i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
		return ;
	}
	for(int i = 0;i < 8;i++){
		if(vis[i] == 1)continue;
		vis[i] = 1;
		ans[8 - not_finish] = i + 1;
		dfs(not_finish - 1);
		vis[i] = 0;
	}
	return ;

}
int main()
{
	dfs(8);
	return 0;
}
