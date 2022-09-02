#include<iostream>
#include<queue>

using namespace std;

const int max_mn = 101;
const int max_tt = 1001;
bool vis[max_mn][max_mn][max_tt];       // 如果这里是int，就会发生内存超限！！
struct castle{
    int vx,vy,t,is_castle;
    castle(int vx = 0,int vy = 0,int t = 0,int is_castle = 0):vx(vx),vy(vy),t(t),is_castle(is_castle){}
};
struct posi{
    int x,y;
    posi(int x = -1,int y = -1):x(x),y(y){}// 表示没有靠近的堡垒
    posi(const posi & a){
        x = a.x;
        y = a.y;
    }
};
castle map[max_mn][max_mn];

posi close_castle[4][max_mn][max_mn];
int dir_move[5][2] = {{1,0},{-1,0},{0,1},{0,-1},{0,0}};
int m,n,k,d;

struct a_state{
    int x,y,t;
    a_state(int x,int y,int t):x(x),y(y),t(t){}
    a_state(const a_state & a){
        x = a.x;
        y = a.y;
        t = a.t;
    }
};



void bfs(){
    queue<a_state> q;
    q.push(a_state(0,0,0));
    vis[0][0][0] = 1;
    while(!q.empty()){
        a_state now_posi = q.front();
        q.pop();
        for(int i = 0; i < 5; i++){
            int nx = now_posi.x + dir_move[i][0];
            int ny = now_posi.y + dir_move[i][1];
            int nt = now_posi.t + 1;
            if(!(0 <= nx && nx <= m&& 0 <= ny && ny <= n))continue;
            if(vis[nx][ny][nt] == 1)continue;
            vis[nx][ny][nt] = 1;
            if(map[nx][ny].is_castle == 1)continue;     // 人不可经过碉堡
            if(m - nx + n - ny + nt > d)continue;   // A*
            // if(nt > d)continue;
            int flag = 0;
            for(int k = 0;k < 4;k++){
                int castle_x_posi = close_castle[k][nx][ny].x;
                int castle_y_posi = close_castle[k][nx][ny].y;
                if(close_castle[k][nx][ny].x == -1 && close_castle[k][nx][ny].y == -1)continue; // 表示这个方向上没有一个堡垒！！
                castle temp_castle = map[castle_x_posi][castle_y_posi];
                if(temp_castle.t == 0)continue;
                if(temp_castle.vx != 0 && (k == 0||k == 1)){
                    int temp_t = (nx - castle_x_posi) / temp_castle.vx;
                    int temp_t_mod = (nx - castle_x_posi) % temp_castle.vx;     //整除；
                    if(temp_t >=0 &&temp_t <= nt && temp_t_mod == 0 && ((nt - temp_t) % temp_castle.t) == 0)flag = 1;
                }
                if(temp_castle.vy != 0 && (k == 2||k == 3)){
                    int temp_t = (ny - castle_y_posi) / temp_castle.vy;
                    int temp_t_mod = (ny - castle_y_posi) % temp_castle.vy;
                    if(0<=temp_t && temp_t <= nt && temp_t_mod == 0 && ((nt - temp_t) % temp_castle.t) == 0)flag = 1;
                }
                if(flag == 1)break;
            }
            if(flag == 1)continue;  // 子弹击中
            if(nx == m && ny == n){
                cout<<nt<<endl;
                return ;
            }
            q.push(a_state(nx,ny,nt));   
            // printf("%d %d %d\n",nx,ny,nt);
        }
    }

    cout<<"Bad luck!"<<endl;
    return ;
}


int main()
{
    while(scanf("%d%d%d%d",&m,&n,&k,&d) == 4){
        for(int i = 0;i <= m;i++){
            for(int j = 0;j <= n;j++){
                map[i][j].is_castle = 0;
                for(int k = 0;k <= d;k++)vis[i][j][k] = 0;
                for(int k = 0;k < 4;k++)close_castle[k][i][j] = posi(-1,-1);
            }
        }
        int t,v,x,y;
        char c;
        for(int i = 0;i<k;i++){
            do{
                c = getchar();
            }while(!(c == 'N'||c == 'W'||c == 'E'||c == 'S'));

            scanf("%d%d%d%d",&t,&v,&x,&y);  
            int vx = 0, vy = 0;
            switch(c){
                case 'N':vx = -v;break; //0
                case 'S':vx = v; break; //1
                case 'W':vy = -v;break; //2
                case 'E':vx = v; break; //3
            }
            map[x][y].is_castle = 1;
            map[x][y].vx = vx;
            map[x][y].vy = vy;
            map[x][y].t = t;
            for(int k = 0;k < 4;k++)close_castle[k][x][y] = posi(x,y);
        }
        if(map[m][n].is_castle == 1){
            cout<<"Bad luck!"<<endl;
            continue;
        }

        for(int i = 0;i <= m;i++){
            for(int j = 0;j<=n;j++){
                int j1 = j;
                int j2 = n - j;
                if(map[i][j1].is_castle == 0 && j1 - 1 >= 0)close_castle[2][i][j1] = close_castle[2][i][j1 - 1];
                if(map[i][j2].is_castle == 0 && j2 + 1 <= n)close_castle[3][i][j2] = close_castle[3][i][j2 + 1];
            }
        }
        for(int j = 0;j<=n;j++){
            for(int i = 0;i <=m; i++){
                int i1 = i;
                int i2 = m - i;
                if(map[i1][j].is_castle == 0 && i1 - 1 >= 0)close_castle[0][i1][j] = close_castle[0][i1 - 1][j];
                if(map[i2][j].is_castle == 0 && i2 + 1 <= m)close_castle[1][i2][j] = close_castle[1][i2 + 1][j];
            }
        }

        bfs();
    }
        
    return 0;
}
