#include<iostream>
using namespace std;
const long long mod = 998244353;
int main()
{
    long long n;
    cin>>n;
    n = n % mod;
    cout<<(n*n) % mod<<endl;
    return 0;
}