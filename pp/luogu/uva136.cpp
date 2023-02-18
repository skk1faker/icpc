#include<bits/stdc++.h>

using namespace std;
int factor[3] = {2,3,5};
int main()
{
  priority_queue<long long,vector<long long >, greater<long long >>pq;
  set<long long>vis;
  long long val = 1;
    pq.push(val);
  vis.insert(val);
  for(int i = 1 ;i < 1500;i++){
    val = pq.top();
    pq.pop();
    for(int j = 0;j < 3;j++){
      if(vis.count(val * factor[j]) == 1)continue;
      vis.insert(val * factor[j]);
      pq.push(val * factor[j]);
    }

  }
  printf("The 1500'th ugly number is %lld.", pq.top());
  return 0;
}
