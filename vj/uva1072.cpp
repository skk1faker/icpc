#include <cstring>
#include <iostream>
using namespace std;

const int maxx = 2 * 1024  *1024 + 20;
int tree[maxx];
int bfs_tree_node[maxx];
int val_tree[maxx];
int ans = 0;

void dfs(int finish_num, int all_posi) {
  if (finish_num == all_posi) {
    ans++;
    return;
  }
  int now_posi = bfs_tree_node[finish_num];
  int sp_val = val_tree[now_posi / 2];
  int last_val = val_tree[bfs_tree_node[finish_num - 1]];
  int lr = now_posi % 2; // 1表示右边，0表示左边
  if (lr == 1) { // 右边元素确定，左边元素也就确定了，这里先定右边的元素，
    for (int i = 1, j = sp_val - i; i <= j; i++, j--) {
      if(j > last_val)continue;
      // 1 <= i <= j <= last_val
      val_tree[now_posi] = j;
      val_tree[now_posi - 1] = i;
      dfs(finish_num + 1,all_posi);
    }
  } 
  else {
    dfs(finish_num + 1, all_posi);
  }
  return;
}

int main() {
  int n;
  int Case = 1;
  while (scanf("%d", &n) == 1 && n != 0) {
    ans = 0;
    memset(tree, 0, sizeof(tree));
    for (int i = 0; i < n; i++) {
      char temp[maxx];
      scanf("%s", temp);
      int root = 1;
      for (int j = 0; temp[j]; j++) {
        tree[root] = 1; //
        if (temp[j] == '1') {
          root = 2 * root + 1;
        } else {
          root = 2 * root;
        }
      }
      tree[root] = 2;
    }
    bfs_tree_node[0] = 1;
    int now_length = 1;
    int now_place = 0;
    while (now_place < now_length) {
      if (tree[bfs_tree_node[now_place]] == 1) {
        bfs_tree_node[now_length++] = 2 * bfs_tree_node[now_place] + 1;
        bfs_tree_node[now_length++] = 2 * bfs_tree_node[now_place];
      }
      now_place++;
    }
    val_tree[1] = 100;
    dfs(1, now_length);
    printf("Case %d: %d\n",Case++,ans);
  }

  return 0;
}
