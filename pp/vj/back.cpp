#include<iostream>
#include<cstring>
#include<vector>
#include<set>

using namespace std;
const int maxx = (int)1e4+10;

struct edge{
	int point_to,length;
	edge(int point_to = 0,int length = 0):point_to(point_to),length(length){}
	bool operator < (const edge temp)const{
		return this->length < temp.length;
	}
};
struct fa_edge
{
	int fa, next_sun,length,lengths;
	fa_edge(int fa,int next_sun,int length,int lengths):fa(fa),next_sun(next_sun),length(length),lengths(lengths){}
	bool operator < (const fa_edge temp)const{
		return this->fa < temp.fa;
	}
};
int dp[maxx][2];
vector<edge>tree[maxx];
set<fa_edge>fa_set[maxx];	// 应加入路径中此点到下一个子的距离	//也可以视为根节点到本节点的路经

void dfs(int fa,int now_posi,int length){
	if(fa != -1){
		fa_set[now_posi].insert(fa_edge(fa,now_posi,length,length));
		for(auto fa_ele :fa_set[fa]){
			fa_ele.lengths += length;
			fa_set[now_posi].insert(fa_ele);
			fa_ele.lengths -= length;
		}
	}
	
	if(tree[now_posi].size() == 1){
		dp[now_posi][0] = 0;
		dp[now_posi][1] = 0;
		return ;
	}
	
	for(auto sun_edge : tree[now_posi]){
		int sun = sun_edge.point_to;
		if(sun == fa)continue;
		dfs(now_posi,sun, sun_edge.length);
		int max_length_to_sun =  dp[sun][0] + sun_edge.length;
		if(dp[now_posi][0] < max_length_to_sun){
			dp[now_posi][1] = dp[now_posi][0];
			dp[now_posi][0] = max_length_to_sun;
		}
		else if(dp[now_posi][1] < max_length_to_sun){
			dp[now_posi][1] = max_length_to_sun;
		}
	}
	return ;
}

int main()
{
	int n;
	cin>>n;

	for(int i = 2;i <= n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		tree[i].push_back(edge(u,v));
		tree[u].push_back(edge(i,v));
	}
	dfs(-1,1,0);
	int ans = 0;
	for(int i = 1;i <= n;i++){
		ans = dp[i][0];
		for(auto fa_ele:fa_set[i]){
			int fa_point = fa_ele.fa;
			if(fa_point == -1)continue;
			int fa_length = fa_ele.lengths;
			if(fa_ele.length + dp[fa_ele.next_sun][0] == dp[fa_point][0]){
				ans = max(ans, fa_length + dp[fa_point][1]);
			}
			else {
				ans = max(ans, fa_length + dp[fa_point][0]);
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
