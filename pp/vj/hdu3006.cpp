#include<iostream>
#include<cstring>
#define ll long long 
using namespace std;
const int maxx = (1<<14) + 10;
//给你n个集合。集合中的所有正整数不小于1且不大于m。如果用这些集合组合新集合，你可以获得多少不同的新集合。给定的集合不能被打破。
int dp[maxx];
int set_num[105];
int main()
{
	int n,m,k;
	ll ans = 0;
	while(scanf("%d%d",&n,&m) == 2){
		ans = 0;
		memset(dp,0,sizeof(dp));
		for(int i = 0;i < n;i++){
			scanf("%d",&k);
			int set_val = 0;
			for(int j = 0; j < k;j++){
				int temp;
				scanf("%d",&temp);
				temp--;
				set_val = set_val | (1<<temp);
			}
			set_num[i] = set_val;
		}
		dp[0] = 1;
		for(int i = 0;i < n;i++){
			for(int set_val = 0;set_val < (1<<m);set_val++){
				if(dp[set_val] == 1){
					dp[set_val | set_num[i]] = 1;
				}
			}
		}
		for(int set_val = 1;set_val < (1<<m);set_val++){
			ans+=dp[set_val];
		}
		printf("%lld\n",ans);

	}
	return 0;
}
