//https://blog.csdn.net/m0_46222454/article/details/127372686?spm=1001.2101.3001.6650.1&utm_medium=distribute.pc_relevant.none-task-blog-2~default~AD_ESQUERY~yljh-1-127372686-blog-49078233.pc_relevant_3mothn_strategy_and_data_recovery&depth_1-utm_source=distribute.pc_relevant.none-task-blog-2~default~AD_ESQUERY~yljh-1-127372686-blog-49078233.pc_relevant_3mothn_strategy_and_data_recovery&utm_relevant_index=2 
// 1. 如何枚举路径不会导致重复
//每次枚举最后一个边
//o
//1.1 为何ℹ < lowbit(str)的点不能参与dp[str][？]的dp计算
//
//因为这会导致重复，一条边算多次
//
// 2. 为何答案计算出来的圈会要/2 
//
//因为与其殿相连的边有两个
// 3. 为什么答案计算过程中，只需要计算集合最小的位置作为起点，这样为什么可以。
//
// 因为如果不设置也行，只需要给dp多一个维度，dp[i][j][str]表示从i到j的路径，然后计算的时候直接计算dp[a][a][str],只需要计算str中独有的一个a就可以了，算其他的会导致重复（一个环被计算多次，一个环有多个点），我们发现为了避免重复，我们只需要计算环的一个起点，于是我们想可不可以将空间优化，将起始点固定。
