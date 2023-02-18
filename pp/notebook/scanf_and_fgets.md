<font size = 5>
# 字符串输入的一些问题

1. fgets(char \*ch, int n, FILE \*stream)
会向ch中写如n字节，其中第n个字节是0，就是字符串结束的标志。
一般在碰到换行符就会结束，换行符也会被读取进来，也就是说fgets读取的是一行，当然一行中最多能读取到n - 1个字符，第n个字符留到下一次读取。
```cpp

#include<iostream>
using namespace std;
const int maxx = 1000;
int main()
{
  char temp[maxx] = "asjfhasjhfjaskfhajk";
  fgets(temp,8,stdin); // 表示填充多少字符，最后一个位置填充为0，也就是最后字符串长度为n - 1, 读取一行，也就是说，碰到换行符号就结束了
  printf("%s\n",temp);
  scanf("%s",temp);
  printf("%s\n",temp);
  return 0;
}

/*
input :
1234567890
*/

/*
output
1234567
890
*/
```

2. scanf("%s",temp);
scanf对于字符串开头的空格，换行符并不将其读入到char \*，scanf碰到空格，换行符、EOF(文件结束符)就结束了，空格和换行符都不会从stdin中读取出来，如果想要读到这些字符，需要使用getchar再次将换行符、空格读出。
```cpp
#include<iostream>
using namespace std;
const int maxx = 1000;
int main()
{
  char temp[maxx] = "asjfhasjhfjaskfhajk";
  scanf("%s",temp);
  char ch = getchar();
  if(ch == '\n')printf("yes is '\\n'\n");
  else printf("not is '\\n'\n");
  scanf("%s",temp);
  ch = getchar();
  if(ch == ' ')printf("yes is ' '\n");
  else printf("not is ' '\n");
  return 0;
}

/*
input :
1234567890
bbbbbbbb ccccc
*/

/*
output
yes is '\n'
yes is ' '
*/

```
```cpp
#include<iostream>
using namespace std;
const int maxx = 1000;
int main()
{
  char temp[maxx] = "asjfhasjhfjaskfhajk";
  scanf("%s",temp);
  printf("%s",temp);
  scanf("%s",temp);
  printf("%s",temp);
  return 0;
}
/*
input
1234567890
               bbbbbbbb ccccc
*/

/*
output:
1234567890bbbbbbbb
*/
```
</font>

