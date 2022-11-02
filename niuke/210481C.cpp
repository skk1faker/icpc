#include<iostream>
// dp[i] 表示i到目标需要的步数，于是
// dp[i] = \sum_{3}^{k1+k2+k3}p[j](dp[i+j] + 1) + pabc*dp[0]

const int maxx = 500 + 18 + 1;
double p[19];
double A[maxx],B[maxx];
using namespace std;

int main()
{
	int n;
	int k[3],abc[3];
	cin>>n;
	for(int i = 0;i < 2;i++){
		for(int j = 0;j < 3;j++){
			if(i == 0){
				scanf("%d",&k[j]);
			}
			else {
				scanf("%d",&abc[j]);
			}
		}
	}
	for(int i = 0;i < 19;i++)p[i] = 0;
	for(int i = 1;i <= k[0];i++){
		for(int j = 1;j <= k[1];j++){
			for(int kk = 1;kk <= k[2];kk++){
				p[i + j + kk]+=1;
			}
		}
	}
	p[abc[0] + abc[1] + abc[2]] -=1;
	p[0] = 1;	
	for(int i = 0;i <= k[0] + k[1] + k[2];i++){
		p[i] = p[i] / (k[0] * k[1] * k[2]);
		A[n + i] = 0;
		B[n + i] = 0;
	}
	for(int i = n;i >= 0;i--){
		A[i] = 0;
		B[i] = 0;
		for(int j = 3;j <= k[0] + k[1] + k[2];j++){
			A[i] += p[j] * A[i + j];
			B[i] += p[j] * B[i + j];
		}
		A[i] += p[0];
		B[i] += 1;
	}

	double ans = B[0]/(1 - A[0]);
	printf("%.10lf\n",ans);
	return 0;
}
