#include<iostream>
using namespace std;

int grid[16][16];
int temp[16][16];
int ans = 16*16;

int was[3][2] = {{-1,1},{-2,0},{-1,-1}};
void dfs(int finish, int n){
    if(finish == n){
        int temp_ans = 0;
        for(int c=0;c<n;c++){// column
            for(int r=0;r<n;r++){//row
                if(c == 0){
                    temp_ans += temp[c][r] - grid[c][r];
                    continue;
                }
                int sum = 0;
                for(int p = 0;p < 3;p++){
                    int new_column = c + was[p][0];
                    int new_row = r + was[p][1];
                    if(new_column < n && new_column >= 0 && new_row < n && new_row >= 0){
                        sum += temp[new_column][new_row];
                    }
                }
                temp[c][r] = sum % 2;
                if(grid[c][r] == 1 && temp[c][r] == 0)return ;
                temp_ans += temp[c][r] - grid[c][r];
            }
        }
        ans = min(ans,temp_ans);
        return ;
    }
    temp[0][finish] = grid[0][finish];
    dfs(finish + 1, n);
    if(grid[0][finish] == 0)
    {
        temp[0][finish] = 1;
        dfs(finish + 1, n);
    }
    return ;
}

int main()
{
    int T,n;
    cin>>T;
    int Case = 0;
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            for(int j = 0;j<n;j++){
                scanf("%d",&grid[i][j]);
            }
        }
        ans = 16*16;
        dfs(0,n);
        if(ans == 16*16)ans = -1;
        printf("Case %d: %d\n",++Case, ans);
    }

    return 0;
}