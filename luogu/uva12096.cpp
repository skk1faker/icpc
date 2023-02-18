#include <algorithm>
#include <bits/stdc++.h>
#include <set>

#define Interval(x) (x).begin(), (x).end()
#define Insert(x) inserter(x, x.begin())

using namespace std;
typedef set<int> Set;
map<Set, int> set_map;
vector<Set> set_list; // 相当于存储了一个树形结构。

int ID(Set s) {
  if (set_map.count(s) == 1)
    return set_map[s];
  set_list.push_back(s);
  return set_map[s] = set_list.size() - 1;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    stack<int> st_Set;
    cin >> n;
    for (int i = 0; i < n; i++) {
      string oper;
      cin >> oper;
      switch (oper[0]) {
      case 'P': {
        Set s;
        st_Set.push(ID(s));
      } break;
      case 'D': {
        st_Set.push(st_Set.top());
      } break;
      case 'U': { // union
        Set x[2];
        x[0] = set_list[st_Set.top()];
        st_Set.pop();
        x[1] = set_list[st_Set.top()];
        st_Set.pop();
        Set ans;
        set_union(Interval(x[0]), Interval(x[1]), Insert(ans));
        st_Set.push(ID(ans));

      } break;
      case 'I': {

        Set x[2];
        x[0] = set_list[st_Set.top()];
        st_Set.pop();
        x[1] = set_list[st_Set.top()];
        st_Set.pop();
        Set ans;
        set_intersection(Interval(x[0]), Interval(x[1]), Insert(ans));
        st_Set.push(ID(ans));
      } break;
      case 'A': {
        Set x[2];
        x[0] = set_list[st_Set.top()];
        st_Set.pop();
        x[1] = set_list[st_Set.top()];
        st_Set.pop();
        x[1].insert(ID(x[0]));
        st_Set.push(ID(x[1]));
      } break;
      }
      printf("%ld\n", set_list[st_Set.top()].size());
    }
    printf("***\n");
  }
  return 0;
}
