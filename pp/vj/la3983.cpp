#include<iostream>
using namespace std;

const int maxx = (int)1e5 + 10 ;
int dp[maxx];
int dist_sum[maxx];
int weight[maxx];
int ori_dist[maxx];
int queue_up[maxx];

int f(int i){return dp[i] + ori_dist[i+1] - dist_sum[i+1];}

int main()
{
    int N;
    cin>>N;
    while(N--){
        int cap_max,package_num;
        cin>>cap_max>>package_num;
        int posi[2][2] = {};
        dist_sum[0] = 0;
        weight[0] = 0;
        ori_dist[0] = 0;
        for(int i=1;i<=package_num;i++){
            int now = i%2,pre = (i-1)%2;
            scanf("%d%d%d",&posi[now][0],&posi[now][1],&weight[i]);
            ori_dist[i] = abs(posi[now][0]) + abs(posi[now][1]);
            dist_sum[i] = dist_sum[i-1] + abs(posi[now][0] - posi[pre][0]) + abs(posi[now][1] - posi[pre][1]);
        }

        int front = 0,tail = 0;
        tail =  (tail + 1);
        queue_up[tail] = 0;
        int total_weight = 0;
        int last_posi = 0;
        for(int i=1;i<=package_num;i++){
            total_weight += weight[i];
            while(!(total_weight <= cap_max)){
                if(front != tail && queue_up[ (front + 1) % maxx] == last_posi - 1)front = (front + 1) % maxx;
                total_weight -= weight[last_posi];
                last_posi++ ;
            }

            dp[i] = f(queue_up[(front + 1)%maxx]) + dist_sum[i] + ori_dist[i];

            while( !(tail == front)&&f(i) <= f(queue_up[tail]) ){
                tail = (tail - 1)%maxx; 
            }
            tail = (tail + 1) % maxx;
            queue_up[tail] = i;

        }
        cout<<dp[package_num]<<endl;
        if(N)cout<<endl;
    }
    // return 0;
}