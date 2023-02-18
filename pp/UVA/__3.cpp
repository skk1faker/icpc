#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

const int maxx=1e3+5;

vector<int> graph[maxx];
vector<int> deep_point[maxx];
int fath[maxx];
int max_deep;
bool get_signal[maxx];
void dfs_get_info(int posi,int pre_posi,int length,int n){
	fath[posi]=pre_posi;
	if(graph[posi].size()==1){//叶子节点！！！
		deep_point[length].push_back(posi);
		max_deep = max(max_deep, length);
	}
	for(int i=0;i<graph[posi].size();i++){
		if(!(pre_posi!=graph[posi][i]))continue;
		dfs_get_info(graph[posi][i],posi,length+1,n);
	}
}
bool dfs_check(int deep,int posi,int pre_posi){
	bool ans=false;
	for(int i=0;i<graph[posi].size();i++){
		int v = graph[posi][i];
		if(v == pre_posi)continue;
		if(graph[v].size() == 1 && get_signal[v] == false){
			ans=true;
			get_signal[v]=true;
		}
		else 
			ans = ans||dfs_check(deep+1, v,posi);
	}
	return ans;
}
int solve(int n,int s,int k)
{
	int ans=0;
	dfs_get_info(s,-1,0,n);
	dfs_check(0,s,-1);	//首先将s能覆盖的区域计算完
	for(int d = max_deep; d>=0;d--){
		for(int i=0;i<deep_point[d].size();i++){
			if(!(get_signal[deep_point[d][i]] == 0))continue;//没有收到讯号！！！注意在这里面的都是叶子节点
				int v;
				v = deep_point[d][i];
				for(int j=0;j<k;j++)v=fath[v];//寻找了k次！！
				if(v==-1||fath[v]==-1)continue;//表示安装的节点是根节点，这个节点已经有了东西！！！
				if(dfs_check(0,v,-1))ans++;
		}
	}
	return ans;
}
int main()
{
	int T;
	cin>>T;
	int n,s,k;
	while(T--){
		scanf("%d%d%d",&n,&s,&k);
		s--;
		max_deep = -1;
		//initial
		for(int i=0;i<n;i++){
			graph[i].clear();
			deep_point[i].clear();//最深距离为n-1,根根为0
		}
		memset(get_signal,0,sizeof(get_signal));
		for(int i=0;i<n-1;i++){

			int temp[2];
			scanf("%d%d",&temp[0],&temp[1]);
			temp[0]--,temp[1]--;
			graph[temp[0]].push_back(temp[1]);
			graph[temp[1]].push_back(temp[0]);
		}
		cout<<solve(n,s,k)<<endl;
	}
	return 0;
}
