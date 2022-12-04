/* 首先需要建立坐标系，这个坐标系能唯一的确定一个三角形，如下所示
 * 我真的不知道作者怎么能设计出这样一个坐标系！！！！日！
 */

/*
 * 将查找到的图案通过旋转然后使用hash记录，如果只通过交换坐标值来进行旋转（就是x，y，z轴互换）注意000旋转之后还是000，所以我们是绕着000进行旋转。
 */
#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#define make_table 0
using namespace std;
const int maxx = 18;
class Triangle {
private:
  int x[3]; // 任意一个值只有8种可能（-4，-3， -2，-1，0，1，2，3）

public:
  Triangle(int x = 0, int y = 0, int z = 0) {
    this->x[0] = x;
    this->x[1] = y;
    this->x[2] = z;
  }
  bool operator==(const Triangle &temp) const {
    for (int i = 0; i < 3; i++) {
      if (this->x[i] != temp.x[i])
        return false;
    }
    return true;
  }
  void extend(int edge) {
    int d_val = ((x[0] + x[1] + x[2]) == 0) ? 1 : -1;
    for (int i = 0; i < 3; i++) {
      if (i == edge)
        continue;
      x[i] += d_val;
    }
  };
  void rotate_180() { // 绕着0，0，0的底边中(0, 0.5, 0.5)点进行旋转
    x[0] = -x[0];
    x[1] = 1 - x[1];
    x[2] = 1 - x[2];
  }
  void rotate_120() {
    int temp = x[0];
    x[0] = x[1];
    x[1] = x[2];
    x[2] = temp;
  }
  void moveto(int *x_) {
    for (int i = 0; i < 3; i++) {
      x[i] -= x_[i];
    }
  }
  void get_x(int *x_) {
    for (int i = 0; i < 3; i++) {
      x_[i] = x[i];
    }
  }
  int get_sum() { return x[0] + x[1] + x[2]; }
  void rotate() {
    rotate_180();
    rotate_120();
  }
  int get_key() {
    int key = 0;
    key += (x[0] + 8) << 8;
    key += (x[1] + 8) << 4;
    key += (x[2] + 8);
    return key;
  }
};

class Pizza {
private:
  Triangle pizza[maxx];
  int cnt;

public:
  Triangle get_pizza(int posi) { return pizza[posi]; }
  Pizza() { cnt = 0; }
  void add_triangle(Triangle temp_t) {
    pizza[cnt] = temp_t;
    cnt++;
  }
  bool extend(int posi, int edge) { // 扩展cnt指向的最后一个文件的三角形
    add_triangle(pizza[posi]);
    pizza[cnt - 1].extend(edge);
    for (int i = 0; i < cnt - 1; i++) {
      if (pizza[i] == pizza[cnt - 1])
        return false;
    }
    return true;
  }
  void remove() { cnt--; }
  int getcnt() { return cnt; }

  void move_to_ori(int posi) {
    int x_temp[3];
    pizza[posi].get_x(x_temp);
    for (int i = 0; i < cnt; i++) {
      pizza[i].moveto(x_temp);
    }
  }; // TODO : 参数？
  void rotate() {
    for (int i = 0; i < cnt; i++) {
      pizza[i].rotate();
    }
  }; // 旋转60C
  int get_key(int posi) { return pizza[posi].get_key(); };
};
vector<Pizza> ans_pizza[maxx];

class Hash {
private:
  int keys[maxx], cnt;

public:
  bool operator<(const Hash &other) const {
    if (this->cnt != other.cnt)
      return this->cnt < other.cnt;
    for (int i = 0; i < cnt; i++) {
      if (this->keys[i] != other.keys[i])
        return this->keys[i] < other.keys[i];
    }
    // return true;  //TODO: why?
    return false; //
  }
  bool operator==(const Hash &other) const {
    if (this->cnt != other.cnt)
      return false;
    for (int i = 0; i < cnt; i++) {
      if (this->keys[i] != other.keys[i])
        return false;
    }
    return true;
  }
  Hash(Pizza pizza) {
    cnt = pizza.getcnt();
    for (int i = 0; i < cnt; i++) {
      keys[i] = pizza.get_key(i);
    }
    for (int i = cnt; i < maxx; i++)
      keys[i] = 0;
    sort(keys, keys + cnt);
  }
};

set<Hash> vis;

bool search_and_insert(Pizza ori_pizza) {
  // find, move, rotate, find ,move,rotate
  Hash hash_pizza_temp(ori_pizza); // hash_pizza有序集合
  if (vis.find(hash_pizza_temp) != vis.end())
    return true;
  // 加入ori_pizza的同族
  int cnt = ori_pizza.getcnt();
  for (int i = 0; i < 6; i++) {     // rotate enum
    for (int j = 0; j < cnt; j++) { // move enum
      if (ori_pizza.get_pizza(j).get_sum() != 0)
        continue;
      ori_pizza.move_to_ori(j);
      Hash hash_pizza(ori_pizza); // hash_pizza有序集合
      if (vis.find(hash_pizza) == vis.end())
        vis.insert(hash_pizza);
    }
    ori_pizza.rotate(); // 旋转60度
  }
  return false;
}

int ans[maxx];
void dfs(Pizza now_pizza) {
  // 1. extend pizza
  if (now_pizza.getcnt() == 16) {
    ans[now_pizza.getcnt()]++;
    return;
  }
  ans[now_pizza.getcnt()]++;
  ans_pizza[now_pizza.getcnt()].push_back(now_pizza);
  for (int j = 0; j < now_pizza.getcnt(); j++) {
    for (int i = 0; i < 3; i++) { // 三个扩展方向
      if (!now_pizza.extend(j, i)) {
        now_pizza.remove();
        continue;
      }
      if (search_and_insert(now_pizza)) {
        now_pizza.remove();
        continue;
      }
      dfs(now_pizza);
      now_pizza.remove();
    }
  }
}
int output[] = {0,1,1,1,4,6,19,43,120,307,866,2336,6588,18373,52119,147700,422016};
int main() {
  if (make_table) {
    Pizza st_pizza;
    Triangle ori_triangle;
    st_pizza.add_triangle(ori_triangle); //
    dfs(st_pizza);
    for (int i = 1; i < maxx; i++)
      cout << ans[i] << endl;
  } else {
    int n;
    int Case = 0;
    scanf("%d", &n);
    while (n--) {
      int temp;
      scanf("%d", &temp);
      printf("Case #%d: %d\n", ++Case, output[temp]);
    }
  }

  return 0;
}
