#include<iostream>
using namespace std;
typedef long long ll;
const long long mod =  998244353;

int main()
{
    // cout<<(-16)%10<<endl;
    long long N;
    cin>>N;
    ll ans = N % mod;
    if(ans / abs(ans) == -1){
        cout<<(mod + ans)<<endl;
    }
    else {
        cout<<ans<<endl;
    }
    return 0;
}