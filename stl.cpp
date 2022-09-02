//安装libpcap的方法
//https://www.csdn.net/tags/MtTaEg5sNTYwMDgtYmxvZwO0O0OO0O0O.html

#include<iostream>
#include<cstdio>

using namespace std;

int dir_move[5][2] = {{1,0},{-1,0},{0,1},{0,-1},{0,0}};
int main()
{
    int a = 1;
    int b = 1;
    int c = 1;
    for(int i = 0;i<5;i++){
        cout<<dir_move[i][0]<<' '<<dir_move[i][1]<<endl;
    }
    double d = -1.0 * c / (a - b);
    double e = 2.0 * c / (a - b);
    cout<<(d < e)<<endl;
    cout<< (d > 1e18)<<endl;
    cout<<d<<endl;

    return 0;
}
