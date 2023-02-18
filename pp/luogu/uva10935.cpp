#include <bits/stdc++.h>

using namespace std;
int main() {
  queue<int> q;
  int n;
  while (scanf("%d", &n) == 1 && n != 0) {
    for (int i = 1; i <= n; i++)
      q.push(i);
    int mode = 0;
    cout << "Discarded cards:";
    while (1) {
      int ele = q.front();
      q.pop();
      if (q.empty()) {
        cout << endl << "Remaining card: " << ele << endl;
        break;
      }
      if (mode == 0) {
        if(ele == 1)
          cout<< ' ' <<ele;
        else 
        cout << ", " << ele;
      } else {
        q.push(ele);
      }
      mode ^= 1;
    }
  }
  return 0;
}
