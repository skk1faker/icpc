#include<iostream>
using namespace std;
int gcd(int a,int b)  // a > b
{
  if(b == 0)return a;
  return gcd(b, a % b);
}
const int maxx = (int)1e3 + 10;
int main()
{
  int n;
  int num[maxx];
  scanf("%d",&n);
  int d;
  for(int i = 0;i < n;i++){
    scanf("%d",&num[i]);
    if(i == 0) d = num[i];
    else d = gcd(num[i], d);
  }
  int ans=0;
  for(int i = 0;i < n;i++){
    num[i] /= d;
    while(num[i] % 2 == 0){
      num[i] /= 2;
      ans++;
    }
    while(num[i] % 3 == 0){
      num[i] /= 3;
      ans++;
    }
    if(num[i] != 1){
      cout<<-1<<endl;
      return 0;
    }
  }
  cout<<ans<<endl;
  return 0;
}




/*
#include<iostream>
#include<cstring>
using namespace std;
const int maxx = 1e3 + 10;
int num_split[3][maxx];
int main(){
  int n;
  memset(num_split,0,sizeof(num_split));
  scanf("%d",&n);
  for(int i = 0 ;i < n;i++){
    scanf("%d",&num_split[0][i]);
    while(num_split[0][i] % 2 == 0 ){
      num_split[1][i]++;
      num_split[0][i] /= 2;
    }
    while(num_split[0][i] % 3 == 0 ){
      num_split[2][i]++;
      num_split[0][i] /= 3;
    }
    // time == log(num_split[0][i]) * n
  }
  int ans = 0;
  int min_num[2] = {(int)1e9,(int)1e9};
  for(int i = 0;i < n;i++){
    if(i + 1 < n && num_split[0][i] != num_split[0][i + 1]){
      cout<<-1<<endl;
      return 0;
    }
    min_num[0] = min(min_num[0], num_split[1][i]);
    min_num[1] = min(min_num[1], num_split[2][i]);
    ans += num_split[1][i];
    ans += num_split[2][i];
  }
  ans -= min_num[0] * n + min_num[1] * n;
  cout <<ans<<endl;
  return 0;
}
*/
