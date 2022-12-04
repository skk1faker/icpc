#include <iostream>
#include <map>
using namespace std;

int main() {
  long long K = 1;
  map<long long, long long> check;
  long long ans = 0;
  scanf("%lld", &K);
  long long N = K;
  for (long long i = 2; i * i <= N; i++) {
    if (N % i == 0) {
      if(check.count(i) == 0)check[i] = 0;
      while (N % i == 0) {
        N /= i;
        check[i]++;
      }
    }
  }
  if (N != 1) {
    if(check.count(N) == 0)check[N] = 0;
    check[N]++;
  }
  for (map<long long, long long>::iterator iter = check.begin();
       iter != check.end(); iter++) {
    for (long long i = iter->first; iter->second; i += iter->first) {
      long long temp = i;
      ans = max(ans, i);
      for (long long j = 2; j * j <= temp; j++) {
        while (temp % j == 0) {
          if (check.count(j) == 1 && check[j] > 0) {
            check[j]--;
          }
          temp /= j;
        }
      }
      if (temp != 1) {
        if (check.count(temp) == 1 && check[temp] > 0) {
          check[temp]--;
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}

