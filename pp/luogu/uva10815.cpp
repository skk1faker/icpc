#include <iostream>
#include <set>
#include <sstream>
using namespace std;
int main() {
  string str;
  set<string> ans;
  while (cin >> str) {
    for (int i = 0; i < str.length(); i++) {
      if (isalpha(str[i])) {
        str[i] = tolower(str[i]);
      } else
        str[i] = ' ';
    }
    stringstream ss(str);
    while(ss >> str){
      ans.insert(str);
    }
  }
  for(set<string>::iterator iter = ans.begin();iter != ans.end();iter++){
    cout<< *iter << endl;
  }
  return 0;
}
