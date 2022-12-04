#include<iostream>
using namespace std;
const int maxx = (int)2e5 + 10;
int a[maxx];
int max_x,min_y;
int n;
int lr[2][maxx];
int rear[2],front[2];
int main()
{
	scanf("%d%d%d",&n,&max_x,&min_y);
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	n = n + 1;
	a[n - 1] = min_y - 1;
	int length = 0;
	long long ans = 0;
	for(int i = 0;i < n;i++){
		if(min_y <= a[i] && a[i] <= max_x)length++;
		else {
			if(length == 0)continue;
			int l_edge = i - length,r_edge = i - 1;
			int l = l_edge,r = l_edge;
			rear[0] = 0;
			rear[1] = 0;
			front[0] = 0;
			front[1] = 0;
			for(int r = l_edge; r <= r_edge; r++){
				while(lr[0][rear[0] - 1] > a[r] && rear[0] != front[0])rear[0] = (rear[0] - 1 + maxx) % maxx; 
				lr[0][rear[0]] = a[r];
				rear[0] = (rear[0] + 1) % maxx;
				while(lr[1][rear[1] - 1] < a[r] && rear[1] != front[1])rear[1] = (rear[1] - 1 + maxx) % maxx; 
				lr[1][rear[1]] = a[r];
				rear[1] = (rear[1] + 1) % maxx;

				// 此时单调队列中必然有元素
				while(lr[0][front[0]] == min_y && lr[1][front[1]] == max_x && l <= r){
					ans += (r_edge - r + 1);
					if(a[l] == min_y)front[0] = (front[0] + 1) % maxx;
					if(a[l] == max_x)front[1] = (front[1] + 1) % maxx;
					l++;
				}
			}
			length = 0;
		}
	}
	cout<<ans<<endl;
	return 0;

}
