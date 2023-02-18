#include<iostream>
#include<cstring>
using namespace std;
int s[26],d[26];
int times[101];
int main()
{
  char source[101],destin[101];
  while(scanf("%s%s",destin,source) == 2){
    memset(s,0,sizeof(s));
    memset(d,0,sizeof(d));
    memset(times,0,sizeof(times));
    for(int i = 0;i < strlen(source);i++){
      s[source[i] - 'A']++;
      d[destin[i] - 'A']++;
    }
    for(int i = 0; i < 26;i++){
      if(s[i] > 0)times[s[i]]++;
      if(d[i] > 0)times[d[i]]--;
    }
    int flag = 0;
    for(int i = 1;i <= 100;i++){
      if(times[i] != 0){
        flag = 1;
      }
    }
    if(flag == 1){
      cout<<"NO"<<endl;
    }
    else {
      cout<<"YES"<<endl;
    }    
  }
  return 0;
}
