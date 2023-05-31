/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    temp2.cpp
*   username:     skt1faker
*   create time:  08:31  2023.05.17
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
struct a
{
  int s1,s2;
  a(int s1,int s2):s1(s1),s2(s2){}
  bool operator < (const a & temp)const{
    return this->s1 < temp.s1;
  }
};

int main()
{
  set<a> t;
  t.insert(a(1,2));
  if(t.find(a(1,9))!=t.end())
    cout<<1<<endl;
  return 0;
}
