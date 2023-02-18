// https://blog.csdn.net/bigdata_lijun/article/details/11101455?spm=1001.2101.3001.6650.2&utm_medium=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7Edefault-2-11101455-blog-111239493.pc_relevant_landingrelevant&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2%7Edefault%7EOPENSEARCH%7Edefault-2-11101455-blog-111239493.pc_relevant_landingrelevant&utm_relevant_index=3
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int maxn = 22;
const int maxways = 30000;
int n, i, j, new_tot, nodes, last, node, cases, ans[maxways][maxn],
    new_ans[maxways][maxn];
int l[maxn * 2], r[maxn * 2], step[maxn];
char a[maxn];

void split(int node) {
  int i, j, k, f;
  new_tot = 0;
  for (i = 0; ans[i][0]; i++) {
    f = ans[i][node];       // 需要拆分的点
    for (j = f - 1; j > (f - 1) / 2; j--)
      if (j <= ans[i][nodes]) {
        for (k = 0; k < nodes; k++) {
          if (k >= node){
            new_ans[new_tot][k] = ans[i][k + 1];
          }
          else
            new_ans[new_tot][k] = ans[i][k];
        }
        new_ans[new_tot][k] = j;
        new_ans[new_tot++][k + 1] = f - j;
      }
  }
  nodes++;    // 当前还有多少节点
  memcpy(ans, new_ans, new_tot * maxn * 4);
  ans[new_tot][0] = 0;
}

int main() {
  while (scanf("%d", &n) && n) {
    memset(l, 0, sizeof(l));
    memset(r, 0, sizeof(r));
    last = 0;
    for (i = 0; i < n; i++) {
      scanf(" %s", a);
      node = 0;
      for (j = 0; a[j]; j++)
        if (a[j] == '0') {
          if (!l[node]) {
            l[node] = ++last;
            r[node] = ++last;
          }
          node = l[node];
        } else {
          if (!r[node]) {
            l[node] = ++last;
            r[node] = ++last;
          }
          node = r[node];
        }
    }
    i = 0;
    j = 0;
    node = 0;
    nodes = 0;
    ans[0][0] = 100;
    ans[1][0] = 0;
    while (i <= j) {
      if (l[step[i]]) {   // bfs 遍历 l[] != 0 表示step[i]不是叶节点
        split(node);      //  参与分裂的节点
        step[++j] = r[step[i]];     // 从大的开始
        step[++j] = l[step[i]];     // 然后遍历小的
      } else
        node++;     // 遇到叶节点记录，下一次遍历
      i++;
    }
    printf("Case %d: %d\n", ++cases, new_tot);
  }
  return 0;
}
/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
/*
#include <bits/stdc++.h>
#define rb(a, b, c) for (int a = b; a <= c; ++a)
#define rl(a, b, c) for (int a = b; a >= c; --a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a, b) make_pair(a, b)
#define FIR first
#define SEC second
#define FREO freopen("check.out", "w", stdout)
#define rep(a, b) for (int a = 0; a < b; ++a)
#define SRAND                                                                  \
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng() % a
#define ALL(a) a.begin(), a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a, b) a = min(a, b)
#define check_max(a, b) a = max(a, b)
using namespace std;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> mp;
int n;
int answer = 0;
int fa[55];
int val[55];
int N = 0;
int is[22];
int label[55];
int son[55][2];
int oldson[55][2];
void dfs(int now, int rest, int have = 1) {
  if (now == N + 1) {
    answer++;
    return;
  }
  if (son[now][0]) {
    val[now] = val[son[now][0]] + val[son[now][1]];
    if (val[now] < val[now - 1])
      return;
    dfs(now + 1, rest, have);
  } else {
    rb(i, max(1, val[now - 1]), rest) {
      if (have == n) {
        i = rest;
      }
      val[now] = i;
      if (i * (n - have) <= (rest - i))
        dfs(now + 1, rest - i, have + 1);
    }
  }
}
int insert(string &s, int pos, int now = 0) {
  if (pos == s.length())
    return now;
  if (s[pos] == '0') {
    if (!son[now][0])
      son[now][0] = ++N, fa[N] = now;
    return insert(s, pos + 1, son[now][0]);
  }
  if (!son[now][1])
    son[now][1] = ++N, fa[N] = now;
  return insert(s, pos + 1, son[now][1]);
}
void Label(int now, int depth, int target) {
  if (target == depth) {
    label[now] = ++N;
    return;
  }
  if (son[now][0]) {
    Label(son[now][0], depth + 1, target);
  }
  if (son[now][1]) {
    Label(son[now][1], depth + 1, target);
  }
}
bool cmp(int A, int B) { return label[A] < label[B]; }
int main() {
  int T = 0;
  while (true) {
    N = 0;
    memset(son, 0, sizeof(son));
    memset(val, 0, sizeof(val));
    scanf("%d", &n);
    if (!n)
      break;
    rb(i, 1, n) {
      string s;
      cin >> s;
      is[i] = insert(s, 0);
    }
    N = 0;
    rl(i, n + 2, 1) { Label(0, 1, i); }
    sort(is + 1, is + 1 + n, cmp);
    answer = 0;
    rb(i, 0, N - 1) oldson[i][0] = son[i][0], oldson[i][1] = son[i][1];
    rb(i, 0, N - 1) {
      if (oldson[i][0])
        son[label[i]][0] = label[oldson[i][0]];
      else
        son[label[i]][0] = 0;
      if (oldson[i][1])
        son[label[i]][1] = label[oldson[i][1]];
      else
        son[label[i]][1] = 0;
    }
    dfs(1, 100);
    printf("Case %d: %d\n", ++T, answer);
  }
  return 0;
}
*
*/
