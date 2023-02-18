#include <bits/stdc++.h>

using namespace std;

int main() {
  set<pair<int, int>> se_student;
  int n;
  while (scanf("%d", &n) == 1 && n != 0) {
    for (int i = 0; i < n; i++) {
      int a, b;
      scanf("%d%d", &a, &b);
      if (se_student.count(make_pair(b, a)) == 0) {
        se_student.insert(make_pair(a, b));
      } else {
        se_student.erase(make_pair(b, a));
      }
    }
    if (se_student.empty())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
    se_student.clear();
  }
  return 0;
}
