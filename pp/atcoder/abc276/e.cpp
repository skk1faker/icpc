// 1. bfs
#include <cstring>
#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
const int maxx = (int)1e6 + 10;
bool vis[maxx];
char map_posi[maxx];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
class Posi {
private:
public:
  int po[2];
  static int h, w;
  bool OutRange() { return 0 <= po[0] && po[0] < h && 0 <= po[1] && po[1] < w; }
  int code() { return po[0] * w + po[1]; }
  Posi(int x = 0, int y = 0) {
    po[0] = x;
    po[1] = y;
  }
  bool operator==(Posi temp) {
    return this->po[0] == temp.po[0] && this->po[1] == temp.po[1];
  }
  void setpoval(int *dir) {
    po[0] += dir[0];
    po[1] += dir[1];
  }
};
class Solve {
public:
  Posi start_posi;
  int flag;
  bool dfs() { return dfs(start_posi, 0); }
  bool dfs(Posi now_posi, int n); // n is length
  Solve(int x, int y) : start_posi(x, y), flag(0){};
};
bool move(Posi &now_posi, int where) {
  Posi new_posi = now_posi;
  new_posi.setpoval(dir[where]);
  if (new_posi.OutRange()) {
    now_posi = new_posi;
    return true;
  } else
    return false;
}
bool Solve::dfs(Posi now_posi, int n) {
  if (now_posi == start_posi) {
    if (flag == 0)
      flag = 1;
    else if (n >= 4)
      return true;
  }
  if (vis[now_posi.code()] == 1)
    return false;
  if (map_posi[now_posi.code()] == '#')
    return false;
  vis[now_posi.code()] = 1;
  for (int i = 0; i < 4; i++) {
    Posi new_posi = now_posi;
    if (move(new_posi, i)) {
      if (dfs(new_posi, n + 1))
        return true;
    }
  }
  // vis[now_posi.code()] = 0;
  // NOTE:这里有一个证明优化
  // 首先我们假设地图中满足条件的路径点的集合为A
  // 首先我们假设仅有一条路径
  // 根据当前算法如果搜索的时候从某一时刻vis标记的路径不属于A，此处的搜索记为
  // 分支b，如果搜索过程中有碰到A的话，因为此时仅有一条路径，所以分支b不会到达
  // 终点，这个时候就会回退到分支开始的位置，如果此时在沿着答案路径搜索的话，
  // 因为之前A被搜索到了，vis记录之后dfs不会在搜索，可能会导致程序无法继续搜索
  // 但是。。。实际上上面的假设是有问题的
  // 因为如果仅存在一条路径的话那么分支可以通过替换算为第二条路径，与原假设不符
  // 所以分支一定不会到达A。
  //
  // 那么假设有多条路径，证明方法还是一样，
  // 假设所有答案的路径集合为A
  // 搜索的过程中出现不属于A的分支b
  // 分支b经过了A中元素，如果分支b可以到达终点则问题解决，如果没有到达则会回退
  // 如果算法在接下来的搜索中不会经过分支b于A的交集，那么则可以搜索到终点
  // 否则可能不会
  // 但是，由于分支b与A相连，我们可以通过替换的方法将分支b中元素转化为A中元素，
  // 这与假设中A包含了所有答案路径的点相矛盾
  // 所以分支不会经过A
  //
  //
  // 简单来说就是
  // 所有答案的路径为集合A
  // 搜索中非A的路径记为分支b
  // 分支b与A相交则会产生矛盾，即A没有包括所有答案的路径，分支b可通过替换变为A中元素
  // 所以分支b不会与A相交
  //
  // 不与A相交，dfs算法就可以找到答案（证明方法不清楚，，，，这个再往下我不想想了）
  return false;
}
int Posi::h = 0;
int Posi::w = 0;
int main() {
  int h, w;
  scanf("%d%d", &Posi::h, &Posi::w);
  getchar();
  h = Posi::h;
  w = Posi::w;
  for (int i = 0; i < Posi::h; i++) {
    scanf("%s", map_posi + i * w);
  }
  for (int i = 0; i < h * w; i++) {
    if (map_posi[i] == 'S') {
      Solve s(i / w, i % w);
      if (s.dfs())
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
      break;
    }
  }
}
