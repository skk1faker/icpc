#include <algorithm>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
int maxx_val;
class Pizza {
public:
  void extend(int where) {
    int extend_dir[3][2] = {{-1, 1}, {1, 1}, {0, -2}}; // y *= -1;
    int label = 1;
    if ((((this->y % 3) + 3) % 3) == 1)
      label = 1;
    else
      label = -1;
    this->x += extend_dir[where][0];
    this->y += label * extend_dir[where][1];
  }
  Pizza(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
  void operator=(const Pizza &temp) {
    this->x = temp.x;
    this->y = temp.y;
  }
  bool operator<(const Pizza &temp) const {
    if (temp.x != this->x)
      return this->x < temp.x;
    return this->y < temp.y;
  }
  bool operator!=(const Pizza &temp) const {
    return !(this->x == temp.x && this->y == temp.y);
  }
  bool operator==(const Pizza &temp) const {
    return temp.x == this->x && temp.y == this->y;
  }
  void rotate() { // clock 60
    int ori_x = this->x, ori_y = this->y;
    this->x = (ori_x + ori_y) / 2;     // -1
    this->y = (ori_y - 3 * ori_x) / 2; // 4 - 2 * 3 / 2
  }
  void move(const Pizza &temp) {
    this->x -= temp.x - 1;
    this->y -= temp.y - 1;
    // 原点设置为1,1
  }
  bool is_positive() {
    int temp_y = this->y;
    temp_y = ((temp_y % 3) + 3) % 3;
    //cout<<"temp_y = "<<temp_y<<endl;
    return temp_y == 1;
  }
  int x, y;
};

class Status {
public:
  Status(Pizza *pizza_f = NULL, int n = 0) {
    for (int i = 0; i < 16; i++) {
      pizza[i].x = 0;
      pizza[i].y = 0;
    }
    if (n > 0) {
      for (int i = 0; i < n; i++) {
        pizza[i].x = pizza_f[i].x;
        pizza[i].y = pizza_f[i].y;
      }
      this->n = n;
    } else
      this->n = n;
  }
  void rotate() {
    for (int i = 0; i < this->n; i++)
      (this->pizza[i]).rotate();
  }
  bool operator<(const Status &temp) const {
    if (this->n != temp.n) {
      return this->n < temp.n;
    }
    for (int i = 0; i < this->n; i++) {
      if (this->pizza[i] != temp.pizza[i])
        return this->pizza[i] < temp.pizza[i];
    }
    return false;
  }
  /*
  bool operator==(const Status &temp) const {
    if (this->n != temp.n)
      return false;
    for (int i = 0; i < this->n; i++) {
      if (this->pizza[i] != temp.pizza[i])
        return false;
    }
    return true;
  }
  */
  void move_to(int which) {
    Pizza temp_pizza = pizza[which];
    for (int i = 0; i < this->n; i++)
      pizza[i].move(temp_pizza);
  }

  bool extend_successful(int posi, int dir) {
    this->n++;
    this->pizza[this->n - 1] = this->pizza[posi];
    this->pizza[this->n - 1].extend(dir);
    for (int i = 0; i < this->n - 1; i++) {
      if (this->pizza[i] == this->pizza[this->n - 1]) {
        delete_num();
        return false;
      }
    }
    return true;
  }
  void delete_num() {
    this->pizza[this->n - 1].x = 0;
    this->pizza[this->n - 1].y = 0;
    this->n--;
  }
  static bool find(Status temp) {
    sort(temp.pizza, temp.pizza + temp.n);
    if (pizza_status.count(temp) == 1) {
      return true;
    }
    // 插入整个群；
    for (int i = 0; i < 6; i++) { // 旋转
      temp.rotate();
      for (int j = 0; j < temp.n; j++) { // 坐标原点
        if (!temp.pizza[j].is_positive())
          continue;
        temp.move_to(j);
        insert_in_set(temp);
      }
    }
    return false;
  }
  static void insert_in_set(Status temp) {
    sort(temp.pizza, temp.pizza + temp.n);
    pizza_status.insert(temp);
  }

  Pizza pizza[16];
  static set<Status> pizza_status;
  int n;
};

set<Status> Status::pizza_status;
int ans[17];
void dfs(int n, Status status) {
  ans[n]++;
  if (n == maxx_val) {
    return;
  }
  for (int i = 0; i < n; i++) {   // 挨个展开
    for (int j = 0; j < 3; j++) { // 三个方向展开
      if (!status.extend_successful(i, j)) {
        continue;
      }
      if (Status::find(status)){
        //cout << status.n << endl;
        status.delete_num();
        continue; // 查到当前状态，不能展开
      }
      dfs(n + 1, status);
      status.delete_num();
    }
  }
}

int main() {
  /*
  Pizza pizza[16];
  pizza[0].x = 1;
  pizza[0].y = 1;
  Status st(pizza, 1);
  scanf("%d", &maxx_val);
  dfs(1, st);
  for (int i = 0; i <= maxx_val; i++) {
    printf("%d ", ans[i]);
  }
  */
  
  int ans_list[] = {0,1,1,1,4,6,19,43,120,307,866,2336,6588,18373,52119,147700,422016};

  int T,Case = 0;
  cin>>T;
  while(T--){
    int i;
    scanf("%d",&i);
    //printf("%d ", ans_list[i]);
    printf("Case #%d: %d\n",++Case,ans_list[i]);
  }

  return 0;
}
