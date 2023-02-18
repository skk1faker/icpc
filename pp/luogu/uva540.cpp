#include<bits/stdc++.h>

using namespace std;
const int maxx = 1000;


int main() {
  int N, n;
  map<int, int> tour;
  queue<int>q_tour,q[maxx];
  int Case = 1;
  while (scanf("%d", &N) == 1 && N != 0) {
    printf("Scenario #%d\n",Case++);
    for (int i = 0; i < N; i++) {
      scanf("%d", &n);
      for (int j = 0; j < n; j++) {
        int temp;
        scanf("%d", &temp);
        tour[temp] = i;
      }
    }
    string op;
    while(cin>>op){
      switch(op[0]){
        case 'E' :{
          int id;
          scanf("%d",&id);
          if(q[tour[id]].empty())q_tour.push(tour[id]);
          q[tour[id]].push(id);
        }break;
        case 'D' :{
          if(!q_tour.empty()){
            cout<<q[q_tour.front()].front()<<endl;
            q[q_tour.front()].pop();
            if(q[q_tour.front()].empty())q_tour.pop();
          }
        }break;
      }
      if(op[0] == 'S')break;
    }
    while(!q_tour.empty()){
      int posi = q_tour.front();
      while(!q[posi].empty())q[posi].pop();
      q_tour.pop();
    }
    printf("\n");
  }
  return 0;
}
