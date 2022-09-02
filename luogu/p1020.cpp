// 题解https://www.luogu.com.cn/problem/solution/P1020

// #include<bits/stdc++.h>
#include<iostream>

using namespace std;

const int maxx = 2000 + 5;
int shell[maxx];
int dp[maxx];   // 表示第k套拦截系统的最小值

int find(int k,int val)     // 假设我们现在有k套系统。
{
    int l = 0, r = k - 1;
    while(l<r){     // l == r break; l和r中恰好有val的上限
        int mid = (l + r)>>1;
        if(dp[mid] < val){
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }   // dp[r] >= val
    if(dp[r] < val) r = r + 1;     // 添加下一个系统
    return r;
}

int main()
{
    int n;
    int ans;
    while(scanf("%d",&n) == 1){
        for(int i=0;i<n;i++)scanf("%d",&shell[i]);
        if(n == 0){
            cout<<0<<endl;
            continue;
        }
        ans = 1;
        dp[0] = shell[0];
        for(int i = 1; i < n; i++){
            int posi = find(ans, shell[i]);
            if(posi == ans)ans++;
            dp[posi] = shell[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}


