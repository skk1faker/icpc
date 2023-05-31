#include <bits/stdc++.h>

using namespace std;

int main() {
  string s;
  set<string> se;
  while (cin >> s)
    se.insert(s);
  for(set<string>::iterator iter = se.begin();iter!=se.end();iter++){
    s = *iter;
    if(s.length() == 1)continue;
    for(int length = 1;length < s.length();length++){
      string sb[2];
      sb[0] = s.substr(0,length);
      sb[1] = s.substr(length,s.length() - length);
      if(se.count(sb[0]) == 1 && se.count(sb[1]) == 1){
        cout<<s<<endl;
        break;
      }
    }
  }
  return 0;
}
