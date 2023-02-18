#include<bits/stdc++.h>
using namespace std;
double log_val_bin(int n,int m)
{
  return log((double)1 - (pow(2,-n-1))) / log(2) + (1 << m) - 1;
}

int main()
{
  char str[40];
  double A;
  long long  B;
  while(scanf("%s",str) == 1 && strcmp(str,"0e0") != 0){
    //printf("%s\n",str);
    *strchr(str,'e') = ' ';
    sscanf(str,"%lf%lld",&A,&B);
    //printf("%.15lf %lld\n",A,B);
    int m = (log(log(A) / log(2) + log(10) / log(2) * B + 2) / log(2));
    int n = 0;
    double log_real = log(A)/log(2) + log(10) * B / log(2);
    for(int i = 0;i <= 9;i++){
      //printf("%.15lf\n",fabs(log_val_bin(i,m) - log_real));
      if(fabs(log_val_bin(n,m) - log_real) > fabs(log_val_bin(i,m) - log_real))n = i;
    }
    printf("%d %d\n",n,m);
  }
  return 0;
}
