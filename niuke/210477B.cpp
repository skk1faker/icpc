#include<iostream>
const int maxx = 100 + 1;
double dp[maxx];
int a[maxx];
using namespace std;

int main(){
	
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
	}
	// 按照转移的可能性来推导
	dp[n] = a[n];
	for(int i = n - 1; i >= 1;i--){
		dp[i] = a[i];
		double temp_p = (double)1 / min(6, n - i);
		for(int j = 1; j <= min(6, n - i) ;j++){
			dp[i] += temp_p * dp[i + j];
		}
	}
	printf("%.10lf\n", dp[1]);
	return 0;
}
