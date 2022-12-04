#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
const int maxx = (int)4e5 + 10;
char input[maxx];
string S[maxx], T[maxx];

int main() {
  int h, w;
  scanf("%d%d", &h, &w);

  for (int i = 0; i < w; i++) {
    S[i] = "";
    T[i] = "";
  }
  for (int i = 0; i < h; i++) {
    scanf("%s", input);
    for (int j = 0; j < w; j++) {
      S[j] += input[j];
    }
  }
  sort(S, S + w);
  for (int i = 0; i < h; i++) {
    scanf("%s", input);
    for (int j = 0; j < w; j++) {
      T[j] += input[j];
    }
  }
  sort(T, T + w);
  for (int i = 0; i < w; i++) {
    if (S[i] != T[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
