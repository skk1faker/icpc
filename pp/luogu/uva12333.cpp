#include <bits/stdc++.h>
#include <math.h>
using namespace std;
const int maxx_bits = 60;
class node {

  node *next[10];
  int num;

public:
  node() {
    for (int i = 0; i < 10; i++)
      next[i] = nullptr;
    num = -1;
  }
  void insert(int *a, int posi, int val) {  // 从高位向低位插
    if (posi == -1)
      return;
    if(next[a[posi]] == nullptr){
      next[a[posi]] = new node;
    }
    if(next[a[posi]]->num == -1){
      next[a[posi]]->num = val;   // 多组前缀都要插入这个值
    }
    next[a[posi]]->insert(a,posi - 1,val);
  }
  int output(char *a,int posi){  //依旧是从数字的最高位开始查询，但是字符串中0位是最高位
    //if(posi == n){
    if(a[posi] == 0){
      return num;
    }
    if(next[a[posi] - '0'] == nullptr)return -1;
    return next[a[posi] - '0']->output(a,posi + 1);
  }
}dic_tree;

class bignum {
public:
  int num[maxx_bits];
  int length;
  bignum(int *a = NULL) {
    if (a == NULL){
      memset(num,0,sizeof(num));
      length = 0;
      return;
    }
    for (int i = 0; i < maxx_bits; i++)
      num[i] = a[i];
    length = 0;
  }
  bignum & operator = (const bignum &temp){
    for(int i = 0;i < maxx_bits;i++)num[i] = temp.num[i];
    length = temp.length;
    return *this;
  }
  void dis() {
    // 99999 + 99999 = 200000 - 2 = 199998
    // 就进了一位，所以我们每次加法最大进一位，退一位即可满足后续加法。
    // 三个数相加 数的范围为[0,1],[0,9],[0,9]三个数相加最大进位还是1.
    for (int i = 1; i < maxx_bits; i++)
      num[i - 1] = num[i];
    num[maxx_bits - 1] = 0;
    length--;
  }
  bignum operator+(bignum &a) 
  {
    bignum ans;
    if (num[maxx_bits - 1] != 0 || a.num[maxx_bits - 1] != 0)
      this->dis(), a.dis();
    int up = 0;
    for (int i = 0; i < maxx_bits; i++) {
      up = a.num[i] + num[i] + up;
      ans.num[i] = up % 10;
      up /= 10;
      if(ans.num[i]!=0)ans.length = i + 1;
    }
    return ans;
  }
};

int main() { 
  bignum a,b,c;
  a.num[0] = 1;
  a.length = 1;
  b.num[0] = 1;
  b.length = 1;

  dic_tree.insert(a.num,0,0);
  for(int i = 2;i < 100000;i++){
    c = a + b;  // F[i] = c;
    a = b;
    b = c;
    dic_tree.insert(c.num,c.length - 1,i);
  }
  int num_check;
  cin>>num_check;
  char number[50];
  for(int i = 1;i <= num_check;i++){
    scanf("%s",number);
    printf("Case #%d: %d\n",i,dic_tree.output(number, 0));
  }
  return 0; 

}
