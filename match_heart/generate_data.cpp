#include <iostream>
using namespace std;
bool justify(int i, int x[]) {
  for (int j = 0; j < i; j++) {
    if (x[i * 2] == x[j * 2] && x[i * 2 + 1] == x[j * 2 + 1])
      return false;
  }
  return true;
}
int main() {
  srand((int)time(0));
  long long temp = (rand() % ((long long )1e9 - 1))  * (long long)(1e3) + (rand() % (long long )1e3);
  printf("%lld",temp);
}
