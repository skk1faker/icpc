#include<iostream>
using namespace std;

void fuck(int (*a)[10])
{
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			printf("%d ",a[i][j]);
		}
	}
}

int main()
{
	int a[10][10];
	for(int i=0;i<10;i++){	
		for(int j=0;j<10;j++){
			a[i][j]=i+j;
		}
	}
	fuck(a);
	char aaaa='A'+10;
	printf("%c",aaaa);
	return 0;
}
