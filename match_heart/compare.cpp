#include<iostream>
#include<vector>
using namespace std;

vector<string>input;
int main()
{
  //char temp[100];
  //while(scanf("%s",&temp) == 1){
  string temp;
  while(cin>>temp){
    input.push_back(temp);
  }
  int n = input.size() / 2;
  for(int i = 0;i < n;i++){
    if(input[i] != input[n + i]){
      printf("1");
      return 0;
    }
  }
  printf("0");
  return 0;
}
