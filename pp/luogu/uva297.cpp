#include <bits/stdc++.h>
#include <deque>
using namespace std;

int ma[26];
class Tree_node {
public:
  Tree_node(int color = 0);
  void dfs(const string &s);
  int count(int scale = 32);
  Tree_node *node[4];
  int color;
  static int num;
};

int Tree_node::num = 0;

void Tree_node::dfs(const string &s) {

  this->color = ma[s[num] - 'a'];
  if (this->color == 0) {
    for (int i = 0; i < 4; i++) {
      num++;
      node[i] = (Tree_node *)malloc(sizeof(Tree_node));
      node[i]->dfs(s);
    }
  }
}

Tree_node::Tree_node(int color) : color(color) { // -1 白， 0 灰， 1 黑
  memset(node, 0, sizeof(node));
}

void merge(Tree_node *&t1, Tree_node *&t2) {
  if(t1->color == t2->color){
    if(t1->color == 0){
      for(int i = 0;i < 4;i++)
        merge(t1->node[i], t2->node[i]);
    }
  }
  else if(t1->color < t2->color){
    free(t1);
    t1 = t2;
  }
}
int Tree_node::count(int scale) {
  int ans = 0;
  if (color == 0) {
    for (int i = 0; i < 4; i++) {
      ans += this->node[i]->count(scale / 2);
    }
  } else if (color == 1)
    ans = (scale * scale);
  return ans;
}
int main() {
  int T;
  ma['e' - 'a'] = -1;
  ma['p' - 'a'] = 0;
  ma['f' - 'a'] = 1;
  scanf("%d", &T);
  while (T--) {
    string a, b;
    Tree_node *a_tree, *b_tree;
    a_tree = (Tree_node *)malloc(sizeof(Tree_node));
    b_tree = (Tree_node *)malloc(sizeof(Tree_node));
    cin >> a;
    cin >> b;
    Tree_node::num = 0;
    a_tree->dfs(a);
    Tree_node::num = 0;
    b_tree->dfs(b);
    int ans = 0;

    merge(a_tree, b_tree);
    ans = a_tree->count();
    printf("There are %d black pixels.\n", a_tree->count());
  }
  return 0;
}
