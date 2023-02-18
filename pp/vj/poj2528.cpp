// 本题注意离散化！！！！

#include<iostream>
#include<algorithm>
using namespace std;
const int maxx = (int)1e5+10;
int tree_num[maxx<<2];
int discert[maxx<<2];// use 2分查找
int val[maxx][2];
int vis[maxx];



int find_val(int l,int r, int val)
{
    if(l == r)return l;
    if(l > r) return -1;
    int mid = (l + r)>>1;
    if(discert[mid] == val)return mid;
    else if(val <discert[mid]){
        return find_val(l,mid - 1,val);
    }
    else if(val > discert[mid]){
        return find_val(mid+1,r,val);
    }
    return -1;
}

void build_tree(int l,int r,int nodeid)
{
    tree_num[nodeid] = 0;
    if(l == r)return;
    int mid = (l + r)/2;
    build_tree(l,mid,(nodeid<<1));
    build_tree(mid+1,r,(nodeid<<1)+1);
    return;
}

void pushdown(int nodeid)
{
    tree_num[nodeid<<1] = tree_num[nodeid];
    tree_num[(nodeid<<1) + 1] = tree_num[nodeid];
}

void add_picture(int l,int r,int nodeid, int val, int ql, int qr){
    if(ql <= l && r <= qr){
        tree_num[nodeid] = val;
        return ;
    }
    if(tree_num[nodeid] > 0)pushdown(nodeid);
    tree_num[nodeid] = -1;
    int mid = (l + r) >> 1;
    if(ql <= mid){
        add_picture(l, mid, (nodeid<<1), val, ql, qr);
    }
    if(qr >= mid + 1){
        add_picture(mid+1, r, (nodeid<<1)+1,val, ql, qr);
    }
}

int ans = 0;

void quire(int l,int r,int nodeid)
{

    if(tree_num[nodeid] > 0){
        if(vis[tree_num[nodeid]] == 0)ans++;
        vis[tree_num[nodeid]] = 1;
        return ;
    }
    if(l >= r){
        return ;
    }
    int mid = (l + r)/2;
    quire(l,mid,(nodeid<<1));
    quire(mid+1,r,(nodeid<<1)+1);
}



int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            scanf("%d%d",&val[i][0],&val[i][1]);
            // discert[(i<<1)] = val[i][0];
            // discert[(i<<1)+1] = val[i][1];
            discert[(i<<2)] = val[i][0];
            discert[(i<<2)+1] = val[i][0] + 1;
            discert[(i<<2)+2] = val[i][1];
            discert[(i<<2)+3] = val[i][1] + 1;
        }
        sort(discert,discert+(n<<2));
        int edge_posi = 0;
        for(int i = 0;i < (n<<2);i++){
            if(i-1 >=0 && discert[i] != discert[i-1])edge_posi++;
            discert[edge_posi] = discert[i];
        }
        int max_scale = edge_posi;
        build_tree(0,max_scale,1);
        for(int i = 1;i <= n ;i++)vis[i] = 0;
        for(int i = 0;i < n;i++){
            int l = find_val(0,edge_posi,val[i][0]);
            int r = find_val(0,edge_posi,val[i][1]);
            add_picture(0,max_scale,1,i+1,l,r);
        }
        ans = 0;
        quire(0,max_scale,1);
        cout<<ans<<endl;
    }
    return 0;
}