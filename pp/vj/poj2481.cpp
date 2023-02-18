#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
const int maxx = (int)1e5 + 5;
int ans_cow[maxx];
class COW {
public:
  int s, e, posi;
  bool operator<(const COW &temp) const {
    if (this->e != temp.e)
      return this->e > temp.e;
    return this->s < temp.s;
  }
  COW(int s = 0, int e = 0, int posi = 0) : s(s), e(e), posi(posi) {}
} cow[maxx];

int tree[maxx];

void init_tree() {
  for (int i = 0; i < maxx; i++) {
    tree[i] = 0;
  }
}

void add_value(int val,int add_val = 1) {
  for (; val < maxx; val += (val & (-val)))
    tree[val] += add_val;
}

int check(int val) {
  int ans = 0;
  for (; val; val -= (val & (-val))) {
    ans += tree[val];
  }
  return ans;
}

int main() {
  int n;
  while (scanf("%d", &n) == 1 && n > 0) {
    init_tree();
    for (int i = 0; i < n; i++) {
      int temp[2];
      scanf("%d%d", &temp[0], &temp[1]);
      cow[i].s = temp[0] + 1;
      cow[i].e = temp[1] + 1;
      cow[i].posi = i;
    }
    sort(cow, cow + n);
    int qs = 0, qe = -1;
    for (int i = 0; i < n; i++) {
      qe = i;
      ans_cow[cow[i].posi] = check(cow[i].s);
      if (!(cow[i].s == cow[i + 1].s && cow[i].e == cow[i + 1].e)) {
        add_value(cow[i].s,qe - qs + 1);
        qs = i + 1;
      }
    }
    for (int i = 0; i < n; i++)
      printf("%d ", ans_cow[i]);
    printf("\n");
  }
  return 0;
}
