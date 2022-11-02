#include<iostream>
#include<algorithm>
using namespace std;

const int maxx = 1<<16 + 1;
int INF = (int)(15*15) * (2000 * 2000) + 10;
int dp[maxx];	// 最小

int area[maxx];	// area[i],编号为i的矩形大小
int point[maxx];	// point[i],编号为i的矩形包括点的集合
int point_xy[maxx][2];

int main()
{
	int n;
	while(scanf("%d",&n) == 1 && n!=0){
		for(int i = 0;i < n;i++)
			scanf("%d%d",&point_xy[i][0],&point_xy[i][1]);
		int cnt = 0;	// 代表矩形数量
		for(int i = 0;i < n;i++){
			for(int j = 0;j < i;j++){
				area[cnt] = abs((point_xy[i][0] - point_xy[j][0]) * (point_xy[i][1] - point_xy[j][1]));
				int flag = 0;
				int p[2][2][2];	// [点][左下右上][xy]
				p[0][0][0] = min(point_xy[i][0], point_xy[j][0]);
				p[0][0][1] = min(point_xy[i][1], point_xy[j][1]);
				p[0][1][0] = max(point_xy[i][0], point_xy[j][0]);
				p[0][1][1] = max(point_xy[i][1], point_xy[j][1]);
				if(point_xy[i][0] == point_xy[j][0]){
					flag = 1;
					area[cnt] = abs(point_xy[i][1] - point_xy[j][1]);	//左方向
					area[cnt + 1] = abs(point_xy[i][1] - point_xy[j][1]);	// 右方向
					p[0][0][0] = min(point_xy[i][0], point_xy[j][0] - 1);
					p[0][0][1] = min(point_xy[i][1], point_xy[j][1]);
					p[0][1][0] = max(point_xy[i][0], point_xy[j][0] - 1);
					p[0][1][1] = max(point_xy[i][1], point_xy[j][1]);
					p[1][0][0] = min(point_xy[i][0], point_xy[j][0] + 1);
					p[1][0][1] = min(point_xy[i][1], point_xy[j][1]);
					p[1][1][0] = max(point_xy[i][0], point_xy[j][0] + 1);
					p[1][1][1] = max(point_xy[i][1], point_xy[j][1]);				
				}
				else if(point_xy[i][1] == point_xy[j][1]){
					flag = 1;
					area[cnt] = abs(point_xy[i][0] - point_xy[j][0]);
					area[cnt+1] = abs(point_xy[i][0] - point_xy[j][0]);
					p[0][0][0] = min(point_xy[i][0], point_xy[j][0]);
					p[0][0][1] = min(point_xy[i][1], point_xy[j][1] - 1);
					p[0][1][0] = max(point_xy[i][0], point_xy[j][0]);
					p[0][1][1] = max(point_xy[i][1], point_xy[j][1] - 1);
					p[1][0][0] = min(point_xy[i][0], point_xy[j][0]);
					p[1][0][1] = min(point_xy[i][1], point_xy[j][1] + 1);
					p[1][1][0] = max(point_xy[i][0], point_xy[j][0]);
					p[1][1][1] = max(point_xy[i][1], point_xy[j][1] + 1);				
					
				}
				point[cnt] = 0;
				point[cnt + flag] = 0;
				for(int k = 0;k < n;k++){	// 判断点再不在范围里面
					if(point_xy[k][0] <= p[0][1][0] && point_xy[k][0] >= p[0][0][0] && p[0][0][1] <= point_xy[k][1] && point_xy[k][1] <= p[0][1][1]){
						point[cnt] |= (1<<k);
					}
					if(flag == 1){
						if(point_xy[k][0] <= p[1][1][0] && point_xy[k][0] >= p[1][0][0] && p[1][0][1] <= point_xy[k][1] && point_xy[k][1] <= p[1][1][1]){
							point[cnt + 1] |= (1<<k);
						}
					}
				}
				cnt += (flag + 1);	
			}
		}

		for(int s = 1;s < (1<<n);s++)dp[s] = INF;
		dp[0] = 0;
		for(int s = 0;s < (1<<n);s++){
			for(int sq = 0;sq < cnt;sq++){
				dp[s|point[sq]] = min(dp[s|point[sq]], dp[s] + area[sq] );
			}
		}
		printf("%d\n",dp[(1<<n) - 1]);
	}
	return 0;
}
