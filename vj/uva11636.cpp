#include<iostream>
using namespace std;
int main(){
    int Case = 1;
    int n;
    while(scanf("%d",&n) == 1&&n > 0){
        int ans = 0;
        if((n&(n-1)) == 0)ans--;    //n&(n-1)判断n是不是2的幂次
        // cout<<(n&n-1)<<' '<<ans<<endl;
        while(n){
            n/=2;   // 计算他的执行次数和n的二进制位数关系
            ans++;  // 他的执行次数和上面哪句话是一样的，不过可以通过条件判断来控制他的执行次数
        }
        printf("Case %d: %d\n",Case++,ans);

    }
}
    