#include<iostream>
using namespace std;

int main()
{
    int a[4],b;
    for(int i=0;i<4;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&b);
    for(int i=0;i<4;i++){
        if(a[i] <= b){
            cout<<b - a[i];
        }
        else cout<<0;
        if(i!=3)cout<<' ';
    }


    return 0;
}