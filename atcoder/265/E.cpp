#include<bits/stdc++.h>

using namespace std;
const long long mod = 998244353;
typedef long long ll;
int main()
{
    set<pair<ll,ll> > P;     // 禁止点
    map<pair<ll,ll>,ll>dp;     // 最终答案
    ll move_method[3][2];
    int n,m;
    cin>>n>>m;
    for(int i = 0;i < 3;i++)scanf("%lld%lld", &move_method[i][0],&move_method[i][1]);
    for(int i = 0;i < m;i++){
        ll x,y;
        scanf("%lld%lld",&x,&y);
        P.insert(make_pair(x,y));
    }
    dp[make_pair(0,0)] = (ll)1;// 开始的状态应该是1
    for(int i = 1;i <= n;i++){
        map<pair<ll,ll>,ll>dp_temp;     // 临时计算
        for(auto it :dp){
            for(int j = 0;j< 3;j++){
                long long new_x = it.first.first + move_method[j][0];
                long long new_y = it.first.second + move_method[j][1];
                if(P.find(make_pair(new_x,new_y)) == P.end()){
                    // cout<<new_x<<' '<<new_y<<' '<<endl;
                    if(dp_temp.count(make_pair(new_x,new_y)) == 0){
                        dp_temp[make_pair(new_x,new_y)] = it.second;
                        // dp_temp[make_pair(new_x,new_y)] %= mod;
                    }
                    else {
                        dp_temp[make_pair(new_x,new_y)] += it.second;
                        dp_temp[make_pair(new_x,new_y)] %= mod;
                    }
                }
            }
        }
        swap(dp,dp_temp);
    }
    long long  ans = 0;
    for(auto it : dp){

        ans += it.second;
        ans %= mod;
    }
    cout<<ans<<endl;
    return 0;
}