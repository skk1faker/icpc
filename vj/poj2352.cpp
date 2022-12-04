#include <iostream>
using namespace std;
const int maxx = 32000 + 10;
int tree[maxx];
int ans[maxx];
void init() {
  for (int i = 0; i < maxx; i++)
    tree[i] = 0, ans[i] = 0;
}
int get_val(int val) {
  int ret = 0;
  for (int i = val; i > 0; i -= (i & (-i))) {
    ret += tree[i];
  }
  return ret;
}
void add(int val) {
  for (int i = val; i < maxx; i += (i & (-i))) {
    tree[i]++;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  init();
  for (int i = 0; i < n; i++) {
    int temp, value;
    scanf("%d%d", &value, &temp);
    value++;  // 防止value 为0
    ans[get_val(value)]++;
    add(value);
  }
  for (int i = 0; i < n; i++) {
    printf("%d\n",ans[i]);
  }
  return 0;
}
