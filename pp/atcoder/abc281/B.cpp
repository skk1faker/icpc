#include<iostream>
#include<cstring>
using namespace std;
int main(){
  char s[100];
  scanf("%s",s);
  if(strlen(s) != 8){
    cout<<"No"<<endl;
    return 0;
  }
  if(!('A' <= s[0] && s[0] <= 'Z')){
    cout<<"No"<<endl;
    return 0;
  }
    if(!('0' < s[1] && s[1] <= '9')){
      cout<<"No"<<endl;
      return 0;
    }
  for(int i = 2;i < 7;i++){
    if(!('0' <= s[i] && s[i] <= '9')){
      cout<<"No"<<endl;
      return 0;
    }
  }
  if(!('A' <= s[7] && s[7] <= 'Z')){
    cout<<"No"<<endl;
    return 0;
  }
  cout<<"Yes"<<endl;
  return 0;
}
