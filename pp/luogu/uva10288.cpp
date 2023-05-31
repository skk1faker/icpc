/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva10288.cpp
*   username:     skt1faker
*   create time:  06:04  2023.05.28
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
  if(a == 0){
    return b;
  }
  return gcd(b % a, a);
}

int main()
{
  long long n;
  while(scanf("%lld",&n) == 1){
    long long a[2],b[2];
    a[0] = 1;
    b[0] = 1;
    for(long long i = 2;i <= n;i++){
      a[1] = a[0] * (n - i + 1) + b[0] * n;
      b[1] = b[0] * (n - i + 1);
      a[0] = a[1];
      b[0] = b[1];
      long long temp = gcd(a[0], b[0]);
      a[0] /= temp;
      b[0] /= temp;
    }
    if(a[0] % b[0] == 0){
      cout<<a[0] / b[0]<<endl;
      continue;
    }
    long long temp = max(a[0] % b[0], b[0]);
    int line_length = 0;
    while(temp){
      line_length++;
      temp /= 10;
    }
    temp = a[0] / b[0];
    int space_length = 0;
    while(temp){
      space_length++;
      temp /= 10;
    }
    for(int i = 0;i<=space_length;i++)printf(" ");
    printf("%lld\n%lld ",a[0] % b[0], a[0] / b[0]);
    for(int i = 0;i<line_length;i++)printf("-");printf("\n");
    for(int i = 0;i<=space_length;i++)printf(" ");
    printf("%lld\n",b[0]);
  }
  return 0;
}
