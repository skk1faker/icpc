#include<iostream>
#include<cstring>
using namespace std;
const int maxx = 101;
char temp[maxx];

bool compare(int st,int min_st){
  int length = strlen(temp);
  for(int i = 0;i < length;i++){
    if(temp[(i + st) % length] != temp[(i + min_st) % length])return temp[(i + min_st) % length] > temp[(i + st) % length];   // 如果st小就使用st这个串
  }
  return false;
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--){
    scanf("%s",temp);
    int min_st = 0;
    int length = strlen(temp);
    for(int st = 1;st < length;st++)
      if(compare(st,min_st))min_st = st;
    
    for(int i = 0;i < length;i++){
      printf("%c",temp[(i + min_st) % length]);
    }
    printf("\n");
  }
}
