/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    d.cpp
*   username:     skt1faker
*   create time:  11:42  2023.05.14
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
int fa[51];
int findfa(int val){
  if(fa[val] == val)return val;
  return fa[val] = findfa(fa[val]);
}
void mergefa(int a,int b){
  a = findfa(a);
  b = findfa(b);
  if(a == b)return ;
  fa[a] = b;
  return ;
}
int countCompleteComponents(int n, vector<vector<int>>& edges) {
   for(int i = 1;i <= n;i++)fa[i] = i;
  int length_edge = edges.size();
  for(int i = 0;i < length_edge;i++){
    mergefa(edges[i][0],edges[i][1]);
  }
   int edge_num[51];
   int point_num[51];
  memset(edge_num,0,sizeof(edge_num));
  memset(point_num,0,sizeof(point_num));
  for(int i = 1;i <= n;i++)point_num[findfa(i)]++;
  for(int i = 0;i < length_edge;i++){
    edge_num[findfa(edges[i][0])]++;
  }
  int ans = 0;
  for(int i = 0;i <= n;i++){
    if(point_num[i] != 0){
      if(point_num[i] * (point_num[i] - 1) == edge_num[i] * 2){
        ans++;
      }
    }
  }
  return ans;
}
