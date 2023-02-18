#include<iostream>
using namespace std;
const int maxx = 100000 + 5 * 9;
int ans[maxx];
int generate(int a)
{
  int b = a;
  while(b){
    a += (b%10);
    b /= 10;
  }
  return a;
}

void init(){
  for(int i = 100000;i >= 0;i--){
    ans[generate(i)] = i;
  }
}

int main()
{
  int n;
  init();
  cin>>n;
  for(int i =0 ;i< n;i++){
    int temp;
    scanf("%d",&temp);
    cout<<ans[temp]<<endl;
  }
  return 0;
}
