#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxx = (int)1e5+10;

struct Edge
{
	int u;
	int num;
	Edge * next;
};

Edge * first_edge[maxx];
int vis[maxx];
int ans[maxx];	// 最后+=2

int path[maxx];
void dfs(int now_posi,int now_ans)
{
	path[now_posi] = 1;
	for(Edge * e = first_edge[now_posi];e!=NULL;e = e->next){
		if(path[e->u]==1)continue;
		ans[e->num] = now_ans;
		dfs(e->u,!(now_ans));
		now_ans = !(now_ans);	//下一个答案应该为和当前边不一样的答案
	}
	path[now_posi] = 0;
}

bool justify(int n)
{
	for(int i=0;i<n;i++){
		if(vis[i]>2)return true;
	}
	return false;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){	//初始化	
			first_edge[i] = NULL;
			vis[i]=0;
		}
		Edge * temp;
		for(int i=0;i<n-1;i++){
			int u,v;
			scanf("%d%d",&u,&v);
			u--,v--;
			vis[u]++,vis[v]++;
			temp = (Edge *)malloc(sizeof(Edge));
			temp->u = v;
			temp->num = i;
			temp->next = first_edge[u];
			first_edge[u] = temp;
			temp = (Edge*)malloc(sizeof(Edge));
			temp->u = u;
			temp->num = i;
			temp->next = first_edge[v];
			first_edge[v] = temp;
		}
		if(justify(n)){
			cout<<-1<<endl;
		}
		else {
			memset(path,0,sizeof(path));
			dfs(0,0);
			for(int i=0;i<n-1;i++){
				cout<<ans[i]+2<<' ';
			}
			cout<<endl;
		}
		for(int i=0;i<n;i++){		// 链表删除！
			while(first_edge[i]!=NULL){
				Edge * now = first_edge[i];
				first_edge[i] = first_edge[i]->next;
				free(now);
			}
		}
	}
	return 0;
}
