#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int maxx = (int)5e5 + 10;
int value[maxx];
int tree[maxx];
inline int lowbit(int value) { return value & (-value); }

void init_tree() {
  for (int i = 0; i < maxx; i++)
    tree[i] = 0;
}

void add(int value) {
  while (value < maxx) {
    tree[value]++;
    value += lowbit(value);
  }
}

int check(int value) {
  int ans = 0;
  while (value > 0) {
    ans += tree[value];
    value -= lowbit(value);
  }
  return ans;
}

int main() {
  int n;
  vector<pair<int, int>> number_pair;
  while (scanf("%d", &n) == 1) {
    if(n == 0)break;
    number_pair.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d", &value[i]);
      number_pair.push_back(make_pair(value[i], i));
    }
    sort(number_pair.begin(), number_pair.end());
    int temp = 1;
    for (int i = 0; i < n; i++) {
      if (i >= 1 && number_pair[i - 1].first != number_pair[i].first)
        temp++;
      value[number_pair[i].second] = temp; //
    }
    long long ans = 0;
    init_tree();
    for (int i = 0; i < n; i++) {
      ans +=
          i - check(value[i]); // i 表示当前树组中的小于value[i]的元素数量
      add(value[i]);
    }
    cout << ans << endl;
  }
  return 0;
}
