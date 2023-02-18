#include<iostream>
using namespace std;
const int room_max = (int)1e5+10;
long long need_time[room_max];
long long  bonud[room_max];
int main()
{
    int n,m;
    long long t;
    cin>>n>>m;
    cin>>t;
    need_time[0] = 0;
    bonud[0] = 0;
    for(int i = 1;i<n;i++){
        bonud[i] = 0;
        scanf("%lld",&need_time[i]);
    }
    for(int i = 0;i < m;i++){
        long long posi,bond;
        scanf("%lld %lld",&posi,&bond);
        bonud[posi - 1] = bond;
    }
    for(int i = 0;i < n;i++){
        t -= need_time[i];
        if(t <= 0){
            cout<<"No"<<endl;
            return 0;
        }
        t += bonud[i];

    }
    cout<<"Yes"<<endl;
    return 0;

}