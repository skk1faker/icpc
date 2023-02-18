#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  vector<string> vec_str;
  while (scanf("%d", &n) == 1) {
    for(int i = 0;i <  60;i++)printf("-");printf("\n");
    vec_str.clear();
    string temp;
    int length = 0;
    for (int i = 0; i < n; i++) {
      cin >> temp;
      vec_str.push_back(temp);
      length = max(length, (int)(temp.length()));
    }
    sort(vec_str.begin(), vec_str.end());
    int col = (60 - length) / (length + 2) + 1;
    int row = (n + col - 1) / col;
    col = (n + row - 1) / row;
    int spare_length = 0;
    for (int i = 0; i < (col * row); i++) {
      int now_row = i / col;
      int now_col = i % col;
      int now_posi = now_row + now_col * row;
      if(now_posi < vec_str.size()){
        spare_length = length + 2 - vec_str[now_posi].length();
      cout<<vec_str[now_posi];
      }
      else spare_length = length + 2;
      if (i % col != col - 1) {
        while(spare_length--)printf(" ");
      } else {
        spare_length -= 2;
        while(spare_length--)printf(" ");
        printf("\n");
      }
    }
  }
}
