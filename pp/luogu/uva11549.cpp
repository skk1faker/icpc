/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva11549.cpp
*   username:     skt1faker
*   create time:  06:42  2023.05.24
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
long long  mod = 0;
long long fun(long long  val)
{
  val = val * val;
  while(val >= mod)
    val /= 10;
  return val;
}

int main()
{
  int t;
  cin>>t;
  while(t--){
    long long n,k;
    scanf("%lld%lld",&n,&k);
    mod = 1;
    for(int i = 0;i < n;i++)mod *= 10;
    long long k1 = k,k2 = fun(k),ans = max(k1,k2);;
    while(k1 != k2){
      k1 = fun(k1);
      k2 = fun(k2);
      ans = max(k2, ans);
      k2 = fun(k2);
      ans = max(k2, ans);
    }
    cout<<ans<<endl;
  }
  return 0;
}
