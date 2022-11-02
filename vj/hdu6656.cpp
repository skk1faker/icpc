# 注意long long 和 int 运算可能会出现问题 
#include<iostream>
#define ll long long 
using namespace std;


const int maxx = (int)5e5 + 10;
const ll mod = (int)1e9+7;
ll dp[maxx];	// dp[i]代表从1升级到i需要的金币数量(a/b ==> dp[i] = (a * b^-1) % mod)
// ll p[maxx];
ll p_reverse[maxx];
ll x[maxx];	// 降级
ll c[maxx];	// 花费

void gcd_extern(ll a,ll b,ll &x,ll &y){	// ax + by = gcd(a,b)
	if(a == b || a == 0 || b == 0){
		if(b == 0){
			x = 1;
			y = 0;
		}
		else if(a == 0){
			x = 0;
			y = 1;
		}
		else {
			x = 1;
			y = 0;
		}
		return ;
	}
	if(a > b){
		gcd_extern(a%b,b,x,y);
		y = (y - a/b * x);
		return ;
	}
	else {
		gcd_extern(a,b%a,x,y);
		x = (x - b/a * y);
		return ;
	}
	return ;
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i = 1;i <= n;++i){
			ll r,s,a,b;
			scanf("%lld%lld%lld%lld",&r,&s,&x[i],&c[i]);
			gcd_extern(r,mod,a,b);	// a r + mod b = 1; r是a关于mod的逆元
			while(a < 0)a += mod;
			p_reverse[i] = (a * s) % mod;
			//gcd(p[i],mod,a,b);
			//p_reverse[i] = a % mod;
		}
		dp[1] = 0;
		for(int i = 2;i <= n + 1;i++){
			dp[i] = (dp[x[i - 1]] + ((dp[i - 1] + c[i - 1] - dp[x[i - 1]] + mod) * p_reverse[i - 1])% mod) % mod;
			while(dp[i] < 0)dp[i]+=mod;
			dp[i] %= mod;
		}
		for(int i = 0;i < m;i++){
			ll l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld\n",(dp[r] - dp[l] + mod)%mod);
		}
	}
	return 0;
}
