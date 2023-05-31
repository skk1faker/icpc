#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>
#include <cstdio>
#include <sys/types.h>
#define DEBUG 0
using namespace std;

map<int, map<string, set<int>>> paper_word_line;
map<int, set<int>> paper_line;
map<int, string> line_num_string;

int init() {
  int n;
  cin >> n;
  getchar();
  char str[81], str_word[81];

  int line_num = 0;
  int paper_num = 1;

  while (n--) {
    while (1) {
      char *ret = fgets(str, 80, stdin);
      if (ret[0] == '*') {
        paper_num++;
        break;
      }
      line_num++;
      paper_line[paper_num].insert(line_num);
      while (sscanf(ret, "%s", str_word) == 1) {
        ret += strlen(str_word);
        int i = strlen(str_word) - 1;
        while (!isalpha(str_word[i]))
          str_word[i--] = 0;
        i = 0;
        while (str_word[i]) {
          str_word[i] = tolower(str_word[i]);
          i++;
        }
        while (ret[0] != 0 && !isalpha(ret[0]))
          ret++;
        paper_word_line[paper_num][str_word].insert(line_num);
        if (DEBUG)
          printf("%s %d\n", str_word, (int)strlen(str_word));
        line_num_string[line_num] = str;
        if (DEBUG)
          printf("%s",line_num_string[line_num].c_str());
      }
    }
  }
  // printf("paper_num = %d\n",paper_num - 1);
  return paper_num - 1;
}

void parser(int paper_num, char *str1, char *str2, int order) {

  int output_num = 0;
  switch (order) {
  case 0: {
    for (int i = 1; i <= paper_num; i++) {
      if (paper_word_line[i][str1].size() > 0) {
        output_num++;
        if (output_num > 1)
          printf("----------\n");
      }
      for (set<int>::iterator iter = paper_word_line[i][str1].begin();
           iter != paper_word_line[i][str1].end(); iter++) {
        printf("%s",line_num_string[*iter].c_str());
      }
    }
    break;
  }
  case 1: {

    for (int i = 1; i <= paper_num; i++) {
      set<int> ans;
      if (paper_word_line[i][str1].size() == 0 ||
          paper_word_line[i][str2].size() == 0)
        continue;
      // cout<<paper_word_line[i][str2].size()<<endl;
      set_union(paper_word_line[i][str1].begin(),
                paper_word_line[i][str1].end(),
                paper_word_line[i][str2].begin(),
                paper_word_line[i][str2].end(), inserter(ans, ans.begin()));
      if (ans.size() > 0) {
        if (output_num >= 1) {
          printf("----------\n");
        }
        output_num++;
      } else
        continue;
      for (set<int>::iterator iter = ans.begin(); iter != ans.end(); iter++) {
        printf("%s",line_num_string[*iter].c_str());
      }
    }
    break;
  }
  case 2: {
    for (int i = 1; i <= paper_num; i++) {
      set<int> ans;
      set_union(paper_word_line[i][str1].begin(),
                paper_word_line[i][str1].end(),
                paper_word_line[i][str2].begin(),
                paper_word_line[i][str2].end(), inserter(ans, ans.begin()));
      if (ans.size() == 0)
        continue;
      if (output_num > 0)
        printf("----------\n");
      output_num++;
      for(set<int>::iterator iter = ans.begin();iter != ans.end();iter++){
        printf("%s",line_num_string[*iter].c_str());
      }
    }
  } break;

  case 3: {
    for(int i =1 ;i <= paper_num;i++){
      if(paper_word_line[i][str1].size() != 0)continue;
      if(output_num > 0)printf("----------\n");
      output_num ++;
      for(set<int>::iterator iter = paper_line[i].begin();iter != paper_line[i].end();iter++){
        printf("%s",line_num_string[*iter].c_str());
      }
    }
  } break;
  }
  if (output_num == 0)
    printf("Sorry, I found nothing.\n");
  printf("==========\n");
}

void solve(int paper_num) {
  char order[81];
  fgets(order, 80, stdin);
  char str1[81], oper[5], str2[81];
  int i = 0;
  int mode = 0;
  while (order[i] && mode == 0) {
    if (order[i] == 'A') {
      mode = 1;
    } else if (order[i] == 'O') {
      mode = 2;
    } else if (order[i] == 'N') {
      mode = 3;
    }
    i++;
  }
  switch (mode) {
  case 0:
    sscanf(order, "%s", str1);
    break;
  case 1:
    sscanf(order, "%s%s%s", str1, oper, str2);
    break;
  case 2:
    sscanf(order, "%s%s%s", str1, oper, str2);
    break;
  case 3:
    sscanf(order, "%s%s", oper, str1);
    break;
  }
  parser(paper_num, str1, str2, mode);
}

int main() {
  int page_num = init();
  int n = 0;
  cin >> n;
  getchar();
  while (n--) {
    solve(page_num);
  }
  return 0;
}
