#include<algorithm>
#include<iostream>
using namespace std;

const int maxx = (int)1e6+10;

class road{
public:
  int a,b;
  bool operator < (const road & temp)const{
    return this->a < temp.a;
  }
}r[maxx];

long long tree[1005];

void init_tree()
{
  for(int i = 0;i < 1005;i++)tree[i] = 0;
}
long long check(int val){
  long long ans = 0;
  for(;val;val -= (val & (-val))){
    ans += tree[val];
  }
  return ans;
}
void add_val(int val){
  for(;val < 1005;val+=(val & (-val)))tree[val]++;
}

int main()
{
  int T;
  cin>>T;
  int Case = 1;
  while(T--){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    init_tree();
    for(int i = 0;i< K;i++){
      int temp[2];
      scanf("%d%d",&temp[0],&temp[1]);
      r[i].a = temp[0];
      r[i].b = temp[1];
    }
    sort(r,r+K);

    long long ans = 0;
    int st=0,en;
    int num = 0;
    for(int i = 0;i < K;i++){
      en = i;
      ans += num - check(r[i].b);

      if(i+1 < K && r[i].a != r[i+1].a){
        for(int j = st;j<=en;j++)add_val(r[j].b);
        num+= (en - st + 1);
        st = i + 1;
      }
    }
    printf("Test case %d: %lld\n",Case++,ans);
  }
  return 0;
}
