#include <iostream>
#include<math.h>
#include<algorithm>
using namespace std;

const int maxx = 900 + 5;
int level[maxx];
int main() {
  int n, m,Case = 1;
  long long vol;
  while (scanf("%d%d", &n, &m) == 2 && n != 0) {
    printf("Region %d\n",Case++);
    for (int i = 0; i < n; i++) 
      for (int j = 0; j < m; j++) 
        scanf("%d",&level[i * m + j]);
    scanf("%lld",&vol);
    sort(level, level + (n * m));
    if(vol == 0){
    printf("Water level is %0.2lf meters.\n"
          "0.00 percent of the region is under water.\n",(double)level[0]);
      continue;
    }
    //printf("min -- %d\n",level[0]);
    level[n * m] = level[n * m - 1] + ((vol + 100 * (n * m) - 1 )/ (100 * (n * m)));  // 上界
    int posi = 1;
    long long sum = 0;
    while(posi <= (n * m)){
      if(level[posi] == level[posi - 1]){
        sum += (level[posi] - level[0]) * 100;
        posi++;
        continue;
      }
      if((level[posi] - level[0] ) * posi * 100 == vol + sum){

        printf("Water level is %.2lf meters.\n",(double)level[posi]);
        printf("%.2lf percent of the region is under water.\n",(double)(posi * 100) / (double)(n * m) );
        break;
      }
      double h = (double)(vol + sum) / ((double)posi * 100) + (double)level[0];
      if(h < (double)level[posi]){
        printf("Water level is %.2lf meters.\n",h);
        printf("%.2lf percent of the region is under water.\n",(double)(posi * 100) / (double)(n * m) );
        break;
      }
      sum += (level[posi] - level[0]) * 100;
      posi++;
    }
    cout<<endl;
  }
  return 0;
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstdio>
using namespace std;
int main()
{
    vector<int> h;
    int n, m, i, j, x;
    double v, k, hi;
    int cnt = 0;
    while (~scanf("%d%d", &n, &m) && n && m)
    {
        h.clear();
        n *= m;
        for (i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            h.push_back(x);
        }
        h.push_back(INT_MAX);
        sort(h.begin(), h.end());//高度排序
        scanf("%lf", &v);
        v /= 100;//除以底面积，v为最大单位面积高度
        for (i = 1; i <= n; ++i)//表示0-i-1装下洪水的高度
        {
            v += h[i-1];
            hi = v/i;
            if (hi < h[i])//如果小于下一个格子的高度则为答案
            {
                k = i;
                break;
            }
        }
        printf("Region %d\nWater level is %.2lf meters.\n", ++cnt, hi);
        printf("%.2lf percent of the region is under water.\n\n", k*100/n);
    }
    return 0;
}
*/
