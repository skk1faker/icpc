#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int bin_search(vector<int> list, int val) {
  int l = 0, r = list.size() - 1;
  int mid ;
  if (list[l] > val || list[r] < val)
    return -1;
  while (l < r) {
    mid = (l + r) / 2 + (l + r) % 2;
    if (list[mid] <= val) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  if (list[l] == val)
    return l + 1;
  else
    return -1;
}
int main() {
  int n, m;
  vector<int> list;
  int Case = 1;
  while (scanf("%d%d", &n, &m) == 2 && n != 0) {
    printf("CASE# %d:\n", Case++);
    list.clear();
    for (int i = 0; i < n; i++) {
      int temp;
      scanf("%d", &temp);
      list.push_back(temp);
    }
    sort(list.begin(), list.end());
    for (int i = 0; i < m; i++) {
      int temp;
      scanf("%d",&temp);
      //int ans = bin_search(list, temp);
      vector<int>::iterator ans = lower_bound(list.begin(),list.end(),temp);
      if (ans == list.end() || *ans != temp) {
        printf("%d not found\n", temp);
      } else {
        printf("%d found at %d\n", temp, ans - list.begin() + 1);
      }
    }
  }
  return 0;
}
