//not yeat
#include<iostream>
using namespace std;

const int maxx = 5000+10;
int mod = (int)1e9;
int f[maxx][maxx];
int g[maxx][maxx];
int letter[2][maxx];

void input_letter(int letter[],int &l){
    l = 0;
    char ch;
    do{
        do {
            ch = getchar();
        }while(!(ch == '.'||(ch<= 'Z'&&ch >= 'A')));
        if(ch == '.')break;
        l++;
        letter[l] = ch - 'A';   // 从1开始赋值
    }while(!(ch == '.'));
    return ;
}

void solve(int leter[][maxx]){
    int l1, l2;
    input_letter(letter[0], l1);
    input_letter(letter[1], l2);
    for(int i=0;i <= l1;i++)
        for(int j=0; j <= l2; j++)
            g[i][j] = 0;
    for(int i = 0; i <= l1; i++){
        f[i][0] = 0;
        g[i][0] = 1;
    }
    for(int i = 0; i <= l2; i++){
        f[0][i] = 0;
        g[0][i] = 1;    // 代表这时只用一种匹配方法，就是完全没有匹配！！！！（注意这样算一中方法哦！！）
    }
    for(int sum = 2; sum <= l1+l2; sum++ ){
        int i;
        if(sum -l2 < 1) i = 1;
        else i = sum -l2;
        for(;i<=l1;i++){
            int j = sum -i;
            if(j<1)break;
            //if(j>l2)continue;
            if(letter[0][i] == letter[1][j]){
                f[i][j] = f[i-1][j-1] + 1;
                g[i][j] += g[i-1][j-1];
                if(f[i][j] == f[i-1][j]) g[i][j] = (g[i][j] + g[i-1][j]) % mod ;     // 此时j一定进行了匹配
                if(f[i][j] == f[i][j-1]) g[i][j] = (g[i][j] + g[i][j-1]) % mod ;     // 此时i一定进行了匹配
            }
            else {
                f[i][j] = max(f[i-1][j],f[i][j-1]);
                if(f[i][j] == f[i-1][j])g[i][j] = (g[i][j] + g[i-1][j]) % mod;
                if(f[i][j] == f[i][j-1])g[i][j] = (g[i][j] + g[i][j-1]) % mod;
                if(f[i][j] == f[i-1][j-1] && f[i-1][j] == f[i][j-1])  g[i][j] = (g[i][j] - g[i-1][j-1]) % mod;
            }
        }
         
    }
    cout<<f[l1][l2]<<endl;
    cout<<g[l1][l2]<<endl;
}

int main()
{
    solve(letter);
    return 0;
}