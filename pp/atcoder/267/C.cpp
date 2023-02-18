#include<iostream>
#define ll long long 
const int N = (int)2e5+10;
ll a[N];
ll sum[N];

using namespace std;
int main()
{

    int n,m;
    cin>>n>>m;
    sum[0] = 0;
    ll ans = 0;
    for(int i = 1;i <= n;i++){
        scanf("%lld",&a[i]);
        if(i <= m)ans += i * a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    // cout<<ans<<endl;
    ll temp = ans;
    for(int i = 2;i <= n - m + 1;i++){
        temp = temp - (sum[i + m - 2] - sum[i - 2]) + m * a[i - 1 + m];
        // cout<<sum[i+m - 2]<<' '<<sum[i-2]<<endl;
        // cout<<temp<<endl;
        ans = max(ans, temp);
    }
    cout<<ans<<endl;
    return 0;
}