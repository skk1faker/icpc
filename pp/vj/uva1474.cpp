
/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva1474.cpp
*   username:     skt1faker
*   create time:  07:35  2023.05.23
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/
/*
#include<bits/stdc++.h>
using namespace std;
const int maxx = 4005;
int dp[2][maxx];
int mapp[maxx];
int people[maxx];
int ans[2][maxx];

int main()
{
  int n,m;
  cin>>n;
  for(int i = 1;i <= n;i++){
    scanf("%d",&people[i]);
  }
  cin>>m;
  for(int i = 1;i <= m;i++){
    scanf("%d",&mapp[i]);
  }
  memset(dp[0],0x3f3f3f3f,sizeof(dp[0]));
  dp[0][0] = 0;
  sort(mapp + 1,mapp + m + 1);
  sort(people +1 ,people + n +1);
  for(int i = 1;i <= m;i++){
    memset(dp[i % 2],0x3f3f3f3f,sizeof(dp[0]));
    for(int j = i;j <= n;j++){
      int length = abs(people[j] - mapp[i]);
      dp[i % 2][j] = min(dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1]) + length;
    }
  }

  cout<<dp[m % 2][n]<<endl;
  return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
const int maxx = 4005;
int dp[2][maxx];
int mapp[maxx];
int people[maxx];
int ans[2][maxx];

int dist(int val, int n) {
  int l = 1, r = n;
  while (l < r) {
    int mid = (l + r) >> 1;
    if (mapp[mid] >= val) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  if (l - 1 >= 1) {
    if (abs(val - mapp[l]) > abs(val - mapp[l - 1]))
      return l - 1;
    else
      return l;
  } else {
    return l;
  }
}

struct Point {
  int x, y;
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  bool operator < (const Point &p)const{
    if(this->x != p.x)
      return this->x < p.x;
    else {
      return this->y > p.y;
    }
  
  }
}mapp_point[maxx],people_point[maxx];

int main() {
  int n, m;
  while (cin >> n) {
    for (int i = 1; i <= n; i++) {
      scanf("%d", &people[i]);
      people_point[i].x = people[i];
      people_point[i].y = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
      scanf("%d", &mapp[i]);
      mapp_point[i].x = mapp[i];
      mapp_point[i].y = i;
    }
    memset(dp[0], 0x3f3f3f3f, sizeof(dp[0]));
    dp[0][0] = 0;
    sort(mapp + 1, mapp + m + 1);
    sort(mapp_point + 1, mapp_point + m + 1);
    sort(people + 1, people + n + 1);
    sort(people_point + 1, people_point + n + 1);
    for (int i = 1; i <= m; i++) {
      int last_change = 0;
      for (int j = i; j <= n; j++) {
        int posi_i = dist(people[j], i);
        if (i <= (j - 1)) {
          dp[i % 2][j] =
              min(dp[(i - 1) % 2][(j - 1)] + abs(mapp[i] - people[j]),
                  dp[i % 2][(j - 1)] + abs(mapp[posi_i] - people[j]));
          if (dp[(i - 1) % 2][(j - 1)] + abs(mapp[i] - people[j]) >
              dp[i % 2][(j - 1)] + abs(people[j] - mapp[posi_i])) {
            ans[i % 2][j] = posi_i;
          } else {
            // memcpy(ans[i],ans[i - 1],sizeof(ans[i]));
            last_change = j; // 需要复制的数量（0 -- (j - 1)）需要复制
            ans[i % 2][j] = i;
          }
        } else {
          dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + abs(mapp[i] - people[j]);
          last_change = j; // 需要复制的数量（0 -- (j - 1)）需要复制
          ans[i % 2][j] = i;
        }
      }
      // cout<<"last_change: "<<last_change<<endl;
      for (int tt = 1; tt < last_change; tt++)
        ans[i % 2][tt] = ans[(i + 1) % 2][tt];
      // memcpy(ans[i % 2],ans[(i + 1) % 2],(last_change) * sizeof(ans[i %
      // 2][0]));
    }
    cout << dp[m % 2][n] << endl;
    for(int i = 1;i <= n;i++){
      ans[(m + 1) % 2][people_point[i].y] = ans[m % 2][i];
    }
    for (int i = 1; i <= n; i++){
      if(i != 1)cout<<' ';
      cout << mapp_point[ans[(m + 1) % 2][i]].y;
    }
    cout << endl;
  }
  return 0;
}
