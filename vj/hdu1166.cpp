#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxx = 50000 + 10;
int trees[maxx << 2];
int val[maxx];

int renewtree(int l,int r,int nodeposi)
{
    int mid = (l + r)/2;
    if(l == r){
        trees[nodeposi] = val[l];
        return trees[nodeposi];
    }

    int newr = mid;
    int newl = mid + 1;
    trees[nodeposi] = renewtree(l,newr,nodeposi<<1) + renewtree(newl,r,(nodeposi<<1)+1);
    return trees[nodeposi];
}

void changetree(int l,int r,int nodeposi,int val,int change_posi){

    trees[nodeposi] += val;   // 路径上的所有制都应该修改。
    if(l == r){
        return ;
    }

    int mid = (l + r)/2;
    if(mid >= change_posi)changetree(l,mid,nodeposi<<1,val,change_posi);
    else changetree(mid+1,r,(nodeposi<<1)+1,val,change_posi);
    return ;
}

int quary(int l, int r, int nodeposi, int quire_l, int quire_r) // nodeposi << 1 编号从1，2，3，4，5
{
    if(l >= quire_l && quire_r >= r){
        return trees[nodeposi]; 
    }

    int mid = (l + r)/2;
    int ans = 0;
    if(quire_l <= mid){
        ans += quary(l, mid, nodeposi<<1, quire_l, quire_r);
    }
    if(quire_r >= mid + 1){
        ans += quary(mid+1, r, (nodeposi<<1)+1, quire_l, quire_r);
    }

    return ans;

}
void get_input(char *output,int &p1,int &p2)
{
    int n = strlen(output);
    int posi = 0;
    p1 = 0,p2 = 0;
    while(!isdigit(output[posi]))posi++;
    while(isdigit(output[posi])){
        p1 *= 10;
        p1 += output[posi] - '0';
        posi++;
    }
    while(!isdigit(output[posi]))posi++;
    while(isdigit(output[posi])&&posi < n){
        p2 *= 10;
        p2 += output[posi] - '0';
        posi++;
    }
    return ;
}
int main()
{
    int T;
    cin>>T;
    for(int Case = 1; Case <= T; Case++){
        printf("Case %d:\n",Case);
        int n;
        cin>>n;
        for(int i=0;i<n;i++)scanf("%d",&val[i]);
        renewtree(0,n-1,1);
        do{
            char inputline[50];
            fgets(inputline,50,stdin);
            // printf("%s\n",inputline);
            if(inputline[0] == 'A'||inputline[0] == 'S'){
                int change_posi = 0,val = 0;
                get_input(inputline, change_posi,val);
                change_posi--;
                if(inputline[0] == 'S')val *= -1;
                changetree(0,n-1,1,val,change_posi);
            }
            else if(inputline[0] == 'Q'){
                int ql, qr;
                get_input(inputline,ql,qr);

                ql--;
                qr--;
                cout<<quary(0,n-1,1,ql,qr)<<endl;
            }
            else if(inputline[0] == 'E') {
                break;// 标识跳出循环
            }
        }while(true);
    
    }
    return 0;
}