#include<iostream>
using namespace std;
//注意这道题，可以用dfs，但是由于这道题不可能有回溯，因为dfs算法中一个点要选用26个值，但是一个点最多与4个值相邻，所以不用退栈！！
const int maxx=11;
bool ok(int row,int column,int value,int edge, char (*ans)[maxx]){
	int director[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	int new_row,new_column;
	for(int i=0;i<4;i++){
		new_row=row+director[i][0];
		new_column=column+director[i][1];
		if(!(new_row>=0&&new_row<edge&&new_column>=0&&new_column<edge))continue;
		if((char)(value+'A')==ans[new_row][new_column])return false;
	}
	return true;
}
int main()
{
	int T;
	cin>>T;
	int Case=0;
	int n;
	char ans[maxx][maxx];
	while(T--){
		printf("Case %d:\n",++Case);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char temp;
			for(int j=0;j<n;j++){
				do{scanf("%c",&temp);}while(!(temp=='.'||(temp<='Z'&&temp>='A')));
				ans[i][j]=temp;
			}
		}
		

		//solve

		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(ans[i][j]!='.')continue;
				for(int value=0;value<26;value++){
					if(ok(i,j,value,n,ans)){
						ans[i][j]=value+'A';
						break;
					}
				}
				
			}
			ans[i][n]=0;
		}
		for(int i=0;i<n;i++)	
			printf("%s\n",ans[i]);
	}
	return 0;
}
