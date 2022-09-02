#include<iostream>
#define LL long long
using namespace std;

const int maxx = (int)1e6+10;
LL dp[maxx];   // 表示最后一个位置为仓库时的值
LL x[maxx],p[maxx],c[maxx];
LL s1[maxx], s2[maxx];
int stack_point[maxx];
LL f(int i){
    return dp[i] + s2[i];
}
LL g(int i){
    return x[i]*s1[i-1] - s2[i-1];
    // return x[i] * s1[i] -s2[i];
}
LL val(int i,int j){
    return f(j) + g(i) - x[i] * s1[j];  //k(i) == x[i], h(j) == s1[j]
}
double spolt(int i,int j)
{
    if(s1[i] == s1[j])return 1e18;              // 血的教训！！！,注意这里有一个除法，浮点数除法中除0并不会报错，但是除法结果会是inf,inf与inf的比较永远返回值为0,inf指的是正无穷

    return 1.0 * ((double)f(i) - f(j))/(s1[i] - s1[j]);
}

int find_val(int val, int r)
{
    int l = 0,mid;
    while(l < r){
        int mid = (l + r) / 2;
        if( spolt(stack_point[mid], stack_point[mid + 1]) < val)l = mid+1;
        else r = mid;
    }
    return r;
}


int main()
{
    int n;
    cin>>n;
    s1[0] = 0;
    s2[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&x[i],&p[i],&c[i]);
        s1[i] = p[i] + s1[i-1];
        s2[i] = p[i] * x[i] + s2[i-1];
    }
    dp[1] = c[1];
    int top = 1;
    stack_point[top] = 1;
    int j = 0;
    for(int i = 2;i<=n;i++){
        j = find_val(x[i], top);        // 寻找最优点
        dp[i] = c[i] + val(i,stack_point[j]);
        // dp[i] = c[i] + dp[stack_point[j]] +(x[i] * (s1[i-1] - s1[stack_point[j]]) - s2[i-1] + s2[stack_point[j]]);
        while(top - j +1 >=2 && spolt(stack_point[top-1],stack_point[top]) > spolt(stack_point[top], i))top--;     // 进入循环的时候保证里面有两个元素,还有就是j之后的元素都一定不是之后的最小值。
        stack_point[++top] = i;   // 刚加入的点
    }
    int max_n = n;    
    for(int i = n;i>=1;i--){
        if(p[i] != 0){
            max_n = i;
            break;
        }
    }
    LL ans = dp[n];
    for(int i = max_n;i<=n;i++) ans = min(ans, dp[i]);
    printf("%lld\n",ans);
    return 0;
}
