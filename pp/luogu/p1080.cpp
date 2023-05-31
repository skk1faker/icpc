/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    p1080.cpp
*   username:     skt1faker
*   create time:  22:46  2023.05.29
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

const int maxx = 1000;
const int max_bit = (int)1e4 + 10;

struct INT{
  static int MOD;
  long long val[max_bit];
  int length;
  void mul(int v){
    long long temp = 0, temp_ans = 0;
    for(int i = 0;i < length;i++){
      temp_ans = val[i] * v + temp;
      val[i] = temp_ans % MOD;
      temp = temp_ans / MOD;
    }
    while(temp){
      val[length] = temp % MOD;
      temp /= MOD;
      length++;
    }
  }
  void div(int v){
    long long temp = 0;
    for(int i = length - 1;i >= 0;i--){
      temp = temp * MOD + val[i];
      val[i] = temp / v;
      temp %= v;
    }
    temp = 0;
    for(int i = 0;i < length;i++){
      temp = val[i] + temp;
      val[i] = temp % MOD;
      temp /= MOD;
    }
    while(val[length - 1] == 0){
      length--;
    }
  }
  void output(){
    printf("%lld",val[length - 1]);
    for(int i = length - 2;i >= 0;i--){
      printf("%04lld",val[i]);
      //printf("%lld",val[i]);
    }
    printf("\n");
  }
  bool operator < (const INT & t)const {
    if(length != t.length)
      return length < t.length;
    for(int i = length - 1;i >= 0;i--){
      if(val[i] != t.val[i])
        return val[i] < t.val[i];
    }
    return false;
  }
};
int INT::MOD= (int)1e4;

struct people{
  int a,b;
  /*
  bool operator < (const people & p)const {
    if(b != p.b)
      return b < p.b;
    return a < p.a;
  }
  */
  bool operator < (const people & p)const {
    return a * b < p.a * p.b;
  }
}p[maxx];
int main()
{
  int n;
  scanf("%d",&n);
  for(int i = 0;i <= n;i++){
    scanf("%d%d",&p[i].a,&p[i].b);
  }
  sort(p + 1,p + n + 1);
  INT temp_ans,ans,temp_mul;
  temp_ans.length = 1;
  temp_ans.val[0] = 1;
  ans = temp_ans;
  for(int i = 1;i<= n;i++){
    temp_ans.mul(p[i - 1].a);
    temp_mul.length = temp_ans.length;
    for(int i =0;i < temp_ans.length;i++){
      temp_mul.val[i] = temp_ans.val[i];
    }
    temp_ans.div(p[i].b);
    ans = max(ans, temp_ans);
    temp_ans.length = temp_mul.length;
    for(int i =0;i < temp_ans.length;i++){
      temp_ans.val[i] = temp_mul.val[i];
    }
  }
  ans.output();
  //printf("%03d",11);
  return 0;
}
