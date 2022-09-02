#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

const int max_point = (int)2e3+10;

struct k_value{
    int dx, dy;
    k_value(int dx = 0,int dy = 0):dx(dx),dy(dy){}
    bool operator < (const k_value & temp)
    {
        return (temp.dx * dy) < (temp.dy * dx);
    }
    bool operator == (const k_value & temp){
        return (temp.dx * dy) == (temp.dy * dx);
    }
    static bool equal_1(const k_value & temp1, const k_value &temp2){       
        return (temp1.dx * temp2.dx) == (-1 * temp1.dy * temp2.dy);
    }
};

struct point{
    int x,y;
    k_value other_point_k[max_point];
    point(int x = 0,int y = 0):x(x),y(y){}
    
}point_value[max_point];

int findbound(k_value k1, point p1,int ele_num,int mode)
{
    int l = 0, r = ele_num - 1;
    while(l < r){
    int mid = (l+r)>>1;
        if(k1 < p1.other_point_k[mid]){
            r = mid ;
        }
        else if(k1 == p1.other_point_k[mid]){
            if(mode == 0)r = mid ;
            else if(mode == 1)l = mid + 1;    
        }
        else {
            l = mid + 1;
        }
    }

    if(mode == 0)return l;
    else return l - 1;
}

int main()
{
    int n,q;
    while(scanf("%d%d",&n,&q) == 2){
        for(int i = 0;i < n;i++){
            scanf("%d%d",&point_value[i].x, &point_value[i].y);
        }

        for(int i = 0;i < n;i++){
            int cnt = 0;
            for(int j = 0;j < n;j++){
                if(i == j)continue;
                point_value[i].other_point_k[cnt].dx = point_value[i].x - point_value[j].x;
                point_value[i].other_point_k[cnt].dy = point_value[i].y - point_value[j].y;
                cnt++;
            }
            sort(point_value[i].other_point_k,point_value[i].other_point_k + cnt);
        }

        for(int i = 0;i < q;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            point temp_point(x, y);
            for(int i = 0;i < n;i++){
                temp_point.other_point_k[i].dx = point_value[i].x - temp_point.x;
                temp_point.other_point_k[i].dy = point_value[i].y - temp_point.y;
            }
            sort(temp_point.other_point_k, temp_point.other_point_k + n);
            queue<int>q_k;
            int id_point = 0;
            while(id_point < n){
                if(q_k.empty()){
                    q_k.push(id_point);
                    id_point++;
                    continue;
                }
                k_value first_element_vertical = temp_point.other_point_k[q_k.front()];
                if(first_element_vertical.dy == 0){
                    first_element_vertical.dx *= -1;   
                }
                else if(first_element_vertical.dx == 0){
                    first_element_vertical.dy *= 1;
                }
                else {
                    first_element_vertical.dx *= -1;
                }
            }



        }

    }
    return 0;
}