#include <cstring>
#include <iostream>
using namespace std;
const int maxx = (int)85 * 2;
char temp[maxx];
char temp_2[maxx];
double weight[27];
char name[4] = {'C', 'H', 'O', 'N'};
double weight_name[4] = {12.01, 1.008, 16.00, 14.01};
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 4; i++)
    weight[name[i] - 'A'] = weight_name[i];
  while (n--) {
    scanf("%s", temp_2);
    int now_posi = 0;
    for (int i = 0; temp_2[i]; i++) { // 首先进行格式转换
      temp[now_posi++] = temp_2[i];
      if (isalpha(temp_2[i]) && (isalpha(temp_2[i + 1]) || temp_2[i + 1] == 0))
        temp[now_posi++] = '1';
      temp[now_posi] = 0;
    }
    // printf("%s %d\n",temp,strlen(temp));
    double ans = 0;
    double temp_ans = 0;
    double weight_single_ele = 0;
    for (int i = 0; temp[i]; i++) {
      if (isdigit(temp[i])) {
        temp_ans *= 10;
        temp_ans += (temp[i] - '0') * weight_single_ele;
      } else {
        ans += temp_ans;
        temp_ans = 0;
        weight_single_ele = weight[temp[i] - 'A'];
      }
    }
    printf("%.3lf\n", ans + temp_ans);
  }
  return 0;
}
