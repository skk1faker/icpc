#include<iostream>
using namespace std;
const int maxx=40;
int number[maxx];
int gcd(int a,int b)
{
	if (a==b)return a;
	if (a>b) a=a-b;
	else b=b-a;
	return gcd(a,b);
}

int solve(int n)
{
	int min_num=(int)1e7;
	int gcd_ans;
	for(int i=0 ;i<n;i++){
		if(number[i]<min_num)min_num = number[i];	
	}
	bool flag=true;
	for (int i=0 ;i<n;i++){
		if(number[i]!=min_num){
			gcd_ans=number[i];
			flag=false;
			break;
		}
	}
	if(flag)return -1;
	gcd_ans-=min_num;
	for(int i=0;i<n;i++){
		number[i] -= min_num;
		if(number[i]==0)continue;
		gcd_ans = gcd(gcd_ans,number[i]);
	}
	return gcd_ans;
}
void get_input()
{
	int T;
	cin>>T;

	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&number[i]);
		}

		cout<<solve(n)<<endl;

	}
}
int main()
{
	get_input();
	return 0;
}
