#include<iostream>
#include<cstring>

using namespace std;
const int max_add = 1000 + 1;

int dp[100][max_add];   // 
int p[2][100];


int main()
{
    int n,d;
    cin>>n>>d;
    int temp = 2;
    while(temp--){
        for(int i = 0;i < n;i++){
            scanf("%d",&p[temp]);
        }
    }
    memset(dp,0,sizeof(dp));
    for(int i = 0;i < n;i++){
        for(int j = 0;j < d;j++){
            dp[i][j] = dp[];
        }
    }
    return 0;
}