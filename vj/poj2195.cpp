#include<iostream>
#include<algorithm>
using namespace std;

const int maxx = 1000;

struct Edge
{
    double x;   // 参与排序
    double y[2];    // 参与整数化
    int val;
    bool operator < (const Edge & a){return x < a.x;}
}edge[maxx<<1];

double y[maxx<<1];       //discrete

int tree[maxx<<2];
void build_tree(int l,int r,int posi)// from 0 start
{
    if(l > r)return ;
    tree[posi] = 0;
    int mid = (l+r)>>1;
    build_tree(l,mid,posi*2 + 1);
    build_tree(mid+1,r,posi*2+2);
}

double find_in_tree(int l,int r,int posi,int val,double modl, double modr)    // val 我感觉需要一个lazy标记！！不然时间会很长！，但是先尝试一下不写lazy吧
{
    if(l>r)return 0;
    if(modl <= y[l] && y[r+1] <= modr){
        if(tree[posi]+val >=2)return y[r+1] - y[l];
        val+=tree[posi];
    }
    int mid = (l+r)>>1;
    double ans = 0;
    if(modl < y[mid+1]){
        ans += find_in_tree(l,mid,posi*2+1,val,modl,modr);
    }
    if(y[mid+1] < modr){
        ans += find_in_tree(mid+1,r,posi*2+2,val,modl,modr);
    }
    return ans;
}

void change_tree(int l,int r,int posi,int val, double modl,double modr)   // 表示(y[l],y[r+1])中的情况！！
{
    if(l > r)return ;
    if(modl <= y[l] && y[r+1] <= modr){
        tree[posi]+=val;
        return ;
    }
    int mid = (l+r)>>1;
    if(!(modl >= y[mid+1])){
        change_tree(l,mid,posi*2+1,val,modl,modr);
    }
    //如果是modl == y[mid+1],表示所查区间只有一个点和我们相交。根据题意，我们只对线段感兴趣，并不会维护点的性质！！！
    if(!(y[mid + 1] >= modr)){
        change_tree(mid+1,r,posi*2+2,val,modl,modr);
    }
    return ;
}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int N;  // 多少正方形
        cin>>N;
        for(int i=0;i<N;i++){
            double x[2],y[2];
            scanf("%lf%lf%lf%lf",&x[0],&y[0],&x[1],&y[1]);
            edge[2*i + 1].x = x[1];
            edge[2*i + 1].y[0] = y[0];
            edge[2*i + 1].y[1] = y[1];
            edge[2*i + 1].val = -1;
            edge[2*i].x = x[0];
            edge[2*i].y[0] = y[0];
            edge[2*i].y[1] = y[1];
            edge[2*i + 1].val = 1;
            y[2*i] = y[0];
            y[2*i + 1] = y[1];
        }
        sort(y,y+(2*N));
        int discrete_length = unique(y,y+(2*N)) - y;
        sort(edge, edge+(2*N));

        cout<<discrete_length<<endl;
        // for(int i = 1;i<2*N;i++){
            // change_tree();
        // }
    }
    return 0;
}