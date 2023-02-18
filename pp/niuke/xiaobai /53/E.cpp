#include<iostream>

using namespace std;
int main()
{
    int T;
    cin>>T;
    int s;
    int k[7];
    int need_s = 0;
    while(T--){
        need_s = 0;
        scanf("%d",&s);
        for(int i = 1;i<=6;i++)scanf("%d",&k[i]);
        k[1] -= k[5] * 11;
        k[2] -= k[4] *5;
        if(k[2] < 0){
            k[1] += 4*k[2];     // 注意此时的k[2]为负数
            k[2] = 0;
        }
        need_s = (k[6] + k[5] + k[4]);
        need_s += (k[3] + 3 )/4;
        if(k[3]%4 != 0){
            switch((4 - (k[3]%4))){
                case 1 : {
                    k[1] -=5;
                    k[2] -=1;
                }break;
                case 2 : {
                    k[1] -=6;
                    k[2] -=3;
                }break;
                case 3 : {
                    k[2] -=5;
                    k[1] -=7;
                }break;
            }
            if(k[2] < 0){
                k[1] += 4 * k[2];
            }
        }
        if(k[2] > 0){
            need_s += (k[2] + 8)/9;
            if(k[2] % 9 !=0){
                k[1] -= 4*(9 - (k[2] % 9));
            }
        }
        if(k[1] > 0){
            need_s += (k[1] + 35)/36;
        }
        if( s >= need_s)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}