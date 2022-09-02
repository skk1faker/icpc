//https://www.cnblogs.com/lighter-blog/p/7216349.html

// 未提交！！！

#include<iostream>
#include<vector>

using namespace std;

struct tree{
    double L,R;
    tree(double x,double y):L(x),R(y){}
};

int w[6];
vector<tree>trees[1<<6];
double sum[1<<6];
int vis[1<<6];  //  代表是否计算过这个树
double r;       // 代表树的半径

void dfs(int sets)
{
    if(vis[sets] == 1)return ;
    vis[sets] = 1;
    if(((sets - 1)&sets) == 0){ // 只有一个元素
        trees[sets].push_back(tree(0,0));
        return ;
    }
    for(int subset = ((sets - 1)&sets); subset > 0 ;subset = ((subset - 1) & sets)){
        int otherset = sets ^ subset;
        dfs(subset);        //L  // 此时所有的子树都已经遍历
        dfs(otherset);      //R      
        double L = (sum[otherset]) / sum[sets];
        double R = (sum[subset] )/sum[sets];

        for(int L_number = 0; L_number < trees[subset].size(); L_number++){
            for(int R_number = 0; R_number < trees[otherset].size(); R_number++){   
                double new_L = max(trees[subset][L_number].L + L, trees[otherset][R_number].L - R);       //注意这里的max！！！
                double new_R = max(trees[otherset][R_number].R + R, trees[subset][L_number].R - L);
                if(new_L + new_R <= r){
                    trees[sets].push_back(tree(new_L, new_R));
                }
            }
        }
    }
    return ;
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        int s;
        cin>>r;
        cin>>s;
        for(int i=0;i<s;i++)scanf("%d",&w[i]);
        // for(int i=0;i<s;i++)cout<<w[i]<<endl;
        for(int i=1;i<(1<<s);i++){
            sum[i] = 0;
            trees[i].clear();
            vis[i] = 0;
            for(int j = 0;j < s; j++){
                if(((1<<j)&i) != 0)sum[i] += w[j];
            }

            // cout<<sum[i]<<endl;
        }
        // cout<<endl;
        int allset = (1<<s) - 1;

        dfs(allset);
        double ans = 0;
        int ans_num = 0;
        for(int i=0;i<trees[allset].size();i++){
            double length = (trees[allset][i].L + trees[allset][i].R);
            if(length <= r + 1e-5){
                ans_num++;
                ans = max(ans, length);
            }
        }
        if(ans_num == 0)cout<<-1<<endl;
        else {
            printf("%.15lf\n",ans);
        }
    }
    return 0;
}