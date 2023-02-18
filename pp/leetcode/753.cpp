#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

class Solution {
private :
    string ans;
//	const int maxx = 4097;
	int edge[4100];

public:
    string crackSafe(int n, int k) {
        memset(edge,0,sizeof(edge));
		eulor(0,n,k);
		for(int i=0;i<n-1;i++)ans+='0';
		return ans;
    }
	int get_next_edge(int posi, int edge_bit,int k){
		return posi * k + edge_bit;
	}
	int get_next_posi(int edge,int k,int n){
		return edge%((int)(pow(k,n-1)));
	}
	void eulor(int posi ,int n,int k){
		for(int i=0;i<k;i++){
			int next_edge = get_next_edge(posi,i,k);
			if(edge[next_edge] == 1)continue;
			edge[next_edge]=1;
			eulor(get_next_posi(next_edge,k,n),n,k);
			ans+=(char)('0'+i);
		}
	}
	
};

int main()
{
	int n,k;
	Solution ans;
	while(scanf("%d%d",&n,&k)==2){
		cout<<ans.crackSafe(n,k)<<endl;
	}
	return 0;
}
