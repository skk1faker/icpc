/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    c1.cpp
*   username:     skt1faker
*   create time:  11:03  2023.05.14
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;
int main() {
  const int maxx = (int)1e3 + 1;
  int dp[maxx][maxx];
  int row_length = grid.size();
  int col_length = grid[0].size();
  int dir[3][2] = {{1,-1},{1,0},{1,1}};
  for(int i = col_length - 1;i >=0 ;i--){
    for(int j = 0;j < row_length;j++){
      dp[i][j] = 1;
      for(int k = 0;k< 3;k++){
        int new_i = i + dir[k][0];
        int new_j = j + dir[k][1];
        if((0<= new_i && new_i < col_length) && (0 <= new_j && new_j < row_length)){
          if(grid[i][j] < grid[new_i][new_j]){
            dp[i][j] = max(dp[i][j], dp[new_i][new_j] + 1);
          }
        }
      }
    }
  }
  cout<<dp[0][0]<<endl;
}
