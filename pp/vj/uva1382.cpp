#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

const int maxx = (int)1e2+10;

struct Posi_stat
{
    int x,y;
    bool operator < (const Posi_stat &a){
        return x < a.x;
    }
}posi_star[maxx];
int y_posi[maxx];

// 最后结果为i,j， on[j] + on[i] + left[j-1] - left[i]
int on[maxx];
int left_sum[maxx];

int main()
{
    int n;
    int T = 0;
    while(scanf("%d",&n) == 1){
        if(n == 0)break;
        for(int i=0;i<n;i++){
            scanf("%d%d",&posi_star[i].x, &posi_star[i].y);
            y_posi[i] = posi_star[i].y;
        }
        sort(y_posi,y_posi + n);
        sort(posi_star,posi_star + n);
        int y_length = unique(y_posi,y_posi + n ) - y_posi;
        // for(int i=0;i<y_length;i++)cout<<y_posi[i]<<' ';cout<<endl;
        int ans = 0; 
        for(int posi_y1 = 0; posi_y1 < y_length; posi_y1++){
            for(int posi_y2 = posi_y1; posi_y2 < y_length; posi_y2++){
                int posi_x = 0;
                int pre_x = posi_star[0].x;
                left_sum[0] = 0;
                int max_left_on = 0;
                on[0] = 0;
                for(int i = 0 ;i<n;i++){
                    if(pre_x != posi_star[i].x){
                        if(posi_x != 0){
                            ans = max(ans, on[posi_x] + left_sum[posi_x - 1] + max_left_on);
                        }
                        else {
                            ans = max(ans, on[posi_x]);
                        }
                        max_left_on = max(on[posi_x] - left_sum[posi_x], max_left_on); 
                        posi_x++;
                        pre_x = posi_star[i].x;
                        left_sum[posi_x] = left_sum[posi_x - 1];
                        on[posi_x] = 0;
                    }
                    if(posi_star[i].y <= y_posi[posi_y2] && y_posi[posi_y1] <= posi_star[i].y){
                        on[posi_x]++;
                    }

                    if(posi_star[i].y == y_posi[posi_y2] || posi_star[i].y == y_posi[posi_y1]){
                        left_sum[posi_x]++;
                    }
                    
                }
                if(posi_x != 0){   
                    ans = max(ans, on[posi_x] + left_sum[posi_x - 1] + max_left_on);
                }
                else {      // 注意这个时候应该是一条线
                    ans = max(ans, on[posi_x]);
                }

                
            }
        }
        T++;
        printf("Case %d: %d\n",T,ans);

    }

    return 0;
}