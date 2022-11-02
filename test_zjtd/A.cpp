#include<vector>
#include<iostream>
using namespace std;

const int maxx = (int)1e7;
int fa[maxx];
int ans[maxx];

void init(int n)
{
    for(int i = 0;i < n;i++){
        fa[i] = i;
    }
    return;
}

int find(int i){
    int ori = i;
    while(!(fa[i] == i)){
        i = fa[i];
    }
    while(!(fa[ori] == ori)){
        int temp = fa[ori];
        fa[ori] = i;
        ori = temp;
    }
    return i;
}

void merge(int i,int j){
    int pai = find(i);
    int paj = find(j);
    if(pai == paj)return ;
    fa[pai] = paj;  // i的父亲变成j了，两个集合就合并了

}

int main()
{
    int x;
    int n;
    cin>>n;
    init(n);
    for(int i = 0;i < n;i++){
        for(int j = 0;j<n;j++){
            int temp;
            scanf("%d",&temp);
            if(temp == 1)merge(i,j);
        }
    }
    cin>>x;
    int ans_length = 0;
    int pax = find(x);
    for(int i = 0;i < n;i++){
        if(find(i) == pax){
            ans[ans_length] = i;
            ans_length++;
        }
    }
    printf("[");
    for(int i = 0;i < ans_length - 1;i++){
        printf("%d, ",ans[i]);
    }
    if(ans_length - 1 >= 0)
        printf("%d]",ans[ans_length-1]);
    else 
        printf("]");

    return 0;
}
