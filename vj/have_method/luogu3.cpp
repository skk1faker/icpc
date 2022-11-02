#include<iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
#define l(x) ((x)<<1)
#define r(x) (((x)<<1)|1)

const int maxx = (int)1e5 + 10;
struct line
{
    ll x,y[2];
    int val;
    bool operator < (const line &l1){
        return this->x < l1.x;
    }
    line(ll x=0,ll y_1=0, ll y_2=0, int val=0){
        this->x = x;
        this->y[0] = y_1;
        this->y[1] = y_2;
        this->val = val;
    }
}square_line[maxx<<1];
ll discert[maxx<<1];
int tree_cover[maxx<<3];    //表示当前取见被修改次数
int tree_len[maxx<<3];

void build_tree(int l,int r,int nodeid){
    tree_cover[nodeid] = 0;
    tree_len[nodeid] = 0;
    if(l == r)return ;
    int mid = (l+r)/2;
    build_tree(l,mid,nodeid);
    build_tree(mid+1,r,nodeid);
    return ;
}

void renew_len(int posi,int l,int r)    //更新一个节点的length的值
{
    if(tree_cover[posi] == 0){
        if(l == r)  tree_len[posi] = 0;
        else tree_len[posi] = tree_len[l(posi)] + tree_len[r(posi)];
    }
    else {
        tree_len[posi] = discert[r+1] - discert[l];
    }
}

void push_down(int posi,int l,int r){
    tree_cover[l(posi)] += tree_cover[posi];
    tree_cover[r(posi)] += tree_cover[posi];
    tree_cover[posi] = 0;
    int mid = (l + r)>>1;
    renew_len(l(posi), l, mid);
    renew_len(r(posi), mid+1, r);
    renew_len(posi,l,r);
}


void add_line(int l,int r,int nodeid,int val,int ql, int qr){
    if((ql<=discert[l]&&discert[r+1]<=qr&&tree_cover[nodeid] + val >= 0)||l == r){
        tree_cover[nodeid] += val;
        renew_len(nodeid, l, r);
        return ;
    }
    if(l>r)return ;
    int mid = (l+r)>>1;
    // push_down(nodeid,l,r);   // 加上会tle，原因是tree_cover[nodeid]是根本不可能出现负数的！
    if(ql < discert[mid+1])add_line(l,mid,l(nodeid),val,ql,qr);
    if(qr > discert[mid+1])add_line(mid+1,r,r(nodeid),val,ql,qr);
    // renew_len(nodeid,l,r);

}


int main()
{
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        ll temp_posi[4];
        for(int j=0;j<4;j++)scanf("%lld",&temp_posi[j]);
        square_line[i<<1] = line(temp_posi[0],temp_posi[1],temp_posi[3],1);
        square_line[(i<<1)|1] = line(temp_posi[2],temp_posi[1],temp_posi[3],-1);
        discert[i<<1] = temp_posi[1];
        discert[(i<<1)|1] = temp_posi[3];   
    }
    sort(discert,discert+(n<<1));
    sort(square_line,square_line+(n<<1));
    int max_discert = unique(discert,discert+(n<<1)) - (discert+1) ;
    // for(int i =0;i<=(max_discert);i++)cout<<discert[i]<<' ';cout<<endl;
    build_tree(0, max_discert-1, 1);
    ll ans = 0;
    for(int i=0;i<(n<<1);i++){        
        int l = square_line[i].y[0];
        int r = square_line[i].y[1];
        int val = square_line[i].val;
        if(i>=1)ans += tree_len[1] *(square_line[i].x - square_line[i-1].x);
        add_line(0,max_discert-1,1,val,l,r);
        cout<<tree_len[1]<<endl;
    }
    // cout<<ans<<endl;
    printf("%lli", ans);
    return 0;
}
