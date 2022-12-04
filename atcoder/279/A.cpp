#include<iostream>
#include<string>
using namespace std;
int main()
{
  string a;
  cin>>a;
  int ans = 0;
  for(int i = 0;i < a.length();i++){
    ans += (a[i] == 'v' ? 1: 2);
  }
  cout<<ans<<endl;
  return 0;
}
