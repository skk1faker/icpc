#include<iostream>

using namespace std;
const int maxx = 50000 +10;
const int min_tall = 1;
const int max_tall = (int)1e6;
int max_tree[maxx<<2],min_tree[maxx<<2];
int val[maxx];

void init(int l, int r, int nodenum){
    if(l==r){
        max_tree[nodenum] = val[l];
        min_tree[nodenum] = val[l];
        return ;
    }
    int mid = (l+r)>>1;
    init(l,mid,nodenum<<1);
    init(mid+1,r,(nodenum<<1)+1);
    max_tree[nodenum] = max(max_tree[(nodenum<<1)], max_tree[(nodenum<<1)+1]);
    min_tree[nodenum] = min(min_tree[(nodenum<<1)], min_tree[(nodenum<<1)+1]);
}

int quire(int l,int r,int nodenum,int ql,int qr,int mode)//mode == 0max, mode == 1min
{       
    // 注意函数默认一件事，就是ql,qr必与l,r相交
    if(ql<=l&&r<=qr){
        if(mode == 0)return max_tree[nodenum];
        else return min_tree[nodenum];
    }
    int mid = (l + r)/2;
    int ans;
    if(mode == 0)ans = min_tall;
    else ans = max_tall;
    //目的是找到所有包含ql-qr的子结点，不相交的点不访问
    if(ql <= mid){      //ql是最边界的点，边界的点在mid的左边，因为ql，qr和l，r必有相交的点，所以l，mid必与ql，qr相交。
        if(mode == 0)ans = max(ans , quire(l,mid,nodenum<<1,ql,qr,mode));
        else ans = min(ans, quire(l,mid,(nodenum<<1),ql,qr,mode));
    }
    if(mid + 1 <= qr){  // 如果相交的话也要访问
        if(mode == 0)ans = max(ans , quire(mid+1,r,(nodenum<<1)+1,ql,qr,mode));
        else ans = min(ans, quire(mid+1,r,(nodenum<<1)+1,ql,qr,mode));
    }
    return ans;
}

int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i=0;i<N;i++)scanf("%d",&val[i]);
    init(0,N-1,1);
    for(int i = 0;i<Q;i++){
        int p1,p2;
        scanf("%d%d",&p1,&p2);
        p1--,p2--;
        cout<<quire(0,N-1,1,p1,p2,0) - quire(0,N-1,1,p1,p2,1)<<endl;
    }
    return 0;
}