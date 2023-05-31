#include<bits/stdc++.h>

using namespace std;
int val_cal(int posi)
{
  return (posi / 2 ) *( posi % 2 == 1 ? -1 : 1);
}

int main()
{
  map<int,set<int>> mp;// next_val length
  int n;
  cin>>n;
  int ans = 1;
  for(int i = 0;i< n;i++){
    int val;
    scanf("%d", &val);
    mp[val + 1].insert(1);
    if(mp.count(val)){
      for(set<int>::iterator iter = mp[val].begin();iter != mp[val].end();iter++){
        int length = *iter;
        int add = val_cal(length + 2) - val_cal(length + 1);
        mp[val + add].insert(length + 1);
        ans = max(ans, length + 1);
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}
