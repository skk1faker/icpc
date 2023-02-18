#include <bits/stdc++.h>

using namespace std;
string getorder(string temp) {

  for (int i = 0; i < temp.size(); i++) {
    if (isalpha(temp[i])) {
      temp[i] = tolower(temp[i]);
    }
  }
  sort(temp.begin(), temp.end());
  return temp;
}
int main() {
  string temp;
  set<string> noorder;
  map<string, int> yesorder;
  while (cin >> temp) {
    if (temp == "#")
      break;
    noorder.insert(temp);
    temp = getorder(temp);
    yesorder[temp]++;
  }
  for (set<string>::iterator iter = noorder.begin();iter != noorder.end();iter++) {
    temp = getorder(*iter);
    if(yesorder[temp] == 1){
      cout<<*iter<<endl;
    }
  }
  return 0;
}
