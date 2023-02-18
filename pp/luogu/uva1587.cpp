#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;
int main() {
  int h[6], w[6];
  vector<pair<int, int>> vec_list;
  map<int, int> map_edge;
  while (scanf("%d%d", &h[0], &w[0]) == 2) {
    vec_list.clear();
    map_edge.clear();
    for (int i = 0; i <= 5; i++) {
      if (i)
        scanf("%d%d", &h[i], &w[i]);
      if (h[i] > w[i])
        swap(h[i], w[i]);
      map_edge[h[i]]++;
      map_edge[w[i]]++;

      vec_list.push_back(make_pair(h[i], w[i]));
    }
    sort(vec_list.begin(), vec_list.end());
    int a[3];
    int num = 0;
    for (map<int, int>::iterator iter = map_edge.begin();
         iter != map_edge.end(); iter++) {
      while(iter->second != 0 && iter->second %4 == 0){
          a[num++] = iter->first;
          iter->second -= 4;
        }
    }
    if (num != 3) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }
    num = 0;
    int flag = 1;
    for (int i = 0; i < 3 && flag; i++) {
      for (int j = i + 1; j < 3 && flag; j++) {
        for (int _ = 0; _ < 2; _++) {
          if (!(vec_list[num].first == a[i] && vec_list[num].second == a[j])) {
            flag = 0;
            break;
          }
          num++;
        }
      }
    }
    if (flag)
      cout << "POSSIBLE" << endl;
    else
      cout << "IMPOSSIBLE" << endl;
  }
}
