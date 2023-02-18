#include<iostream>
#include<queue>
#include<vector>
const int maxx = 30 + 5;
int dist[2][maxx];
int n;

struct edge
{
	int to,length;
	bool operator < (const edge temp)const{
		return this->length > temp.length;
	}
	edge(int to,int lenght):to(to),length(length){}
};
vector<edge>G[maxx];
void dijstra(int s,int t, int MAX)
{
	for(int i = 0;i < n;i++){
		dist[0][i] = maxx * MAX + 10;
	}
	dist[0][s] = 0;
	priority_queue<edge> pq;
	pq.push(edge(s,0));
	while(!pq.empty()){
		edge now_edge = pq.top();
		pq.pop();
		int now_posi = now_edge.to;
		if(now_posi == t)return ;
		if(dist[0][now_posi] != now_edge.length)continue;
		for(auto son_edge : G[now_posi]){
			if(dist[0][now_posi] + son_edge.length < dist[0][son_edge.to]){
				dist[0][son_edge.to] = dist[0][now_posi] + son_edge.length;
				pq.push(edge(son_edge.to, dist[0][son_edge.to]));
			}
		}
	}
}

int Astar(int s,int t,int k)	// 注意这个和dijstra没有什么关系
{
	dist[1][t] = 0;
	priority_queue<edge> pq;
	pq.push_back(edge(t, dist[1][t]));
	while(!pq.empty()){
		
	}
}

int main()
{
	int n,s,t,MAX;
	scanf("%d%d%d%d",*n,&s,&t,&MAX);
	for(int i = 1;i <= n;i++){
		for(int j = 1; j <= n; j++)
		int length  = 0;
		scanf("%d",&length);
		if(length < MAX)G[i].push_back(edge(j,length));
	}
	dijstra(s,t,MAX);
	Astar(s,t,n);
}
