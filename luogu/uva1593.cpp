#include <bits/stdc++.h>
#include <sstream>
using namespace std;
int main() {
  char input[190];
  vector<vector<string>> line_vec;
  vector<int> col_length;
  while (fgets(input, 190, stdin) != 0) {
    stringstream ss(input);
    string words;
    vector<string> line;
    int i = 0;
    while (ss >> words) {
      line.push_back(words);
      if (col_length.size() == i) {
        col_length.push_back(words.length());
      } else
        col_length[i] = max(col_length[i], (int)words.length());
      i++;
    }
    line_vec.push_back(line);
  }
  for (int i = 0; i < line_vec.size(); i++) {
    for (int j = 0; j < line_vec[i].size(); j++) {
      int add_length = col_length[j] + 1 - line_vec[i][j].length();
      cout << line_vec[i][j];
      if (j != line_vec[i].size() - 1)
        while (add_length--)
          cout << ' ';
      else
        cout << endl;
    }
  }
  return 0;
}
