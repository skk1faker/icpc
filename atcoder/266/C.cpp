#include<iostream>
#include<cmath>

#define sgn(x) (abs(x) / (x))

using namespace std;
struct posi{
    int x,y;
};
bool in_where(posi p0,posi p1, posi p2){
    if(p0.x == p1.x){
        return p0.x < p1.x;
    }
    return p1.y * abs(p0.x - p1.x) > sgn(p0.x - p1.x) * (p0.y - p1.y) * (p1.x - p2.x) + p2.y * abs(p0.x - p1.x);
}
bool in_line(posi p0,posi p1, posi p2){
    if(p0.x == p1.x){
        return p0.x == p1.x;
    }
    return p1.y * abs(p0.x - p1.x)  ==  sgn(p0.x - p1.x) * (p0.y - p1.y) * (p1.x - p2.x) + p2.y * abs(p0.x - p1.x);
}
int main()
{
    posi p[4];
    for(int i = 0;i < 4; i++){
        scanf("%d%d",&p[i].x,&p[i].y);
    }
    for(int i = 0;i < 2;i++){
        if((in_where(p[0 + i], p[2 + i], p[1 + i]) == in_where(p[0 + i], p[2 + i], p[(3 + i)% 4]))||in_line(p[0 + i], p[2 + i], p[(3 + i)% 4]) ||in_line(p[0 + i], p[2 + i], p[1 + i])){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}