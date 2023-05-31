#include <bits/stdc++.h>

using namespace std;

const int maxx = 1030;
char str[maxx];

void back(int l, int r) {
  if(l > r)return;
  if(l == r){
    if(str[l] == '0')cout<<'B';
  else cout<<'I';
      return;
  }
  int sum = 0;
  int mid = (l + r) / 2;
  back(l,mid);
  back(mid + 1,r);
  for (int i = l; i <= r; i++) {
    sum += str[i] - '0';
  }
  if (sum == 0) {
    cout << 'B';
  } else if (sum == (r - l + 1)) {
    cout << 'I';
  } else
    cout << 'F';
}

int main()
{
  int n,length = 1;
  cin>>n;
  scanf("%s",str);
  length = strlen(str);
  back(0,length - 1);
}
