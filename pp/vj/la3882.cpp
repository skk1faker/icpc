#include<iostream>
using namespace std;

int n,k,m;

int re_num(int total_number)   // id is dead in have total_number - 1 
{
    if(total_number == 1)return 1;
    int ans = ((re_num(total_number - 1) + k )%total_number);
    ans = (ans == 0 ? total_number : ans);
    return ans;
}


int main()
{
    while(scanf("%d%d%d", &n,&k,&m) == 3){
        if(n == 0)return 0;
        int ans = (re_num(n) + m - k) % n;
        if(ans <= 0 )ans += n;
        cout<<ans<<endl; 
    }
    return 0;
}