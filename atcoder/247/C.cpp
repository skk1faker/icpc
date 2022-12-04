#include<iostream>
using namespace std;
void output(int n){
	if(n == 1){
		printf("1 ");
		return;
	}
	else {
		output(n - 1);
		printf("%d ",n);
		output(n - 1);
	}
}


int main()
{
	int n;
	scanf("%d",&n);
	output(n);
	return 0;
}
