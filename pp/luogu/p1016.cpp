/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    p1016.cpp
*   username:     skt1faker
*   create time:  20:26  2023.05.28
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
int n;
double p[8],dist[8];
const double eps = 1e-6;
int next_small_posi[8];
double length,tolance =  0,max_tolance,power;

int main()
{
  while(scanf("%lf%lf%lf%lf%d",&length,&max_tolance,&power,&p[0],&n) == 5){
    dist[0] = 0;
    dist[n  + 1] = length;
    p[n + 1] = 0;
    for(int i = 1;i <= n;i++)
      scanf("%lf%lf",&dist[i] ,&p[i]);
    for(int i =0;i <= n + 1;i++){
      next_small_posi[i] = -1;
      for(int j = i + 1;j <= n + 1;j++){
        if(p[i] > p[j]){
          next_small_posi[i] = j;
          break;
        }
      }
    }
    double ans = 0;
    tolance = 0;
    for(int i = 0;i <= n +1;i++){
      // 假设到达本点为最佳加油方案，则到达本点之后，加油方案应为：
      // 0.当前点为全局最小
      // 1 如果加满油箱无法到达下一个最小，直接加到最满，因为不加满中途还会加油，在中途加油不如在当前位置加，这种是一种置换反映。
      // 2. 否则加到到达下一点刚好的油量
      if(i!=0)tolance -= (dist[i] - dist[i - 1]) /power;
      if(tolance < 0 - eps){
        cout<<"No Solution"<<endl;
        break;
      }
      if(i == n + 1)printf("%.2lf\n",(int)((ans + 0.005) *100) * 1.0 / 100);

      if(next_small_posi[i] == -1) {
        ans += (max_tolance - tolance) * p[i];
        tolance = max_tolance;
      }
      else {
        double need_oil = (dist[next_small_posi[i]] - dist[i]) / power;
        if(need_oil < tolance)
          continue;
        need_oil = min(need_oil, max_tolance);
        ans += (need_oil - tolance) *p[i];
        tolance = need_oil;
      }
    }
    
  }
  return 0;
}
