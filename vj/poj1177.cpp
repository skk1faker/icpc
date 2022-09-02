#include<iostream>
#include<algorithm>
#define l(x) (x<<1)
#define r(x) ((x<<1)|1)

using namespace std;
const int maxx = (int)5e3+10;
int discert[maxx<<2];
struct line
{
    int p1,p2[2];
    int val;   
    line(int x=0,int y_1=0,int y_2=0,int val=0){
        p1 = x;
        p2[0] = y_1;
        p2[1] = y_2;
        this->val =val;
    }
    bool operator < (const line &l1){
        return p1 < l1.p1;
    }
};
line square_line_x[maxx<<1];
line square_line_y[maxx<<1];

int tree_node_num[maxx<<2]; // 边点数量
int tree_node_edge[maxx<<2][2]; //  边界点位置
int tree_cover[maxx<<2];    //  覆盖情况


void build_tree(int l,int r,int nodeid)
{
    tree_node_num[nodeid] = 0;
    tree_node_edge[nodeid][0] = 0;  // left
    tree_node_edge[nodeid][1] = 0;  // right
    tree_cover[nodeid] = 0;

    if(l == r)return ;
    int mid = (l + r)/2;
    build_tree(l, mid,l(nodeid));
    build_tree(mid+1,r,l(nodeid));
}

void renew_val(int nodeid,int l,int r)
{
    if(tree_cover[nodeid] == 0){   //非叶子节点怎么处理
        if(l<r){
            if(tree_node_num[l(nodeid)] > 0 && tree_node_num[r(nodeid)] > 0){
                tree_node_edge[nodeid][0] = tree_node_edge[l(nodeid)][0];
                tree_node_edge[nodeid][1] = tree_node_edge[r(nodeid)][1];
                tree_node_num[nodeid] = tree_node_num[l(nodeid)] + tree_node_num[r(nodeid)];
                if(tree_node_edge[l(nodeid)][1] == tree_node_edge[r(nodeid)][0]) tree_node_num[nodeid] -= 2;
            }
            else if(tree_node_num[l(nodeid)] > 0){
                tree_node_edge[nodeid][0] = tree_node_edge[l(nodeid)][0];
                tree_node_edge[nodeid][1] = tree_node_edge[l(nodeid)][1];
                tree_node_num[nodeid] = tree_node_num[l(nodeid)];
            }
            else if(tree_node_num[r(nodeid)] > 0){
                tree_node_edge[nodeid][0] = tree_node_edge[r(nodeid)][0];
                tree_node_edge[nodeid][1] = tree_node_edge[r(nodeid)][1];
                tree_node_num[nodeid] = tree_node_num[r(nodeid)];
            }
            else {
                tree_node_num[nodeid] = 0;
            }
        }
        else if(l == r){        // 在叶子节点应该怎么作处理
            tree_node_num[nodeid] = 0;
        }
            
    }
    else if(tree_cover[nodeid] > 0){    
        tree_node_edge[nodeid][0] = discert[l];
        tree_node_edge[nodeid][1] = discert[r+1];
        tree_node_num[nodeid] = 2;
    }
}

void add_line(int l,int r,int nodeid,int val, int ql, int qr){//发生递归后的节点信息要维护好
    if(ql<=discert[l] && discert[r+1]<=qr){
        tree_cover[nodeid] +=val;
        renew_val(nodeid,l,r);
        return ;
    }
    if(l>r)return ;
    int mid = (l+r+1)/2;
    if(ql < discert[mid])add_line(l,mid-1,l(nodeid),val,ql,qr);
    if(qr > discert[mid])add_line(mid,r,r(nodeid),val,ql,qr);
    renew_val(nodeid,l,r);//叶子节点更新完之后要更新本节点，保证信息的准确性
    return ;
}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j = 0;j < 4;j++)scanf("%d",&discert[(i<<2)+j]);
        square_line_x[(i<<1)] = line(discert[(i<<2)], discert[(i<<2)+1], discert[(i<<2)+3],1);
        square_line_y[(i<<1)] = line(discert[(i<<2)+1], discert[(i<<2)], discert[(i<<2)+2],1);
        square_line_x[(i<<1)+1] = line(discert[(i<<2)+2], discert[(i<<2)+1], discert[(i<<2)+3],-1);
        square_line_y[(i<<1)+1] = line(discert[(i<<2)+3], discert[(i<<2)], discert[(i<<2)+2],-1);
    }
    sort(square_line_x, square_line_x + (n<<1));
    sort(square_line_y, square_line_y + (n<<1));
    sort(discert, discert + (n<<2));
    int max_discert = unique(discert, discert + (n<<2)) - (discert + 1); 
    // for(int i=0;i<=max_discert;i++)cout<<discert[i]<<' ';cout<<endl;
    long long length = 0;
    build_tree(0,max_discert-1,1);
    for(int i=0;i<(n<<1);i++){
        if(i>0){
            length += (square_line_x[i].p1 - square_line_x[i-1].p1) * tree_node_num[1];
        }
        add_line(0,max_discert-1,1,square_line_x[i].val,square_line_x[i].p2[0],square_line_x[i].p2[1]);
        // cout<<tree_node_num[1]<<endl;
    }
    build_tree(0,max_discert-1,1);
    for(int i=0;i<(n<<1);i++){
        if(i>0){
            length += (square_line_y[i].p1 - square_line_y[i-1].p1) * tree_node_num[1];
        }
        add_line(0,max_discert - 1,1,square_line_y[i].val,square_line_y[i].p2[0],square_line_y[i].p2[1]);
    }
    cout<<length<<endl;

}