#include<iostream>
#include<cmath>
using namespace std;
const int maxx = 8;
int set_name[maxx];
int leng[maxx];
float S(int *a)
{
	float ans = 0;
	float a4[3];
	float a2[3];
	for(int i=0;i<3;i++){
		a2[i] = a[i]*a[i];
		a4[i] = a2[i]*a2[i];
	}
	float sum2 = 0;
	float sum4 = 0;
	for(int i=0 ; i<3; i++){
		sum2 += 2 * a2[0]*a2[1]*a2[2]/a2[i];
		sum4 += a4[i];
	}

	ans = 0.25*sqrt(sum2-sum4);
	return ans;
}

float cal_s(int n)
{
	float ans = 0;
	int a[3]={0,0,0};
	for(int i=0;i<n;i++){
		if(set_name[i] == 3)continue;
		a[set_name[i]]+=leng[i];
	}
	if(a[0]+a[1]>a[2]&&abs(a[0]-a[1])<a[2])return S(a);
	return 0;
}
float dfs(int posi,int n){
	float ans = 0;
	if(posi == n){		//说明0--n-1 已经分配完！
		return cal_s(n);
	}
	for(int j=0;j<4;j++){
		set_name[posi] = j;
		ans = max(dfs(posi+1,n),ans);
	}
	return ans;
}


int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&leng[i]);
	}
	float ans = dfs(0,n);
	if(ans > 0){
		printf("%0.1f",ans);
	}
	else {
		cout<<-1<<endl;
	}
}
