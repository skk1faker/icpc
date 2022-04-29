//https://cloud.tencent.com/developer/article/1695822

//是一个二分题目
/*
	但是判断一个策略是否成立，却是这个二分需要研究的问题
	1.贪心，使用贪心的时候就必须要证明，存在一种分配方法可以转化为贪心方法！！！
	少于平均数的派要进行补，需要从其他pie上进行切分，

*/
#include<iostream>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
const double eps = 1e-5;
bool justify(double ans,int n,int *r,int m)
{
	int num=0;
	for(int i=0;i<n;i++){
		num+=(int)((double)(r[i]*r[i])/(ans));
	}
	return num>=(m+1);			//表示可以成功分配！！！
}

int main()
{
	int radio[(int)1e4+5];
	int n,m;
	int T;
	cin>>T;
	double maxx;
	while(T--){
		
		maxx=0;
		cin>>n>>m;
		for(int i=0;i<n; i++){
//			printf("%d\n",i);
			scanf("%d",&radio[i]);
			maxx = max(maxx, (double)(radio[i]*radio[i]));
		}
		double l=0,r=maxx,mid;
		while(!(fabs(l-r)<eps))	//注意！后面的是表示fabs(l-r)<eps是最终输出条件！！！！
		{
			mid=(l+r)/2;
			if(justify(mid,n,radio,m))	//true表示能进行分配
				l=mid;
			else 
				r=mid;
		}
		printf("%.5lf\n",l*PI);
		//if(T!=0)cout<<endl;
	}
	return 0;
}
