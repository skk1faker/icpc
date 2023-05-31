#include<iostream>
using namespace std;
int main()
{
  int n = 200000;
  cout<<n<<endl;
  for(int i = 0;i < n;i++)printf("0 ");
  cout<<endl;
  for(int i = 2;i <= n;i++){
    printf("%d %d\n",i - 1, i);
  }
  return 0;
}
