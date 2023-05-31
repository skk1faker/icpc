#include<bits/stdc++.h>
using namespace std;
struct Basement{
  int get_remain;
  int get_out;
  Basement(int C = 0, int get_out = 0):C(C),get_out(get_out){}
};

struct stmt{
  int quary,num;
  stmt(int quary, int num):quary(quary),num(num);
};

queue<stmt>q;
map<int, stmt>dropback;
int main()
{
  int C,N;
  cin>>C>>N;
  Basement base(C,0);
  for(int i = 0;i < N;i++){
    int quary ,num;
    scanf("%d%d",&quary,&num);
    if(quary == -1){
      base.get_remain += dropback[num].num;
      base.get_out -= dropback[num].num;
      while(!q.empty()){
        
      }
    }
    else if(quary >= 0){
      dropback[i]
      if(base.C - base.get_out > quary){
          base.get_out += quary;
          base.get_remain -= quary;
      }
    }
  }
}
