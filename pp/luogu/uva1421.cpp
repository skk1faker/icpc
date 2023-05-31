/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*
*   filename：    uva1421.cpp
*   username:     skt1faker
*   create time:  10:35  2023.05.27
    email:        skk1faker@163.com
*   descripe:
*
================================================================*/
#include <bits/stdc++.h>
using namespace std;
int n,T;
double W;
const int maxx = (int)5e3 + 10;
const double eps = 1e-6;
const double pi = 4 * atan(1);
struct Target
{
  double x[2],y;
  bool operator <  (const Target &t) const {
    return y < t.y;
  }
}tar[maxx];

double fi(double x,double y,double x1,double y1){
  if(fabs(x - x1) < eps){
    return pi / 2;
  }
  double ans = atan((y - y1) / (x - x1));
  if(ans < 0)ans += pi;
  return ans;
}
void cal_range(double mid, int posi, double ans[])
{
  ans[0] = fi(mid,0, tar[posi].x[0],tar[posi].y);
  ans[1] = fi(mid,0, tar[posi].x[1],tar[posi].y);
  if(ans[0] > ans[1])swap(ans[0], ans[1]);
  
}

int check()
{

  double l = 0,r = W;
  while(fabs(l - r) > eps){
    double mid = (l + r) / 2;
    double  ans[2] = {0,pi};
    int flag = 0;
    //cout<<endl;
    for(int i = 0;i < n;i++){
      double temp_ans[2];
      cal_range(mid,i,temp_ans);
      //cout<<ans[0] <<' '<<ans[1]<<' '<<mid<<endl;
      if(temp_ans[1] < ans[0] - eps){
        flag = 1;
        r = mid;
        break;
      }
      if(temp_ans[0] > ans[1] + eps){
        flag = 1;
        l = mid;
        break;
      }
      ans[0] = max(ans[0], temp_ans[0]);
      ans[1] = min(ans[1], temp_ans[1]);
    }
    if(flag == 0)return 1;
  }
  return 0;
}

int main()
{
  cin>>T;
  while(T--){
    scanf("%lf%d",&W,&n);
    int min_posi = 0;
    for(int i =0;i < n;i++){
      scanf("%lf%lf%lf",&tar[i].y,&tar[i].x[0], &tar[i].x[1]);
    }
    sort(tar,tar+n);

    if(check())cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
  }
}




/*
const int maxx = (int)5e3 + 10;
const double eps = 1e-6;
const double pi = 4 * atan(1);
struct length {
  double x[2], y;
} tar[maxx];
int T, W, n;

double fi(double x, double y, double x1, double y1) {
  if (fabs(x - x1) < eps) {
    return pi / 2 ;
  }
  double ans = atan((y1 - y) / (x1 - x));
  if (ans < 0)
    ans += pi;
  return ans;
}

void calcul(double x, double y, int posi, double *ans) {
  for (int i = 0; i < 2; i++)
    ans[i] = fi(x, y, tar[posi].x[i], tar[posi].y);
  if (ans[0] > ans[1]) {
    swap(ans[0], ans[1]);
  }
}

bool check(double x, double y, int posi_now) {
  double ans_[2];
  calcul(x, y, n, ans_);
  for (int i = 0; i < n; i++) {
    if (i == posi_now)
      continue;
    double fi_[2];
    calcul(x, y, i, fi_);
    ans_[0] = max(ans_[0], fi_[0]);
    ans_[1] = min(ans_[1], fi_[1]);
    if (ans_[0] > ans_[1] + eps)
      return false;
    //if(fabs(ans_[0] - ans_[1]) < eps)return false;
  }
  return true;
}

int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &W, &n);
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf", &tar[i].y, &tar[i].x[0], &tar[i].x[1]);
    }
    tar[n].y = 0;
    tar[n].x[0] = 0;
    tar[n].x[1] = W;
    int flag = 0;
    for (int i = 0; i < n && flag == 0; i++) {
      for (int j = 0; j < 2; j++) {
        if (check(tar[i].x[j], tar[i].y, i)) {
          flag = 1;
          break;
        }
      }
    }
    if (flag) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
*/
