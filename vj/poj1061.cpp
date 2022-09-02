#include<iostream>
using namespace std;
#define LL long long

/*
LL gcd_ext(LL x,LL y,LL & kx, LL & ky){    // 扩展gcd

    if(x == 0){
        ky = 1;
        kx = 0;
        return y;
    }
    else if(y == 0 || x == y){
        kx = 1;
        ky = 0;
        return x;
    }
    else if(x > y){
        LL prex = x;        // 注意分清代码中的符号！！
        x %= y;
        LL val = gcd_ext(x,y,kx,ky);    // 
        ky = ky - (prex/y) * kx;
        return val;
    }
    else if(y > x){
        LL prey = y;
        y %= x;
        LL val = gcd_ext(x,y,kx,ky);
        kx = kx - (prey/x) * ky; 
        return val;
    }
}*/
LL gcd_ext(LL x, LL y, LL & kx, LL & ky)   // y < x
{
    if(y == 0){
        kx = 1;
        ky = 0;
        return x;
    }
    LL val = gcd_ext(y,x%y,ky,kx);
    ky = ky - (x/y) * kx;
    return val;
}

int main()
{

    LL x,y,m,n,L;
    cin>>x>>y>>m>>n>>L;
    if(m < n){
        swap(x,y);
        swap(m,n);
    }
    LL kmn,kL;
    LL val = gcd_ext((m-n),L,kmn,kL);


    if((y - x)%val !=0){
        cout<<"Impossible";
    }
    else {
        cout<<(((kmn * ((y - x) / val)) % (L/val)) + (L/val))%(L/val);
    }
    return 0;
}