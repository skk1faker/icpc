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
  int n,m;
  int a,b,c;
  n = rand() % 100 + 1;
  m = rand() % (n * 10) + 1;
  n = 100000;
  m = 200000;
  printf("%d %d\n",n,m);
  for(int i =0 ;i < m;i++){
    int temp = rand()%n +1;
    int temp_2 = rand()%n +1;
    int temp_3 = rand()%((int)1e9) +1;
    printf("%d %d %d\n",temp,temp_2,temp_3);
  }

}
