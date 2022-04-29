
/*	由于在dfs的时候一定会经过最后一个去掉的点，经过最后一个点的时候一定会发生分类正确，但是什么时候会发生分分类错误呢！！！
	那么最后一个去掉的点有什么特点呢！！！，也就是何时出现错误，
	在这里有一个很好的想法
	就是使用bfs，每次发生删除的时候，表明本次搜索结束！
	删除规则就是，删除的节点到搜索节点都可已删除了，在进行bfs的时候可以使用标记记录路径
	搜索停止的条件是搜索的
*/



#include<vector>
#include<queue>
#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;


const int maxx = (int)4e5+10;
vector<int> edge[maxx];
int res[maxx];
int layer[maxx];
int vis[maxx];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		memset(res,0,sizeof(res));
		memset(layer,0,sizeof(layer));
		memset(vis,0,sizeof(vis));
		int n,k;
		scanf("%d%d",&n,&k);

		for(int i=0;i<n;i++)edge[i].clear();
		for(int i=0;i<n-1;i++){
			int p_a,p_b;
			scanf("%d%d",&p_a,&p_b);
			p_a--;
			p_b--;
			edge[p_b].push_back(p_a);
			edge[p_a].push_back(p_b);
			res[p_a]++;
			res[p_b]++;
		}

		int ans=0;
		queue<int > q;
		for(int i=0;i<n;i++){
			if(res[i]<=1){
				q.push(i);
				layer[i]=1;
				ans++;
			}
		}

		while(!q.empty())
		{
			int posi = q.front();
			q.pop();		//当前点的位置！！
			if(layer[posi]==k)continue;
			vector<int>::iterator iter;
			for(iter = edge[posi].begin(); iter != edge[posi].end(); iter++)
			{
			
				if(res[*iter]>1){
					res[*iter]--;
					if(res[*iter]==1){
						layer[*iter] = layer[posi]+1;
						q.push(*iter);
						if(layer[posi]+1<=k)
							ans++;
					}

				}
			}
		}

		cout<<n-ans<<endl;
	}
	
	return 0;
}



