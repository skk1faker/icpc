/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva10328.cpp
*   username:     skt1faker
*   create time:  08:04  2023.05.26
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/

#include <bits/stdc++.h>
#define  DEBUG 0
using namespace std;

const int maxx = (int)1e4 + 10;
const double eps= -1e-10;


struct Range {
  double x[2];
  bool operator<(const Range &temp) const {
    return x[0] < temp.x[0];
  }
} ranges[maxx];

int main() {
  int Case = 1;
  double now_end = 0, next_end = 0;
  int n, l, w;
  int ans = 0;
  while (scanf("%d%d%d", &n, &l, &w) == 3 && n != 0) {
    bool check = (Case == 592 || Case == 592) && DEBUG;
    if(check){
      printf("%d %d %d\n",n,l,w);
    }
    Case++;
    ans = 1;
    now_end = 0,next_end = 0;
    for (int i = 0; i < n; i++) {
      int p, r;
      scanf("%d%d", &p, &r);
      if(check)printf("%d %d\n",p,r);
      double length = 0;
      if(r * r - w * w * 0.25 >0 ){
        length = sqrt(r * r - (double)w * w * 0.25);
        ranges[i].x[0] = p - length;
        ranges[i].x[1] = p + length;
      }
      else {
        ranges[i].x[0] = p ;
        ranges[i].x[1] = p ;
      }
    }
    sort(ranges, ranges + n);
    /*
    for(int i = 0;i < n;i++)
      printf("%lf %lf\n",ranges[i].x[0],ranges[i].x[1]);
    cout<<endl;
    */
    for(int i = 0;i < n;i++){
      if(ranges[i].x[0] > now_end ){
        now_end = next_end;
        ans++;  // 即将选择下一个
      }
      if(ranges[i].x[0] > now_end){
        ans = -1;
        break;
      }
      next_end = max(next_end, ranges[i].x[1]);
      if(next_end >=l ){
        break;
      }
    }
    if(next_end < l)ans = -1;
    if(!DEBUG)cout<<ans<<endl;
  }
  return 0;
}
