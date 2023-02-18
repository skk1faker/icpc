#include<iostream>
#include<cstring>
#include<map>

using namespace std;
map<int, int> posi_right[3];
long long a[(int)2e5 + 10];
int main()
{
    long long  n,value[3];
    cin>>n;
    for(int i = 0 ;i < 3;i++)cin>>value[i];
    for(int i = 0; i < n;i++)scanf("%lld",&a[i]);
    for(int j = 0 ;j < 3;j++){
        int st_posi = 0;
        long long  sum = 0;
        for(int en_posi = 0;en_posi< n;en_posi++){
            sum += a[en_posi];

            // now_value  = [st_posi -- en_posi];
            while(sum > value[j]){
                sum -= a[st_posi];
                st_posi++;
            }
            if(sum == value[j]){
                posi_right[j][st_posi] = en_posi;
            }
        }
    }

    for(auto it :posi_right[0]){
        if(posi_right[1].count(it.second + 1) != 0){
            if(posi_right[2].count(posi_right[1][it.second + 1] + 1) != 0){
                cout<<"Yes"<<endl;
                // cout<<it.first<< ' '<<it.second + 1<<' '<<posi_right[1][it.second + 1] + 1<<' '<<posi_right[2][posi_right[1][it.second + 1] + 1] + 1<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}