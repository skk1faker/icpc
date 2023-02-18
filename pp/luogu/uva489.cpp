#include <cstring>
#include <iostream>
using namespace std;
int num[26];
int vis[26];
int main() {
  int Case;
  char input[10000];
  while (scanf("%d", &Case) == 1 && Case != -1) {
    memset(num, 0, sizeof(num));
    memset(vis,0,sizeof(vis));
    printf("Round %d\n",Case);
    scanf("%s", input);
    for (int i = 0; input[i] != 0; i++)
      num[input[i] - 'a'] = 1;
    int sum_char = 0;
    for (int i = 0; i < 26; i++)
      sum_char += num[i];

    scanf("%s", input);
    //printf("%s\n",input);
    int ans = 0;
    for (int i = 0; input[i] != 0; i++) {
      if(vis[input[i] - 'a'] == 1)continue;
      if (num[input[i] - 'a'] == 1) {
        num[input[i] - 'a'] = 0;
        vis[input[i] - 'a'] = 1;
        sum_char--;
        if(sum_char == 0)break;
      } else {
        if(vis[input[i] - 'a'] == 0)
          vis[input[i] - 'a'] = 1;
        ans++;
        if (ans == 7)
          break;
      }
    }
    if (ans == 7) {
      cout << "You lose." << endl;
    } else {
      if (sum_char == 0) {
        cout << "You win." << endl;
      } else {
        cout << "You chickened out." << endl;
      }
    }
  }

  return 0;
}
