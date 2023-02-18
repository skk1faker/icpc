#include<iostream>

using namespace std;

int main()
{
    int k,x,y;
    while(scanf("%d",&k) == 1){
        int maxx = k*k + k;
        int edge = (maxx + k + 1) / 2;
        int ans_num = 0;
        for(y = k + 1; y <= maxx; y++ ){
            x = (k * y) /(y - k);
            if(x < y)break;
            if( (k * (x + y)) == (x * y)){
                ans_num++;
            }
        }
        cout<<ans_num<<endl;
        for(y = k + 1; y <= maxx; y++ ){
            x = (k * y) /(y - k);
            if(x < y)break;
            if( (k * (x + y)) == (x * y)){
                printf("1/%d = 1/%d + 1/%d\n",k,x,y);
            }
        }
    }
    return 0;
}