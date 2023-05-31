/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    c.cpp
*   username:     skt1faker
*   create time:  10:17  2023.05.14
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
vector<int> fun(int n,int k){
  int ans[51];
  memset(ans ,0,sizeof(ans));
  int round = 1;
  int posi = 0;
  while(ans[posi] == 0){
    ans[posi] = 1;
    posi = (posi + round * k) % n;
    round++;
  }
  vector<int>temp_ans;
  for(int i =0 ;i < n;i++){
    if(ans[i] == 0){
      temp_ans.push_back(i + 1);
    }
  }
  return temp_ans;
}
int main()
{
  vector<int> a = fun(4,4);
  for(int b : a){
    cout<<b<<endl;
  }
}
