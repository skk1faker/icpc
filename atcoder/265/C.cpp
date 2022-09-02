#include<iostream>
#include<string.h>
using namespace std;

const int grid_max = 501;
string G[grid_max];
bool vis[grid_max][grid_max];
struct posi
{
    int x,y;
};

bool move_posi(posi &nowposi, char order,int h, int w)
{
    posi temp_posi = nowposi;
    switch (order){
        case 'U':{
            temp_posi.x--;
            break;
        }
        case 'D':{
            temp_posi.x++;
            break;
        }
        case 'R':{
            temp_posi.y++;
            break;
        }
        case 'L':{
            temp_posi.y--;
            break;
        }
    }
    if((temp_posi.x < 0 || temp_posi.x >=h)||(temp_posi.y < 0 || temp_posi.y >=w)){
        return false;
    }
    else {
        nowposi.x = temp_posi.x;
        nowposi.y = temp_posi.y;
        return true;
    }
}

int main()
{
    int h,w;
    cin>>h>>w;
    for(int i = 0;i < h; i++){
        cin>>G[i];
    }
    posi now_posi = {0,0};
    memset(vis,0,sizeof(vis));
    // cout<<G[0][0]<<endl;
    while(move_posi(now_posi, (char)G[now_posi.x][now_posi.y],h,w))
    {
        // cout<<G[now_posi.x][now_posi.y]<<endl;
        // cout<<now_posi.x<<' '<<now_posi.y<<endl;
        if(vis[now_posi.x][now_posi.y] == 1){
            cout<<-1<<endl;
            return 0;
        }
        vis[now_posi.x][now_posi.y] = 1;
    }
    cout<<now_posi.x + 1<<' '<<now_posi.y + 1<<endl;
    return 0;
}