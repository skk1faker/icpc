#include<iostream>
using namespace std;
int main()
{
	double ans = 0;
	int n = 0, Case = 1;
	scanf("%d",&n);

	while(scanf("%d",&n) == 1){
		ans = 0;
		for(int i = 1;i <= n;i++){
			ans += (double)n / (double)i;
		}
		//cout<<ans<<endl;
		printf("Case %d: %.10lf\n",Case++,ans);
	}
	return 0;
}
