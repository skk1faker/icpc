/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva1153.cpp
*   username:     skt1faker
*   create time:  09:34  2023.05.28
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
const int maxx = (int)8e5 +10;
struct node{
  int dur,en;
  bool operator < (const node & t)const{
    return dur < t.dur;
  }
}p[maxx];

bool cmp(const node &t1,const node &t2){
  return (t1.en == t2.en) ? t1.dur > t2.dur: t1.en < t2.en;
}

int main()
{
  int T;
  cin>>T;
  while(T--){
    int n;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
      scanf("%d%d",&p[i].dur,&p[i].en);
    }
    sort(p,p+n,cmp);
    int cnt = 0;
    priority_queue<node>q;
    for(int i = 0;i < n;i++){
      if(cnt + p[i].dur <= p[i].en){
        cnt += p[i].dur;
        q.push(p[i]);
      }
      else if(!q.empty()){
        node f = q.top();
        if(p[i].dur < f.dur){
          q.pop();
          q.push(p[i]);
          cnt += p[i].dur;
          cnt -= f.dur;
        }
      }
    }
    cout<<q.size()<<endl;
    if(T)cout<<endl;
  }
}
