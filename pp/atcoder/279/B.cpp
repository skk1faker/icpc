#include <iostream>
#include <string>
using namespace std;

int main() {
  string a, b;
  cin >> a;
  cin >> b;
  int i = 0, j = 0, flag = 0;
  if (a.length() >= b.length()) {
    while (i < a.size()) {
      if (a[i] == b[j]) {
        i++;
        j++;
      } else // if(a[i]!=b[j])
      {
        i++;
        j = 0;
      }
      if (j == b.size()) {
        flag = 1;
        break;
      }
    }
  }
  if (flag == 1)
    cout << "Yes";
  else
    cout << "No";
  return 0;
}
