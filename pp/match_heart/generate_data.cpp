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
  int n,k,d;
  n = rand() % 100 + 1;
  k = rand() % n + 1;
  d = rand() % 100;
  printf("%d %d %d\n",n,k,d);
  for(int i =0 ;i < n;i++){
    int temp = rand() % ((int)1e9 + 1);
    printf("%d ",temp);
  }

}
