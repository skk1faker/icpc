#include<iostream>
#include<cstring>
using namespace std;
const int maxx = 19;

int cap[4] = {2,6,10,14};
char name_char[4] = {'s','p','d','f'};
int name[maxx] = {0,0,1,0,1,0,2,1,0,2,1,0,3,2,1,0,3,2,1};
int layer[maxx] = {1,2,2,3,3,4,3,4,5,4,5,6,4,5,6,7,5,6,7};
int ans[7][4];
int main()
{
	int T;
	cin>>T;
	while(T--){
		int n;
		scanf("%d",&n);
		memset(ans,0,sizeof(ans));
		for(int i = 0;i < 19;i++){
			if(n <= cap[name[i]]){
				ans[layer[i] - 1][name[i]] = n;
				break;
			}
			else {
				n -= cap[name[i]];
				ans[layer[i] - 1][name[i]] = cap[name[i]];
			}
		}
		for(int i = 0;i < 7;i++){
			for(int j = 0;j < 4;j++){
				if(i ==0 && j==0){
					if(ans[i][j] > 0)
						printf("%d%c%d",i+1,name_char[j],ans[i][j]);
				}
				else {
					if(ans[i][j] > 0)printf(" %d%c%d",i+1,name_char[j],ans[i][j]);
				}

			}
		}
		cout<<endl;
	}
	return 0;
}
