#include<iostream>
#include<cstring>

using namespace std;
const int maxx = (1<<20) + 1;
int g[20][20];	// 牛牛i喜欢的棚子j会有g[i][j] = 1 不喜欢的为0
int dp[maxx];
int cnt[maxx];


void init()
{
	for(int i = 0;i < maxx;i++){
		for(int j = 0;j < 20;j++){
			if((i & (1<<j)) == (1<<j))cnt[i]++;
		}
	}
}

int main()
{
	int N,M;
	cin>>N>>M;
	init();
	memset(g,0,sizeof(g));
	for(int i = 0 ;i < N;i++){
		int P;
		cin>>P;
		while(P--){
			int temp;
			scanf("%d",&temp);
			temp--;
			g[i][temp] = 1;
		}
	}
	dp[0] = 1;	// 与实际情况不相符合，主要是为了计算
	int ans = 0;
	for(int s = 1;s < (1<<M); s++){
		if(cnt[s] > N)continue;
		dp[s] = 0;
		for(int i = 0;i < M;i++){
			if((s & (1<<i)) !=0 && g[cnt[s] - 1][i] == 1)
				dp[s] += dp[s - (1<<i)];
		}
		if(cnt[s] == N)ans += dp[s];
	}
	cout<<ans<<endl;
	return 0;
}


