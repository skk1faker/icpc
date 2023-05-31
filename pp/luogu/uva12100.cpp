#include <bits/stdc++.h>
#include <queue>
using namespace std;

void solve() {
  //priority_queue<int, vector<int>, greater<int>> pq;
  priority_queue<int> pq;
  queue<pair<int, int>> q; // value is my;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    int x, y;
    scanf("%d", &x);
    if (i == m)
      y = 1;
    else
      y = 0;
    q.push(make_pair(x, y));
    pq.push(x);
  }
  int time_val = 0;
  while(!q.empty()){
    if(q.front().first == pq.top()){
      time_val++;
      if(q.front().second == 1){
        cout<<time_val<<endl;
        return ;
      }
      q.pop();
      pq.pop();
    }
    else {
      q.push(q.front());
      q.pop();
    }
  }
}

int main() {
  int T;
  cin>>T;
  while(T--){
    solve();
  }
  return 0;
}
