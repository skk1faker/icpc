#include <bits/stdc++.h>
using namespace std;
multiset<pair<int, int>> point;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      int p[2];
      scanf("%d%d", &p[0], &p[1]);
      point.insert(make_pair(p[0], p[1]));
    }
    multiset<pair<int, int>>::iterator iter[2] = {point.begin(), point.end()};
    iter[1]--;
    sum = iter[0]->first + iter[1]->first;
    int flag = 1;
    while (point.size() >= 2) {
      iter[0] = point.begin();
      iter[1] = point.find(make_pair(sum - iter[0]->first, iter[0]->second));
      if (iter[1] == point.end()) {
        flag = 0;
        break;
      }
      if(iter[0] == iter[1]){
        point.erase(iter[0]);
      } 
    else{

      point.erase(iter[0]);
      point.erase(iter[1]);
      }
    }
    if (flag == 1) {
      if (n % 2 == 1) {
        iter[0] = point.begin();
        if (iter[0]->first * 2 != sum) {
          cout << "NO" << endl;
        } else
          cout << "YES" << endl;
      } else
        cout << "YES" << endl;
    } else
      cout << "NO" << endl;
    point.clear();
  }
}
