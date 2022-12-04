#include <iostream>
#include <math.h>
using namespace std;
int main() {

  double A, B;
  scanf("%lf%lf", &A, &B);
  double x = pow(A / (2 * B), 2.0 / 3.0) - 1;
  long long xup = ceil(x), xdown = floor(x);
  double ans = A;
  if (xup >= 0) {
    ans = min(ans, B * xup + A / (sqrt(xup + 1)));
  }
  if (xdown >= 0) {
    ans = min(ans, B * xdown + A / (sqrt(xdown + 1)));
  }
  printf("%0.10lf\n",ans);
  return 0;
}
