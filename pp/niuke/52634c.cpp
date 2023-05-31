#include <bits/stdc++.h>
using namespace std;
const int maxx = (int)1e6 + 10;
int dfs_sort[maxx];
int tree_large[maxx];
set<pair<int, int>> ans;
int n;
using namespace std;
int dfs(int root_posi) {
  for (int i = root_posi + 1;
       i < root_posi + tree_large[dfs_sort[root_posi]] && i < n;
       i += tree_large[dfs_sort[i]]) {
    ans.insert(make_pair(min(dfs_sort[root_posi], dfs_sort[i]) + 1, max(dfs_sort[root_posi], dfs_sort[i]) + 1));
    dfs(i);
  }
  return root_posi;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++){
    scanf("%d", &dfs_sort[i]);
    dfs_sort[i]--;
  }
  for (int i = 0; i < n; i++)
    scanf("%d", &tree_large[i]);
  dfs(0);
  for (set<pair<int, int>>::iterator iter = ans.begin(); iter != ans.end();
       iter++)
    printf("%d %d\n", iter->first, iter->second);
  return 0;
}
