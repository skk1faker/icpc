/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva10635.cpp
*   username:     skt1faker
*   create time:  21:14  2023.05.13
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

const int maxx = 250 * 250 + 1;
int dp[maxx];

int B[maxx];
int translate[maxx];


int bin_find(int val ,int ri){
  int l = 0,r = ri;
  while(l < r){
    int mid = (l + r) >> 1;
    if(dp[mid] < val){
      l = mid + 1;
    }
    else if(dp[mid] == val){  // 两个元素的时候应该如何选择
       r = mid;
      //l = mid;  会导致死循环， 如果是l = mid + 1则可能丢解。
    }
    else {
      r = mid;
    }
  }
  // 决定是upperbound和downbounder整实际上和if(dp[mid] == val)没有关系，是在两个相邻节点的时候val在两节点中间，这个时候算法如何取值是算法为upperbound 还是downbounder的区别。
  dp[l] = min(dp[l], val);
  return l;
}

int main()
{
  int T;
  cin>>T;
  int Case = 0;
  while(T--){
    memset(dp,0x3f3f3f3f,sizeof(dp));
    memset(translate,0x3f3f3f3f,sizeof(translate));
    int n,p,q;
    cin>>n>>p>>q;
    for(int i = 0;i <= p;i++){
      int temp;
      scanf("%d", &temp);
      translate[temp] = i;
    }
    for(int i = 0;i <= q;i++){
      int temp;
      scanf("%d",&temp);
      B[i] = translate[temp];
    }
    int ans = 0;
    dp[0] = -1;  // 第一个位置元素为0， 此时长素为0;
    for(int i = 0; i <= q;i++){
      ans = max(ans, bin_find(B[i], q + 1));
    }
    printf("Case %d: %d\n",++Case,ans);
  }
  return 0;
}
