#include<iostream>
#include<vector>
using namespace std;
const int maxx = (1<<10) ;
long long dp[maxx][10];
const long long INF = (long long )1e11;
struct point{
	bool flag;
	int b,c,p,r;
	point(int b = 0,int c = 0,int p = 0,int r = 0,bool flag = false):flag(flag),c(c),p(p),r(r),b(b){}
};
// struct point graph[10][10];
vector<point> graph[10];
int main()
{
	/* 首先检查是否有从1-->n的路径
	 * 然后再dp
	 * dp[set][posi];
	*/
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 0; i < m;i++){
		int a,b,c,p,r;
		scanf("%d%d%d%d%d",&a,&b,&c,&p,&r);
		a--;
		b--;
		c--;
		graph[a].push_back(point(b,c,p,r,1));
	}
	for(int i = 0 ;i < (1 << n);i++){
		for(int j = 0; j < n;j++){
			dp[i][j] = INF;
		}
	}
	dp[1][0] = 0;
	bool flag = true;
	while(flag){
		flag = false;
		for(int set_val = 0; set_val < (1<<n);set_val++){
			for(int posi = 0;posi < n;posi++){
				if(dp[set_val][posi] != INF){
					for(vector<point>::iterator it = graph[posi].begin(); it != graph[posi].end(); it++){
						point edge = *it;
						if(edge.flag == 1){
							int next_posi = edge.b;
							int temp_val = dp[set_val | (1 << next_posi)][next_posi];
							if(((1<<edge.c) &set_val) != 0)dp[set_val | (1 << next_posi)][next_posi] = min(dp[set_val | (1 << next_posi)][next_posi], dp[set_val][posi] + edge.p);
							dp[set_val | (1 << next_posi)][next_posi] = min(dp[set_val | (1 << next_posi)][next_posi], dp[set_val][posi] + edge.r);
							if(temp_val != dp[set_val | (1 << next_posi)][next_posi])flag = true;
						}
					}
				}
			}
		}
	}
	long long ans = INF;
	for(int i = 1;i < (1<<(n));i++){
		if((i&(1 << 0))!=0 && (i&(1<<(n - 1)))!=0)ans = min(ans, dp[i][n - 1]);
	}
	if(ans != INF)cout<<ans<<endl;
	else cout<<"impossible"<<endl;
	return 0;
}
