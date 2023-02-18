#include<iostream>
using namespace std;
char name[5] = "ATCG";
char input[51][1001];
int input_number[4];
int get_number(char a)
{
  switch(a){
    case 'A':return 0;
    case 'T':return 1;
    case 'C':return 2;
    case 'G':return 3;
  }
  return -1;
}
int main()
{
  int T;
  cin >> T;
  while(T--){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
      scanf("%s",input[i]);
    }
    int ans_val = 0;
    for(int i = 0;i < m;i++){
      int max_val = 0;
      for(int ii = 0;ii < 4;ii++)input_number[ii] = 0;
      char ans;
      for(int j = 0;j < n;j++){
        input_number[get_number(input[j][i])]++;
        if(max_val < input_number[get_number(input[j][i])]){
          max_val = input_number[get_number(input[j][i])];
          ans = input[j][i];
        }
        else if(max_val == input_number[get_number(input[j][i])] && ans > input[j][i]){
          ans = input[j][i];
        }
      }
      ans_val += n - max_val;
      printf("%c",ans);
    }
    printf("\n%d\n",ans_val);
  }
}
