// https://blog.csdn.net/ZscDst/article/details/84960582
//理解本代码首先要理解一个证明

/*


对于本题目来说，dp的状态转移

一.第一段dp
	1. dp[i][j]表示一个空串经过粉刷(就是将一个区间变为同样字幕的多次操作)得到string[i:j](表示string中从i -- j的串)的最小操作量
	2. dp[i][j]中边缘的串可以是最先粉刷的,证明如下:
		已知dp[i][j]代表一类操作,这种操作数量是最小的,操作共有n个,粉刷最后一位j在第m次操作,假设这个操作是粉刷到k
		[.......aaaaa]
		[       ^   ^]
		[i      k   j]
		(1) 可以看到粉刷到k之后会将(1--(m-1))次操作在string(k -- j)的修改覆盖,也就是(1 -- (m - 1))的操作影响string(k -- j)的可以将操作范围缩小,例如一个操作修改了string(i -- k + 1),那么它可以将操作范围修改为string(i -- k - 1),经过修改之后,m操作和(1 -- (m - 1))操作互不相关,于是m可以提前到(1 -- (m - 1))操作前面.
		(2) 第一次执行将a从j刷到k的操作和第一次执行从j刷到i其实是一样的,因为执行完第一次操作之后,string(i -- k - 1)之间没有字符和有字符并不会阻止后面的操作,而当前操作又是最少的,所以第一此将a从j刷到i是可行的.同理第一次从i开始刷到j,都刷为string[i]也是可以的.
		(3) string[i - 1]在粉刷的时候可以是自己单独粉刷,也可以是和其他字符一起参与一次粉刷(这个字符一定是和string[i - 1]一样的),如果string[i - 1] == string[j]一起被粉刷的话那么最少操作次数一定是dp[i][j](注意条件,string(i - 1),string(j)同时被刷)因为刷完之后需要修改的部分和原先一样,所以操作数量依旧不变.
		由于dp[i - 1][j] 的下限为dp[i][j](如果dp[i - ][j]这个状态操作有比dp[i][j]数量还少的操作,那么我们可以执行dp[i - 1][j]的操作时在string(i-1)不进行操作上,这样dp[i][j]就会有更小的操作数量dp[i-1][j]),所以当string[i-1] == string[j]最小操作数量dp[i-1][j] == dp[i][j]
	3. 状态转移方程的建立
	状态转移方程有两种方式
	(方法1). 由于最开始可将串的边界刷出来，按照边界元素刷到的位置，且刷到的位置后续操作不会修改粉刷的边界.
		假设i可呢会刷到每一个位置k == [i,j]，如果这个位置string[k] != string[i],那么后续操作就会将其破坏，总会有一个边界m没有被破坏过，这样我们可以视为这次操作直接刷到m处，所以我们有这样的假设“刷完后的边界不会改变”，如果这个边界不会改，那么就会有string[i] == string[k],所以状态转移就是这样的

		dp[i][j] = dp[i+1][j] + 1;	//这个代表从i刷到i是先进行的
		for(int m = i+1;m < j;m++){
			// 求最小值的dp保证dp每个枚举的装态都是最小值
			if(string[m] == string[i])dp[i][j] = min(dp[i+1][m] + dp[m + 1][j] ,dp[i][j]);	
			// [i+1 -- m]后续不会被其他与破坏m的操作搭边，所以可将粉刷操作分为两段，每段都取最小值，此时的dp[i + 1][m] + 0 便是从[i -- m]的最小操作,可以说是dp[i][m],所以这里的操作也可为如下写法
			// if(srting[m] == string[i])dp[i][j] = min(dp[i][m] + dp[m+1][j], dp[i][j]); //此时dp[i][m] == dp[i + 1][m];
		}
		if(string[i] == string[j])dp[i][j] = dp[i + 1][j];

	(方法2). 按照是分段刷还是整体刷的方式刷出来
		dp[i][j]的最大值是dp[i + 1][j] + 1，这个是一个大概估计，dp[i + 1][j]执行完之后刷string[i].
		这种方式最好理解，对于从空串刷到string[i -- j]的操作整体刷的意思就是先从i刷到j然后在进行后续，当string[i] == string[j]的时候根据上面的结论2.（3）dp[i][j] == dp[i+1][j],当string[i] != string[j]的时候，由于string[j]一定会被重新刷的，所以最开始的将string[i]刷到j位置就毫无意义，这种时候就不时整段刷（当然我们也可以整段刷其他颜色的字符，但是整段刷其他颜色最后我们也要刷string[i]，所以这种也不是整段刷，由此可以知道整段刷的颜色只能是边界的颜色。）
		所以整段刷的条件只有在string[i] == string[j]才成里，其他条件最小操作一定是分段刷的。
		所以这里的初始化代码可以写为
		if(stirng[i] == string[j])dp[i][j] = dp[i+1][j]
		else dp[i][j] = dp[i+1][j] + 1	这个只是当前的最大值，string[i] != string[j]这种情况操作最小值一定是分段出现的
		分段刷的代码很好写，将分段点给出就可以了
		for(int k = i; k < j;k++)
			dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j])

		

二. 第二段dp
	现在的主要任务是计算从string_b变化到string的最小操作数！	
	ans[i]表示string_b[1 -- i]变到string[1 -- i]所需要的最小次数
	注意这段证明和上面的证明基本一致，
	（1）如果string_b[i] != string[i]一定会有将string_b[i]处的字符刷为string[i]的操作，可以证明这个操作可以放在第一位，假设达到ans[i]的最小操作的操作序列是[1--n]操作m为刷string[i]，其刷过的范围会让[1 -- m-1]的操作不好使，所以可以将前m - 1个操作的范围不要进入m操作的影响范围，这样的话m和[1 -- m-1]操作户不相干，所以可以将这个操作提到最前面，ans[i]所代表的操作就可以先刷string[i]起手，假设刷到k位置，如果后续操作将我们刷k给刷没了相当于前面的操作部分是无效的，这样我们可以找到一个边界，他没有被影响过再次定为k。
	[......bbbbbbbbbb] -> operate m
			.
			.
			.
	[......aaaabbbbbb] -> operate m+s
	[      k   m    j]
	操作m可以视为
	[..........bbbbbb]
	[..........m    j] -> 等效操作

	但是
	[......bbbbbbbbbb] -> operate m
			.
			.
			.
	[......bbaabbbbbb] -> operate m+s
	[      k   m    j]
	操作m不可以视为如下操作
	[..........bbbbbb]
	[..........m    j] -> 等效操作
	因为这个时候k处的b没有操作来刷了
	
	定好k之后我们就可以分段操作了，[i -- k-1]因为和原来的string_b一样，其变为string的操作是ans[i]，后面的[k -- j]先刷了string[j]，所以这已经将string_b[j]的大部分信息抹掉了，而这段操作和dp[k][j]是相似的，dp[k][j]可以先将[k--j]全部刷为string[j]，之后的最小操作为dp[k][j]，所以将某一部分刷为string[j]之后变为string[k -- j]的最小操作为dp[i][j]，故转移方程如下:

	ans[i] = dp[0][i];	// 表示string_b[0 -- i]都刷为string[i]的最小操作为dp[0][i],此是不用分段刷
	for(int k = 0;k < i;k++){
		ans[i] = min(ans[i],dp[k+1][i] + ans[k]);//分段操作
	}

	（2）string_b[i] == string[i] 因为ans[i]的操作下界就是ans[i - 1]所以如果存在一个操作使得ans[i] == ans[i - 1],那么这一定是最小值了！！

*/



#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
char a[MAXN], b[MAXN];
int dp[MAXN][MAXN], ans[MAXN];
int l[MAXN],r[MAXN];
int main()
{
    while (~scanf("%s%*c%s%*c", a, b))
    {
        int n = strlen(a);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        for (int len = 2; len <= n; len++)
        {

            for (int i = 0; i + len - 1 < n; i++)
             {
                int j = i + len - 1;
                dp[i][j] = dp[i + 1][j] + 1;   // dp[i][j]最大值，按照原来的理论，我可一将其首先string[i]给他刷到尾巴，但是并不会影响后续操作

                if(b[i] == b[j]) dp[i][j] = dp[i + 1][j];

                for (int k = i + 1; k <= j; k++)
                {
                    // if(b[i] == b[k])dp[i][j] = min(dp[i][j], dp[i + 1][k] + dp[k + 1][j] );		// i和某一个同值元素刷出来的区间边界点不会被其他操作给覆盖（如果被覆盖了，那么这个操作的区间可以缩短），这样的话我们就可一独立考虑
                    dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j]);
                }
            }
        }
        ans[0] = (a[0] != b[0]);
        for (int i = 1; i < n; i++)
        {
            ans[i] = dp[0][i];
            if (a[i] == b[i]) ans[i] = ans[i - 1];
            else
            {
                for (int j = 0; j < i; j++)
                {
                    ans[i] = min(ans[i], ans[j] + dp[j + 1][i]); 
                }
            }
        }
        printf("%d\n", ans[n - 1]);
    }
    return 0;
}
/*
zzzzzfzzzzz
abcdefedcba
abababababab
cdcdcdcdcdcd
*/
