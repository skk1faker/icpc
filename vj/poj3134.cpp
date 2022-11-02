#include<iostream>
#include<cstring>

using namespace std;
const int maxx = 2000+5;
int val_vis[maxx];
int val_set[maxx];

int n,ans = maxx;

int f(int deep){
	int temp_ans = 0;
	int max_val = 0;
	for(int i = 0;i <= deep;i++){
		max_val = max(max_val,val_set[i]);
	}
	while(max_val < n){
		temp_ans++;
		max_val <<=1;
	}
	return temp_ans;
}

bool dfs(int deep, int now_i, int length){	// 此时集合中有deep + 1个元素。deep 表示操作数量 , now_i表示新加入集合的元素
	if(now_i <= 0)return false;
	if(now_i == n)return true;
	val_set[deep] = now_i;
	if(deep >= length)return false;
	if((deep + f(deep)) > length)return false;// A*;	
	if(val_vis[now_i] == 1)return false;
	val_vis[now_i] = 1;
	for(int i = 0;i <= deep;i++){
		if(dfs(deep+1,now_i + val_set[i], length)) return true;
		if(dfs(deep+1,now_i - val_set[i], length)) return true;
	}
	val_vis[now_i] = 0;
	return false;
}

int main()
{
	while(scanf("%d",&n) == 1&&n){
		for(int length = 0;length <= n;length++){
			memset(val_vis,0,sizeof(val_vis));
			if(dfs(0,1,length)){
				cout<<length<<endl;
				break;
			}
		}
	}
	return 0;
}
