#include<iostream>

using namespace std;
int main()
{
	int n;
	cin>>n;
	double E = 0;
	double ans = 0;
	double pi;
	double pi_mi = 1;
	for(int i = 0;i < n;i++){
		scanf("%lf",&pi);
		ans += (2*E  + 1) * pi;
		E = (E + 1) * pi;
		//pi_mi = pi_mi * (pi - 1);
	}
	printf("%.10f",ans);
	return 0;
}
