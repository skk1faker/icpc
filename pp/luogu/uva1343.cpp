/*================================================================
*   Copyright (C) 2023 Sangfor Ltd. All rights reserved.
*   
*   filename：    uva1343.cpp
*   username:     skt1faker
*   create time:  11:44  2023.05.21
    email:        skk1faker@163.com
*   descripe:     
*
================================================================*/

#include<bits/stdc++.h>
using namespace std;

struct Operator_mode{
  int x,y,dx,dy;
  Operator_mode(int x = 0,int y = 0,int dx = 0,int dy = 0):x(x),y(y),dx(dx),dy(dy){}
}op[8];
int reverse_op[8];

const int maxx = 7;
int mapp[maxx][maxx] = {{0,0,-1,0,-1,0,0},{0,0,-1,0,-1,0,0},{-1,-1,-1,-1,-1,-1,-1},{0,0,-1,0,-1,0,0}, {-1,-1,-1,-1,-1,-1,-1},{0,0,-1,0,-1,0,0},{0,0,-1,0,-1,0,0}};

void oper(int mode){
  int x = op[mode].x,y = op[mode].y;
  if(op[mode].dx != 0){
    int temp_val = mapp[x][y];
    for(int i = 0;i < 7;x += op[mode].dx,i++){
      int new_x = (x + op[mode].dx + maxx) % maxx;
      if(i < 6)mapp[x][y] = mapp[new_x][y];
      else {
        mapp[x][y] = temp_val;
      }
    }
  }
  else {
    int temp_val = mapp[x][y];
    for(int i = 0;i < 7;y += op[mode].dy,i++){
      int new_y = (y + op[mode].dy + maxx) % maxx;
      if(i < 6){
        mapp[x][y] = mapp[x][new_y];
      }else {
        mapp[x][y] = temp_val;
      }
    }
  }
}

void init(){
  op[0] = Operator_mode(0,2,1,0);
  op[1] = Operator_mode(0,4,1,0);
  op[2] = Operator_mode(2,6,0,-1);
  op[3] = Operator_mode(4,6,0,-1);
  op[4] = Operator_mode(6,4,-1,0);
  op[5] = Operator_mode(6,2,-1,0);
  op[6] = Operator_mode(4,0,0,1);
  op[7] = Operator_mode(2,0,0,1);
  reverse_op[0] = 5;
  reverse_op[5] = 0;
  reverse_op[1] = 4;
  reverse_op[4] = 1;
  reverse_op[2] = 7;
  reverse_op[7] = 2;
  reverse_op[3] = 6;
  reverse_op[6] = 3;
}
int check(){
  int num[4] = {0,8,8,8};
  for(int i = 2;i<=4;i++){
    for(int j =2 ;j<=4;j++){
      if(i == 3 && j == 3)continue;
      num[mapp[i][j]]--;
    }
  }
  //cout << min(min(num[1],num[2]), num[3]) << endl;
  return min(min(num[1],num[2]), num[3]);
}
int ans_list[100];
bool dfs(int finish,int aim_step){
  if(check() + finish > aim_step)return false;
  if(finish == aim_step){
    if(check() == 0)
      return true;
    return false;
  }
  for(int i = 0;i < 8;i++){
    oper(i);
    ans_list[finish] = i;
    if(dfs(finish + 1, aim_step))
      return true;
    oper(reverse_op[i]);
  }
  return false;
}

bool get_input()
{
  int x = 0,y =0;
  for(int i = 0;i <24 ;i++){
    while(mapp[x][y] == 0){
      y++;
      if(y >= 7){
        y = 0;
        x++;
      }
    }
    if(scanf("%d",&mapp[x][y]) != 1)return false;
    y++;
    if(y >= 7){
      y = 0;
      x++;
    }
  }
  return true;
}

int main()
{
  init();  
  while(get_input()){
    int ans = 0;
    for(;;ans++){
      if(dfs(0,ans))break;
    }
    if(ans == 0){
      cout<<"No moves needed";
    }
    else {
      for(int i = 0;i < ans;i++){
        printf("%c",'A' + ans_list[i]);
      }
    }
    cout<<endl;
    cout<<mapp[2][2]<<endl; // 最后没有这个换行回判错
  }
}
