#include<iostream>
using namespace std;

int ans[100];
int cnt;

void output(int length)
{
    for(int i = 0; i < length; i++){
        if((i + 1) % 4 != 0)printf("%c", ans[i] + 'A');
        else if((i + 1) % 4 == 0){
            if(i == length)printf("%c", ans[i] + 'A');
            else if((i + 1) % 64 == 0)printf("%c\n", ans[i] + 'A');
            else printf("%c ", ans[i] + 'A');
        }
    }
    cout<<endl<<length<<endl;
}

int dfs(int length, const int & n, const int & L)
{
    for(int i = 0; i < L; i++){
        ans[length] = i;
        int flag = 0;
        for(int test_length = 1; test_length <= (length + 1)/2; test_length++){ // 判断合法性
            flag = 0; 
            for(int l = 0; l < test_length; l++){
                if(ans[length - l] != ans[length - l - test_length]){
                    flag = 1;       //存在不相等！
                }
            }
            if(flag == 0){  // 存在相等字符串
                break;
            }
        }
        if((length + 1)/2 < 1) flag = 1;
        if(flag == 1){   // 可以书写，且此并非第n个答案
            cnt ++;
            // cout<<cnt<<endl;
            if(cnt < n){
                //进行递归
                if(dfs(length+1, n, L) == 1)return 1;
            }
            else if(cnt == n){
                output(length + 1);
                return 1;// 表示程序应该结束了
            }
        }
    }
    return 0;       // 表示还没有找到
}

int main()
{
    int n,L;
    while(scanf("%d%d",&n,&L) == 2){
        if(n == 0 && L == 0)break;
        cnt = 0;// 表示已经找到0个答案！
        dfs(0, n, L);
    }
    return 0;
}