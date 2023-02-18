#include<iostream>

using namespace std;
int get_ans(int n)
{
    if(n <= 1)return 1;
    return get_ans(n/2)+1;
}
int main()
{
    int n;
    while(scanf("%d",&n)==1){
        cout<<get_ans(n)<<endl;
        //cout<<n<<"向上取整"<<((int)((double)(n-1)/2+0.5))<<" "<<n/2<<endl;
    }
}