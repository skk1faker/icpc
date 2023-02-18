#include<iostream>
using namespace std;
//问题就是一个生成字符串的问题；


const int maxx=11;
bool justify(int i,int j,char (*ans)[maxx], int row_max,int column_max)	//column_max和row_max表示的是坐标值！！
{
	cout<<i<<j<<endl;
	int director[4][2]={{0,1},{0,-1},{1,0},{-1,0}};	//{x,y}
	for(int k=0;k<4;k++){							//4个方向！！
		int column = i+director[k][0];
		int row = j+director[k][1];
		if(!(column>=0&&column<column_max&&row>=0&&row<row_max))continue;//此位置已经出界
		if(ans[row][column]==ans[i][j])return false;
	}
	return true;
}

bool dfs(int posi, char (*ans)[maxx],int n, int (*tag)[maxx])		//posi表示现在的位置,需要使用最开始的地方的公式进行处理！！
{

	int row=posi/n;
	int column=posi%n;
	if(row==n){//此时一定是超过了界限！！！
		//输出最终的结果！！！(当然也可放在外面输入！！)
		
		
		return true;
	}
	if(tag[row][column]!=1){	//tag！=1表示这个位置可以改变，否则只能进行下一个！！！
		for(int i=0;i<26;i++){
			ans[row][column] = 'A'+i;
			if(justify(row,column,ans,n,n)){		//检测之后发现可以填入！！可以进行下一步的dfs！！
				if(dfs(posi+1, ans ,n ,tag))return true;
			}
		}

	}
	else {		//tag ==1 表示可以直接检测下个位置！！，因为这个位置不能改变！！！
		if(dfs(posi+1, ans, n, tag))return true;
	}
	return false;
}
int main()
{
	int T;
	cin>>T;
	int tag[maxx][maxx];		//tag==1 表示这里是固定的哦！！
	char ans[maxx][maxx];
	int casee=0;
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			char temp;
			for(int j=0;j<n;j++){
				do{
					scanf("%c",&temp);
				}while(!(temp=='.'||(temp>='A'&&temp<='Z')));
				if(temp=='.'){
					ans[i][j]='.';
					tag[i][j]=0;
				}
				else {
					ans[i][j]=temp;
					tag[i][j]=1;
				}
//				printf("%c",ans[i][j]);
			}
//			cout<<endl;
		}
//		cout<<endl;
		if(dfs(0,ans,n,tag)){
			printf("Case %d:\n", ++casee);
			for(int i=0;i<n;i++){
				ans[i][n]=0;
				printf("%s\n",ans[i]);
			}
		}
		else printf("not found\n");

	}
	return 0;
}
