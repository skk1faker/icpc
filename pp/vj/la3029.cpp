#include<iostream>
using namespace std;

int field[1001][1001];
int length_bottom[1001][1001];

void input_data(int n,int m)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char ans;
            do {
                ans = getchar();
            }while(!(ans == 'R' || ans == 'F'));
            field[i][j] = (ans=='R' ? 1:0);
        }
    }
}
void solve(int n,int m)
{
    for(int j=0;j<m;j++)length_bottom[n][j] = 0;
    for(int i = n-1;i>=0 ;i--){
        for(int j=0; j<m; j++){
            if(field[i][j] == 1)length_bottom[i][j] = 0;
            else {
                length_bottom[i][j] = length_bottom[i+1][j] + 1;
            }
        }
    }
    int ans = 0;
    for(int row = 0; row < n; row++){
        for(int column = 0; column < m; column++){
            int min_length = 1001;
            for(int search_column = column; search_column < m;search_column++){
                if(field[row][search_column] == 1)break;
                min_length = min(min_length, length_bottom[row][search_column]);
                ans = max(ans, min_length * (search_column - column + 1));
            }
        }
    }
    cout<<3 * ans<<endl;

}
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        input_data(n,m);
        solve(n,m);
    }
    return 0;
}