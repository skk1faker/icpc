#include<bits/stdc++.h>
using namespace std;
const int max_=1000000005;
int n,m;
struct LMF {
	int c,x;//c为编号，x为边权 
} b;
int a,e;
int f[100005],fa,faa;
int fc[100005],d[100005],l;//fc存当前点上一个边的颜色，f存上一个点的编号 
queue<int> q;
vector<LMF> g[100005];
bool vis[1000005];
int main() {
	while(cin>>n>>m) {//多组数据！！！多组数据！！！多组数据！！！多组数据！！！ 
		for(int i=1; i<=n; i++)g[i].clear();
		while (!q.empty()) q.pop();
		l=0;//清零 
		for(int i=1; i<=m; i++) {
			cin>>a>>b.c>>b.x;
			g[a].push_back(b);
			swap(a,b.c);
			g[a].push_back(b);
		}
		for(int i=1; i<=n; i++) {
			fc[i]=max_;
			d[i]=max_;
			vis[i]=0;
			f[i]=0;
		}
		q.push(n);
		g[1].clear();
		vis[n]=1;
		d[n]=0;
		while(!q.empty()) {
			int a=q.front();
			q.pop();
			for(int i=0; i<g[a].size(); i++) {
				if(vis[g[a][i].c]==0) {//没有到过这个点 
					q.push(g[a][i].c);//push进去
					d[g[a][i].c]=d[a]+1;
					fc[g[a][i].c]=g[a][i].x;
					f[g[a][i].c]=a;
					vis[g[a][i].c]=1;//一堆更新 
				}
				if(d[g[a][i].c]<=d[a])continue;//如果下一个节点的距离比本节点还长,就不加考虑 
				if(fc[g[a][i].c]>g[a][i].x&&d[g[a][i].c]==d[a]+1) {
					fc[g[a][i].c]=g[a][i].x;
					f[g[a][i].c]=a;
					continue; 
				}//如果字典序此处就小立马更新
				if(fc[g[a][i].c]==g[a][i].x){
					faa=f[g[a][i].c];
					fa=a;
					while(fc[faa]==fc[fa]&&faa!=fa){//一层一层向上找 
						fa=f[fa];
						faa=f[faa];
					}
					if(fc[fa]<fc[faa])f[g[a][i].c]=a;//如果字典序更小,更新 
				}
			}
		}
		a=1;
		do {
			l++;
			a=f[a];
		} while(a!=n);
		cout<<l<<endl;
		a=1;
		do {
			cout<<fc[a];
			if(f[a]!=n)cout<<' ';
			a=f[a];
		} while(a!=n);
		cout<<endl;//平平无奇的输出
	}
	return 0;
}
