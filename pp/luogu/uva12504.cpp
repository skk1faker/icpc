#include <bits/stdc++.h>
#include <iterator>
#include <string>
using namespace std;

bool value_check(string a) { return true; }

bool key_check(string a) { return true; }

int main() {
  map<string, string> dict;
  set<string> add;
  set<string> change;
  int T;
  cin >> T;
  while (T--) {
    dict.clear();
    add.clear();
    change.clear();
    string input;
    int posi = 0;
    for (int mode = 0; mode <= 1; mode++) {
      cin >> input;
      input = input.substr(1, input.length() - 2);
      input += ',';
      while (posi < input.length()) {
        int posi_dot = input.find(",", posi);
        int posi_mao = input.find(":", posi);
        string key = input.substr(posi, posi_mao - posi);
        string value = input.substr(posi_mao + 1, posi_dot - (posi_mao + 1));
        if (key_check(key) && value_check(value)) {
          if (mode == 0)
            dict[key] = value;
          else {
            if (dict.count(key) == 0)
              add.insert(key);
            else if (dict.count(key) == 1) {
              if (dict[key] != value) {
                change.insert(key);
              }
              dict.erase(key);
            } else {
              add.insert(key);
            }
          }
        }
        posi = posi_dot + 1;
      }
    }
    int flag = 1;
    if (add.size() != 0) {
      printf("+");
      flag = 0;
      for (auto iter = add.begin(); iter != add.end(); iter++) {
        if (iter != add.begin())
          printf(",");
        cout << *iter;
      }
      cout << endl;
    }
    if (dict.size() != 0) {
      printf("-");
      flag = 0;
      for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        if (iter != dict.begin())
          printf(",");
        cout << iter->first;
      }
      cout << endl;
    }
    if (change.size() != 0) {
      printf("*");
      flag = 0;
      for (auto iter = change.begin(); iter != change.end(); iter++) {
        if (iter != change.begin())
          printf(",");
        cout << *iter;
      }
      cout << endl;
    }
    if (flag) {
      printf("No changes\n");
    }
  }
  return 0;
}
