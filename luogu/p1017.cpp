#include<iostream>
using namespace std;
int mod(int ,int);
char output[40]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void stack(int n,int r)
{
	if(n==0){
		return ;
	}
	int ans = mod(n,r);
	n -=ans;
	n /=r;
	stack(n,r);
	printf("%c",output[ans]);
}
int mod(int n,int r)
{
	int ans = (n-(n/r)*r);
	while(ans<0)
		ans-=r;
	return ans;
}
int main()
{
	int n,r;
	while(scanf("%d%d",&n,&r) == 2){
//		while(!(n==0)){
//			printf("%c",output[mod(n,r)]);
//			n-=mod(n,r);
//			n/=r;
//		}
		printf("%d=",n);
		stack(n,r);
		printf("(base%d)\n",r);
	}
	return 0;
}



