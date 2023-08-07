树状数组与二分相结合可以进行第k大值的查找。

题意 ： 

初始序列为n个0， 然后每次修改其中的一个值为x,(x <= $10 ^9$),共($10 ^ 5$)个操作，求数列的前k大的和。https://atcoder.jp/contests/abc306/tasks/abc306_e

思路：因为修改次数比较少，所以先离散化，然后对离散话之后的值使用树状数组记录其数量，和未离散话之前数值的和。

细节如下：



```python
/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    E.cpp
*   username:     skt1faker
*   create time:  20:52  2023.06.17
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

// 离散化 + 树状数组
//
const int maxx = (int)5e5 + 10;
map<int, int>mapp;
int res_mapp[maxx];
struct Tree{
  long long val;
  int num;
}tree[maxx];  


int lowbit(int posi){
  return posi & (-posi);
}
void change(int val,int mode){
  int posi = mapp[val];
  do{
    tree[posi].val += mode * val;
    tree[posi].num += mode;
    posi += lowbit(posi);
  }while(posi < maxx);
}
int check(int posi, long long &sum){
  sum = 0;
  int num = 0;
  do{
    sum += tree[posi].val;
    num += tree[posi].num;
    posi -= lowbit(posi);
  }while(posi > 0);
  return num;
}

int val[maxx];
struct OPer{
  int val,id;
}op[maxx];

int main()
{
  int n,k,q;
  cin>>n>>k>>q;
  val[0] = 0;
  for(int i = 0;i < q;i++){
    scanf("%d%d",&op[i].id,&op[i].val);
    val[i + 1] = op[i].val;
  }
  sort(val , val + q + 1);
  int cnt = 1;
  mapp[val[0]] = cnt;   // 树状数组第一个值为1
  res_mapp[cnt] = val[0];
  for(int i = 1;i <= q;i++){
    if(val[i] != val[i - 1]){
      mapp[val[i]] = ++cnt;
      res_mapp[cnt] =val[i];
    }
  }
  int check_posi = n - k;   // 取反
  long long all_sum = 0;
  for(int i = 0;i < n;i++){
    change(0,1);
  }
  memset(val,0,sizeof(val));
  for(int i = 0;i < q;i++){
    change(val[op[i].id], -1);
    change(op[i].val, 1);
    all_sum = all_sum + op[i].val - val[op[i].id];
    int l = 1, r = cnt;
    int ret;
    int last_val;
    long long ans;
    while(l < r){
      int mid = (l + r) / 2;
      ret = check(mid, ans);  // 寻找下界
      if(ret < check_posi){
        l = mid + 1;
      }
      else {
        r = mid;
      }
    }
    //cout<<ans<<endl;
    if(ret > check_posi){
      ret = check(l - 1,ans);
    }
    ans += (check_posi  - ret) * res_mapp[l];
    //cout<< check_posi <<' '<< ret <<' '<< res_mapp[l] <<endl;
    //cout<< "ans = " << all_sum - ans <<endl;
    cout<<all_sum - ans <<endl;
    val[op[i].id] = op[i].val ;
  }

}

```

