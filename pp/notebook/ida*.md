# ida*（加深迭代搜索）

主要是用于最短路的搜索，但是因为一些原因（如状态比较大，难以使用变量表示，bfs需要使用队列存储一对状态，这样bfs需要大量内存，但是dfs可以使用全局变量存储当前状态）不能使用bfs，而使用dfs，再使用过程中规定搜索深度，通过不断加大深度，然后进行搜索，

同时ida*也有一些剪枝的手段，使用当前距离 + 预测距离（**当前状态能达到最远状态**）< 目标距离进行剪枝





我： 

为什么用ida*不用bfs

chatgpt：

IDA*和BFS都是搜索算法，但是它们的运行方式和效率有所不同。

BFS是一种广度优先搜索算法，从起点开始逐层扩展搜索，直到找到目标节点或搜索完整个图。BFS的优点是能够找到最短路径，但是当搜索空间非常大时，需要存储所有已访问的节点，内存占用会很高。

IDA*（迭代加深A*）是一种启发式搜索算法，它结合了深度优先搜索和A*算法的思想。IDA*使用一个估价函数来评估每个节点的可能性，并在每次迭代中增加限制条件，直到找到目标节点。IDA*比BFS更节省内存，因为它只需要存储当前路径，而不是整个搜索空间。

因此，在搜索空间较大且内存受限的情况下，使用IDA*比BFS更有效。但是，在搜索空间相对较小且寻找最短路径的情况下，BFS更适合。



## 题目

https://www.luogu.com.cn/problem/UVA1374

```cpp
#include<bits/stdc++.h>
using namespace std;

//set<int> vis;
int val_get[20];
int n_val;
bool dfs(int finish,int need_finish, int now_val){
  if(finish == need_finish){
    return now_val == n_val;
  }
  int max_val = 0;
  val_get[finish] = now_val;
  for(int i = 0;i <= finish;i++){
    max_val = max(max_val,val_get[i]);
  }
  if((max_val) << (need_finish - finish) < n_val)return false;
  for(int i = 0;i <= finish;i++){
    if(dfs(finish + 1, need_finish, now_val + val_get[i]))return true;
    if(dfs(finish + 1, need_finish, abs(now_val - val_get[i])))return true;
  }
  return false;
}

int main()
{
  while(scanf("%d",&n_val) == 1 && n_val != 0){
    int ans = 0;
    for(ans;;ans++){
      if(dfs(0,ans, 1))break;
    }
    printf("%d\n",ans);
  }
  return 0;
}
```