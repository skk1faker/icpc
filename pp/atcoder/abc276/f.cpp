#include <iostream>
using namespace std;
const int maxx = (int)2e5 + 10;
const int MOD = 998244353;
long long btree[maxx][2];
void build_tree() {
  for (int i = 0; i < maxx; i++) {
    btree[i][0] = 0;
    btree[i][1] = 0;
  }
}
int low_bit(int val) {
  // return val - ((val - 1) & val);
  return val & (-val);
}
long long get_value(int posi, int kind) {
  long long ans = 0;
  while (posi != 0) {
    ans += btree[posi][kind];
    posi -= low_bit(posi);
  }
  return ans;
}
void add_value(int posi) {
  int val = posi;
  while (posi < maxx) {
    btree[posi][0] += 1;
    btree[posi][1] += val;
    posi += low_bit(posi);
  }
}
void extern_gcd(long long a, long long b, long long &ax,
                long long &bx) { // 用于获取逆元
  if (b == 0) {
    ax = 1;
    bx = 0; // 此时这个值为任意值
    return;
  }
  extern_gcd(b, a % b, bx, ax); // 这里的bx和ax的位置无所谓。
  bx = (bx - a / b * ax);
}
int main() {
  int n;
  scanf("%d", &n);
  long long ans = 0;
  long long now_sum = 0;
  for (int i = 0; i < n; i++) {
    int val;
    scanf("%d", &val);
    long long sum = 2 * (now_sum - get_value(val, 1) + get_value(val, 0) * val);
    long long i2_inv, mod_inv;
    extern_gcd(((long long)(i + 1) * (long long)(i + 1)), MOD, i2_inv,
               mod_inv); // 注意这里(i+1) * (i+1)超出了int范围
    while (i2_inv < 0)
      i2_inv += MOD;
    ans = (ans + val + sum) % MOD;
    cout << ((ans * i2_inv) % MOD + MOD) % MOD << endl; // 乘法逆元
    add_value(val);
    now_sum += val;
  }
  return 0;
}
