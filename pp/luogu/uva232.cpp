/*
输入一个r 行c 列(1<r,.c<10)
的网格，黑格用“*”每个白格都填有一个字母。如果一个白格的左边相邻位置或者上边相邻位置没有白格(可能是黑格，也可能出了网格边界)，则称这个白格是一个起始格
你的任务是找出网格中所有所有横向单词(Across)。.这些单词必须从一个起始格(左边是黑格，或是第一列)
开始，向右延伸到一个黑格的左边或者整个网格的最右列。然后找出所有竖向单词(Down)。
这些单词必须从一个起始格(上边是黑格，或是第一行)
开始，向下延伸到一个黑格的上边或者整个网格的最下行。 输入:
有多个矩阵输入，每一个矩阵都是以RC 开始(1<r,c<10)，表示R 行C
列，然后下面紧跟着一个R 行C 列的矩阵，里面全部是大写字母或是*，以,C
代表所有矩阵输入结束。
*/

#include <algorithm>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

char map[10][10];
vector<pair<int, string>> ans_list;
int num[10][10];
int main() {
  int m, n; //  m行，n列
  int Case = 1;
  while (scanf("%d", &m) && m != 0) {
    if(Case != 1)printf("\n");
    printf("puzzle #%d:\n",Case++);
    memset(num, 0, sizeof(num));
    scanf("%d", &n);
    for (int i = 0; i < m; i++) {
      scanf("%s", map[i]);
    }
    int temp_num = 0;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (((i - 1 >= 0 && map[i - 1][j] == '*') ||
             (j - 1 >= 0 && map[i][j - 1] == '*') || i == 0 || j == 0) &&
            map[i][j] != '*') {
          num[i][j] = ++temp_num;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int ans_num = 0;
      string ans = "";
      for (int j = 0; j < n; j++) {
        if (map[i][j] == '*') {
          if(ans_num != 0)ans_list.push_back(make_pair(ans_num, ans));
          ans_num = 0;
          ans = "";
        } else {
          if (ans_num == 0)
            ans_num = num[i][j];
          ans += map[i][j];
        }
      }
      if(ans_num != 0)ans_list.push_back(make_pair(ans_num, ans));
    }
    sort(ans_list.begin(), ans_list.end());
    printf("Across\n");
    for (vector<pair<int, string>>::iterator iter = ans_list.begin();
         iter != ans_list.end(); iter++) {
      printf("%3d.%s\n", iter->first, (char *)iter->second.data());
    }
    ans_list.clear();
    for (int i = 0; i < n; i++) {
      int ans_num = 0;
      string ans = "";
      for (int j = 0; j < m; j++) {
        if (map[j][i] == '*') {
          if(ans_num != 0)ans_list.push_back(make_pair(ans_num, ans));
          ans_num = 0;
          ans = "";
        } else {
          if (ans_num == 0)
            ans_num = num[j][i];
          ans += map[j][i];
        }
      }
      if(ans_num != 0)ans_list.push_back(make_pair(ans_num, ans));
    }
    printf("Down\n");
    sort(ans_list.begin(), ans_list.end());
    for (vector<pair<int, string>>::iterator iter = ans_list.begin();
         iter != ans_list.end(); iter++) {
      printf("%3d.%s\n", iter->first, (char *)iter->second.data());
    }
    ans_list.clear();
  }
  return 0;
}
