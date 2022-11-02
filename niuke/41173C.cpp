#include<iostream>
#include<map>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		long n,m;
		map<int,int> val;
		scanf("%ld%ld",&n,&m);
		long sum = 0;
		for(int i = 0;i < n;i++){
			int a;
			scanf("%d",&a);
			sum += a;
			sum %= m;
			val[(a) % m]++;
		}
		int ans = 0;
		for(auto [key,value] : val ){
			if(val[(sum + m - key) % m] != 0 && val[key] != 0){
				if (((sum + m - key) % m ) == key){
					if(val[key] >= 2){
						ans = sum;
						if(sum == 0)ans = m;
						break;
					}
				}
				else {
					ans = sum;
					if(sum == 0)ans = m;
					break;
				}
			}
		}
		cout<<ans<<endl;

	}	
	return 0;
}
