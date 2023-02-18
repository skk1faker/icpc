#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int maxx = 25;
vector<int> pile[maxx];
map<int, int> where_pile;
void re_back(int pile_posi, int aim_posi, int which_block) { // 归位
  if (pile_posi == aim_posi)
    return;
  int length = pile[pile_posi].size();
  for (vector<int>::reverse_iterator iter = pile[pile_posi].rbegin();
       iter != pile[pile_posi].rend(); iter++) {
    if (*iter == which_block)
      break;
    length--;
    pile[*iter].push_back(*iter);
    where_pile[*iter] = *iter;
  }
  pile[pile_posi].resize(length);
}
void move_pile(int move_posi, int aim_posi, int val) { // 移动
  if (move_posi == aim_posi)
    return;
  int length = pile[move_posi].size();
  vector<int> temp;
  for (vector<int>::reverse_iterator iter = pile[move_posi].rbegin();
       iter != pile[move_posi].rend(); iter++) {
    length--;
    temp.push_back(*iter);
    where_pile[*iter] = aim_posi;
    if (*iter == val)
      break;
  }
  pile[move_posi].resize(length);
  for (vector<int>::reverse_iterator iter = temp.rbegin(); iter != temp.rend(); iter++) {
    pile[aim_posi].push_back(*iter);
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    pile[i].push_back(i);
    where_pile[i] = i;
  }
  char input[1000];
  getchar();
  while (fgets(input, 1000, stdin) != 0) {
    if (input[0] == 'q')
      break;
    int a, b;
    char command[2][10];
    sscanf(input, "%s%d%s%d", command[0], &a, command[1], &b);
    if (command[0][0] == 'm') {
      if (command[1][1] == 'n') {
        re_back(where_pile[a], where_pile[b], a);
        re_back(where_pile[b], where_pile[a], b);
        move_pile(where_pile[a], where_pile[b], a);
      } else {
        re_back(where_pile[a], where_pile[b], a);
        move_pile(where_pile[a], where_pile[b], a);
      }
    } else {
      if (command[1][1] == 'n') {
        re_back(where_pile[b], where_pile[a], b);
        move_pile(where_pile[a], where_pile[b], a);
      } else {
        move_pile(where_pile[a], where_pile[b], a);
      }
    }
  }
  for (int i = 0; i < n; i++) {
    printf("%d:", i);
    for (vector<int>::iterator iter = pile[i].begin(); iter != pile[i].end();
         iter++)
      printf(" %d", *iter);
    printf("\n");
  }
  return 0;
}
