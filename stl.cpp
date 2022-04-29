#include<map>
#include<set>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{

	int a[][2][4] = {{{1,2},{3,4}},{{1,2,3,4},{5,6,7,8}}};
	for(int i=0 ;i<2;i++){
		for(int j=0;j<4;j++){
			cout<<a[0][i][j];
		}cout<<endl;
	}

		
}
