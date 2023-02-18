#include <bits/stdc++.h>

using namespace std;
void get_next(vector<int> &now, int length) {
  vector<int> pre = now;
  while (length--) {
    now.clear();
    for (int i = 0; i < pre.size(); i++) {
      now.push_back(abs(pre[i] - pre[(i + 1) % pre.size()]));
    }
    pre = now;
  }
}
bool is_equal(const vector<int> &l1, const vector<int> &l2){
  for(int i = 0;i< l1.size();i++){
    if(l1[i] != l2[i])return false;
  }
  return true;
}
int main() {
  int T;
  cin >> T;
  vector<int> normal, fast;
  while (T--) {
    int n;
    scanf("%d", &n);
    normal.clear();
    fast.clear();
    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      normal.push_back(temp);
      fast.push_back(temp);
    }
    get_next(fast, 2);
    get_next(normal, 1);
    while (!is_equal(fast, normal)) {
      get_next(fast, 2);
      get_next(normal, 1);
    }
    int flag = 0;
    for (int i = 0; i < n; i++) {
      if (fast[i] != 0) {
        flag = 1;
        break;
      }
    }
    if (flag)
      cout << "LOOP" << endl;
    else
      cout << "ZERO" << endl;
  }
  return 0;
}
