#include<iostream>
using namespace std;
int n;

bool dfs(int ans,int val[])
{
    if(ans == 0){
        for(int i = 0;i < n;i++){
            if(val[i] != i + 1)return false;
        }
        return true;
    }
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){     // 选择复制位置
            for(int posi = 0;posi <= n ;posi++){  // 选择粘贴位置
                if(i <= posi||posi <= j)continue;
                
            }
        }
    }

}

int main()
{

    int val[10];
    int T = 1;
    while(scanf("%d",&n) == 1 && n!=0){
        for(int i = 0;i < n;i++)scanf("%d",&val[i]);
        int ans = 1;
        while(1){
            if(dfs(ans,val))break;
            ans++;
        }
        printf("Case %d: %d\n",T,ans);
    }
    return 0;
}