0. 参考资料
	https://www.cnblogs.com/cilinmengye/p/16213283.html
假设源节点为s
1. bellman-ford是，共n个点，对所有边松弛（dist[father] + edge[father][son] < dist[son],此时更新dist[son]即可）n - 1次。dist[i]表示节点i到达源点的最短距离，假设dist[i]包含m条边，那么对所有边松弛后，包含m+1条边的最短路一定会产生。由于源点s到s需要0条边，且s到所有节点的最短路径中，每个最短路径最多包含n-1条边。于是经过n-1次所有边的松弛就会将s到所有点的最短路求解出来

2. SPFA是bellman-ford的优化，因为bellman对所有边进行松弛，dist[a]只会之间变小，但是有些节点的松弛没有必要的，例如，上一次dist[father]没有改变，因为dist[a]只会之间变小，dist[father] + edge[father][son] < dist[son] 是一定不会为真的，因为dist[father]没有改变，但是dist[son]只可能变小，father的所有边没有必要松弛。于是我们维护一个节点队列，队列中存储了dist发生改变的节点即可。

3. SPFA不能判断出来s无法到达的负环（这说明产生了一个森林）那么哦噢们一个森林一个森林判断即可！
SPFA判断节点入队次数（不是dist改变次数）入队n+1次就是有负环。（其实节点i入队一次对应到bellman中就是在一轮松弛所有边中节点i发生了改变（不是看改变次数），如果入队n - 1次说明对应到bellman中已经发生了n-1次所有边的松弛，再次入队就是有了负环，SPFA会在无法松弛的时候自动停止，而存在负环会无法停止）
4. bellamn算法最后需要用一个循环判断以下是否有负环，由负环的话结果不能使用。
