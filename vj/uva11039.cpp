#include<iostream>
#include<algorithm>
using namespace std;

const int max_ele = 500000 +1;
struct Val{
    int x;
    int sign;
    bool operator < (const Val & temp){
        return x < temp.x;
    }
};
struct Val val[max_ele];


int main()
{
    int p;
    cin>>p;
    while(p--){
        int n;
        cin>>n;
        for(int i = 0;i < n;i++){
            scanf("%d",&val[i].x);
            val[i].sign = val[i].x / abs(val[i].x);
            val[i].x = abs(val[i].x);
        }
        sort(val,val+n);
        int ans = 0;
        if(n > 0) ans = 1;
        for(int i = 1;i < n;i++){
            if(val[i].sign != val[i - 1].sign)ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}