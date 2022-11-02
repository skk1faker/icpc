// https://www.luogu.com.cn/problem/P5490
//思路就是计算0的长度，然后用查询的总长度减去0的长度，但是维护起来好像不行，因为如果有一个去见里面没有0的话，那么程序就会一致查到叶子节点，时间上就会和浪费
// 如果我们能记录一个去见是否被覆盖，那末就可以解决这个问题。

// tree_cover == -1 表示有覆盖
// tree_cover == 0 表示没有覆盖
// tree_cover > 0 表示这是一个覆盖
#include <iostream>
#include <algorithm>
using namespace std;

const int maxx = (int)4e5+10;
const int maxx_square = (int)1e5+10;
long long tree_cover[maxx_square<<3];    // 标识所代表的去见被覆盖住了
long long discert[maxx_square<<1];          // 不用严格的离散化也可以

struct line
{
    long long x,y[2],val;
    bool operator <(const line &tt)
    {
        return this->x < tt.x;
    }
}square_line[maxx_square<<1];

// bool cmpx(line l1, line l2)     //l1 ,l2 是最后排序结束之后的顺序
// {
//     return l1.x < l2.x;         // 我们只需要规定这个顺序下，元素之间的关系就可以了
// }

void build(int l, int r, int nodeid)
{
    tree_cover[nodeid] = 0;
    if(l == r)return ;
    int mid = (l + r)/2;
    build(l, mid, (nodeid<<1));
    build(mid + 1, r, (nodeid<<1)+1);
}

long long quire(int l,int r,int nodeid){  // 频繁出错的原因是子结点并不能维护节点长度，导致子节点在返回长度的时候出错！
    if(l<=r){       // 所以这里需要给出一个定义就是我们需要让节点表示线段！
        if(tree_cover[nodeid] > 0)return discert[r+1] - discert[l];
        else if(tree_cover[nodeid] == 0) return 0;
    }
    if(l>r)return 0;

    int mid = (l + r)/2;
    int ans =0;
    ans = quire(l,mid,(nodeid<<1));
    ans += quire(mid+1,r,(nodeid<<1)+1);

    return ans;
}

void add_line(int l,int r,int nodeid,int val, int ql,int qr){
    if(l>r)return ;
    if((ql <= discert[l] && discert[r+1] <= qr && tree_cover[nodeid]>=0)||l == r){
        tree_cover[nodeid] += val;
        return;
    }
    if(tree_cover[nodeid] >= 0){
        tree_cover[nodeid<<1] = tree_cover[nodeid];
        tree_cover[(nodeid<<1)+1] = tree_cover[nodeid];
    }
    int mid = (l + r)/2;
    if(ql < discert[mid+1])add_line(l,mid,(nodeid<<1),val,ql,qr);       //discert 记录的是点的值
    if(qr > discert[mid+1])add_line(mid+1,r,(nodeid<<1)+1,val,ql,qr);//不能重复加入
    if(tree_cover[(nodeid<<1)] == tree_cover[(nodeid<<1)+1])tree_cover[nodeid] = tree_cover[(nodeid<<1)];
    else tree_cover[nodeid] = -1;
    return ;
}

int find_val(int l, int r ,long long val){

    if(l == r){
        if(discert[l] == val)return l;
        else return -1;
    }
    if(l > r)return -1;
    int mid = (l + r)/2;
    if(val == discert[mid])return mid;
    else if(val < discert[mid])return find_val(l,mid-1,val);
    else if(val > discert[mid])return find_val(mid+1,r,val);
    return -1;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        long long posi_temp[4];
        for(int j=0;j<4;j++)scanf("%lld",&posi_temp[j]);
        square_line[(i<<1)].val = 1;
        square_line[(i<<1)].x = posi_temp[0];
        square_line[(i<<1)].y[0] = posi_temp[1];
        square_line[(i<<1)].y[1] = posi_temp[3];
        square_line[(i<<1)+1].val = -1;
        square_line[(i<<1)+1].x = posi_temp[2];
        square_line[(i<<1)+1].y[0] = posi_temp[1];
        square_line[(i<<1)+1].y[1] = posi_temp[3];
        discert[(i<<1)] = square_line[(i<<1)].y[0];
        discert[(i<<1)+1] = square_line[(i<<1)].y[1];
    }
    // sort(square_line,square_line+(n<<1),cmpx);
    sort(square_line,square_line+(n<<1));

    sort(discert,discert+(n<<1));
    // int max_discert = 0;
    int max_discert = unique(discert, discert + (n<<1)) - discert - 1;
    // for(int i=0;i<(n<<1);i++){
    //     if(i >= 1&&discert[i] != discert[max_discert])max_discert++;
    //     discert[max_discert] = discert[i];
    // }
    // for(int i=0;i<=max_discert;i++)cout<<discert[i]<<' ';cout<<endl;
    long long line_long = 0;
    long long ans = 0;
    for(int i=0;i<(n<<1);i++){
        if(i>=1){
            // cout<<line_long<<' '<<square_line[i].x - square_line[i-1].x<<endl;
            ans += (square_line[i].x - square_line[i-1].x) * line_long;
        }
        // int l = find_val(0,max_discert,square_line[i].y[0]);
        // int r = find_val(0,max_discert,square_line[i].y[1]);
        int l = square_line[i].y[0];
        int r = square_line[i].y[1];
        // cout<<l<<r<<endl;
        add_line(0,max_discert-1,1,square_line[i].val,l,r);
        line_long = quire(0, max_discert-1, 1);

    }
    // cout<<ans<<endl;
    printf("%lli",ans);
    return 0;
}