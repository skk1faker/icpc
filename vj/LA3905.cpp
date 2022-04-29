#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
const int maxx = 1e5;

const double inf_time = 200000;		// 时间的尽头！ 
struct time_scale
{
	double l,r;
};
time_scale intangle_stat[maxx];

bool cmp_sort(time_scale t0, time_scale t1){return t0.l < t1.l; }			// from small to big
struct cmp_prioriqueue{
	bool operator ()(time_scale  t0, time_scale  t1){return t0.r > t1.r; }	// 优先队列小顶堆
};

bool get_time_brife(int x,int a,int w, time_scale & temp_time1){
	if (a == 0){
		if(0 < x&&x < w){
			temp_time1.l = 0;
			temp_time1.r = inf_time;
		}
		else return false;	// 空集合

	}
	else if(a>0){
		temp_time1.l = -(double)x/a;
		temp_time1.r = (double)(w-x)/a;
	} 
	else if (a<0){
		temp_time1.r = -(double)x/a;
		temp_time1.l = (double)(w-x)/a;
	}
	return (temp_time1.l < temp_time1.r) && temp_time1.r > 0;		//是不是空集合,注意这个时间可以为负数，方便我们处理,temp.time1.r == 0时我们无法观测到他
}
bool get_time(int x,int y,int a,int b, int w ,int h, time_scale & temp_time)
{
	bool ans = true;	//表示不是空集合
	time_scale t1;
	time_scale t2;
	ans = (get_time_brife(x, a, w, t1) && get_time_brife(y, b, h, t2));
	temp_time.l = max(t1.l, t2.l);
	temp_time.r = min(t1.r, t2.r);
	return ans && (temp_time.l < temp_time.r);
}
void solve (){
	int w ,h;
	cin>>w>>h;
	int x,y,a,b;
	int n,num_intangle = 0;
	cin>>n;
	while(n--){
		scanf("%d%d%d%d", &x,&y,&a,&b);
		if(get_time(x,y,a,b,w,h,intangle_stat[num_intangle]))num_intangle++;	//num_intangle 表示能观测到的星星个数

	}
	priority_queue<time_scale, vector<time_scale>, cmp_prioriqueue> pq;			// push pop top size empty()
	sort(intangle_stat,intangle_stat+num_intangle,cmp_sort);
	int ans=0;
	//cout<< "num = " <<num_intangle<<endl;
	for(int i=0 ;i < num_intangle; i++){
		if(intangle_stat[i].l < 0){
			pq.push(intangle_stat[i]);
			ans = (int)pq.size();	// 因为所有的l<0的满足r>0,所以一开始的时候就会有这么多的东西在框框内
			continue;
		}
		while(!pq.empty()){
			if(pq.top().r <= intangle_stat[i].l)pq.pop();
			else break;
		}
		pq.push(intangle_stat[i]);	// 此时一颗星星加入，同时排出其他星星！
		ans = max(ans , (int)pq.size() );
	}
	cout<<ans<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
