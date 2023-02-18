#include <iostream>
using namespace std;
const long long maxx = 1001;
long long ip[maxx];
int main() {
  long long n;
  while (scanf("%lld", &n) == 1) {
    for (long long i = 0; i < n; i++) {
      ip[i] = 0;
      long long temp[4] = {0};
      scanf("%lld.%lld.%lld.%lld", &temp[0], &temp[1], &temp[2], &temp[3]);
      for (long long j = 0; j < 4; j++) {
        ip[i] *= 256;
        ip[i] += temp[j];
      }
    }
    long long max_length = 0;
    for (long long i = 0; i < n; i++) {
      long long val = ip[0] ^ ip[i];
      long long length = 0;
      while (val) {
        val /= 2;
        length++;
      }
      max_length = max(length, max_length);
    }
    // printf("%lld\n",max_length);
    long long mask = 0;
    for (long long i = 31; i >= 0; i--) {
      mask *= 2;
      mask += (i >= max_length);
    }
    long long ip_net = (ip[0] & mask);
    long long ans_ss[4];
    long long mask_ans[4];
    for (long long i = 3; i >= 0; i--) {
      ans_ss[i] = ip_net % 256;
      mask_ans[i] = mask % 256;
      mask /= 256;
      ip_net /= 256;
    }
    for (long long i = 0; i < 4; i++) {
      printf("%lld", ans_ss[i]);
      if (i != 3)
        printf(".");
      else
        printf("\n");
    }
    for (long long i = 0; i < 4; i++) {
      printf("%lld", mask_ans[i]);
      if (i != 3)
        printf(".");
      else
        printf("\n");
    }
  }
  return 0;
}
