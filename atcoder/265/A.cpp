#include<iostream>
using namespace std;
int main()
{
    int x,y,n;
    cin>>x>>y>>n;
    if(3 * x > y){
        cout<<((n/3) * y) + (n%3) *x<<endl;
    }
    else {
        cout<<n*x<<endl;
    }
    return 0;
}