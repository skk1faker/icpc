// 注意两个需要优化的目标应该如何处理！
// 两个变量维护目标！
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int max_node = (int)1e3+10;
const int M = (int)1e3+10;  // 1. 大于v2最大值
// int dp[max_node][2];
int v2[max_node][2];    // 是附加状态，表示的是一个边被两个点照亮的情况！
vector<int> tree[max_node];

int vis[max_node];//用于判断树是否被访问完毕
int dfs(int root, int pre_node, int val) // 
{
    vis[root] = 1;
    int ans = 0;
    vector<int>::iterator iter = tree[root].begin();
    v2[root][val] = 0;
    if(val == 0){   // 这个点不放置街灯
        for(;iter!=tree[root].end();iter++){
            if(*iter == pre_node)continue;  // 不能回去
            ans += dfs(*iter, root, 1);//放置大街灯
            v2[root][val] += v2[*iter][1];
            // ans++;      //这是(root *iter)是只有一个灯照亮的地方
        }
    }
    else {              // 放置街灯
        ans++;
        for(;iter!=tree[root].end();iter++){
            if(*iter == pre_node)continue;
            int val_dp[2];
            val_dp[0] = dfs(*iter, root, 0);
            val_dp[1] = dfs(*iter, root, 1);
            int choose = (val_dp[0] < val_dp[1]) ? 0 : 1;
            ans += val_dp[choose];
            if(val_dp[0] == val_dp[1]){
                v2[root][val] += max(v2[*iter][0], v2[*iter][1] + 1);
            }
            else {
                if(choose == 1 && val == 1)v2[root][val]++;
                v2[root][val] += v2[*iter][choose];
            }
        }
    }
    return ans;
}

int main()
{
    int n,m;
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            tree[i].clear();
        }
        for(int i=0;i<m;i++){
            int node_temp[2];
            scanf("%d%d",&node_temp[0],&node_temp[1]);
            tree[node_temp[0]].push_back(node_temp[1]);
            tree[node_temp[1]].push_back(node_temp[0]);
        }
        int ans = 0;
        int v2_ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                // ans += min(dfs(i,-1,0), dfs(i,-1,1));
                int val_dp[2];
                val_dp[0] = dfs(i,-1,0);
                val_dp[1] = dfs(i,-1,1);
                ans += min(val_dp[0],val_dp[1]);
                int choose = val_dp[0] < val_dp[1] ? 0 : 1;
                if(val_dp[0] == val_dp[1]){
                    v2_ans += max(v2[i][0], v2[i][1]);
                }
                else {
                    v2_ans += v2[i][choose];
                }
            }
        }
        cout<<ans<<' ';
        cout<<v2_ans<<' ';
        cout<<m - v2_ans<<endl;
    }
    return 0;
}


/*

使用一种变量记录答案
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

const int max_node = (int)1e3+10;
const int M = (int)1e3+10;  // 1. 大于v2最大值
int dp[max_node][2];
vector<int> tree[max_node];

int vis[max_node];//用于判断树是否被访问完毕
int dfs(int root, int pre_node, int val) // 
{
    vis[root] = 1;
    int ans = 0;
    vector<int>::iterator iter = tree[root].begin();
    if(val == 0){   // 这个点不放置街灯
        for(;iter!=tree[root].end();iter++){
            if(*iter == pre_node)continue;  // 不能回去
            ans += dfs(*iter, root, 1);//放置大街灯
            ans++;      //这是(root *iter)是只有一个灯照亮的地方
        }
    }
    else {          // 放置街灯
        ans += M;
        for(;iter!=tree[root].end();iter++){
            if(*iter == pre_node)continue;
            int val[2];
            val[0] = dfs(*iter, root, 0);
            val[1] = dfs(*iter, root, 1);
            if(val[0] < val[1])ans++;       // 不放置街灯
            ans += min(val[0],val[1]);
        }
    }
    return ans;
}

int main()
{
    int n,m;
    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++){
            tree[i].clear();
        }
        for(int i=0;i<m;i++){
            int node_temp[2];
            scanf("%d%d",&node_temp[0],&node_temp[1]);
            tree[node_temp[0]].push_back(node_temp[1]);
            tree[node_temp[1]].push_back(node_temp[0]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(vis[i] == 0){
                ans += min(dfs(i,-1,0), dfs(i,-1,1));
            }
        }
        cout<<ans / M<<' ';
        cout<<m - (ans % M)<<' ';
        cout<<(ans % M)<<endl;
    }
    return 0;
}


*/