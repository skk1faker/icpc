#include<bits/stdc++.h>
using namespace std;
int k,m,x;
int main()
{
  int T;
  cin>>T;
  while(T--){
    cin>>m>>x;
    k = m / x;
    cout<< ((m / k) - ((m + 1 + k)  / (k + 1))  + 1)<<endl;;
  }
  return 0;
}
