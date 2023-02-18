#include<iostream>
#include<cstring>
#include<queue>

using namespace std;

char map[16][20];

int vis[16777217];
int w,h,n;

struct posi_ghost{
    int n;
    int posi[3][2];
    int step;
    posi_ghost(int n)
    {
        step = 0;
        for(int i = 0;i< n;i++){
            posi[i][0] = 0;
            posi[i][1] = 0;
        }
        this->n = n;
    }
    posi_ghost(const posi_ghost & temp){
        this->n = temp.n;
        for(int i = 0; i < 3; i++){
            for(int j = 0;j < 2;j++){
                this ->posi[i][j] = temp.posi[i][j];
            }
        }
        this->step = temp.step;
    }
    int encode()
    {
        int ans = 0;
        for(int i = 0;i < n;i++){
            ans *= (16 * 16);
            ans += posi[i][0] * 16 + posi[i][1];
        }
        return ans;
    }
    bool operator == (const posi_ghost & temp){
        if(temp.n != this->n)return false;
        for(int i = 0;i < temp.n;i++){
            if(temp.posi[i][0] != this->posi[i][0])return false;
            if(temp.posi[i][1] != this->posi[i][1])return false;
        }
        return true;
    }
    void print(){
        for(int i = 0;i < n;i++){
            printf("%c :%d %d\n", (char)(i + 'a'),posi[i][0],posi[i][1]);
        }
        printf("%d\n",step);
    }
    bool check_clash(const posi_ghost & temp)      // 检测碰撞
    {
        for(int i = 0;i < n;i++){
            for(int j = i + 1;j < n;j++){
                if(posi[i][0] == posi[j][0] && posi[i][1] == posi[j][1]) return true;
                if(posi[i][0] == temp.posi[j][0] && posi[i][1] == temp.posi[j][1] && temp.posi[i][0] == posi[j][0] && temp.posi[i][1] == posi[j][1]) return true;
            }
        }

        return false;
    }
    bool check_out_edge(int w,int h)
    {
        for(int i = 0;i < n;i++){
            if(!(0 <= posi[i][0] && posi[i][0] < h))return true;
            if(!(0 <= posi[i][1] && posi[i][1] < w))return true;
        }
        return false;
    } 
};
int dir[5][2] = {{0,1},{0,-1},{1,0},{-1,0},{0,0}};

/*
    什么样的可以作为下一个状态！
    1. 不越界
    2. 不在'#'上
    3. 顺序移动时不发生碰撞
    4. 是一个新的状态
*/

void bfs(posi_ghost init_state,posi_ghost end_state)
{
    int state_number = 1;
    for(int i =0;i < n;i++)state_number *= 5;
    memset(vis,0,sizeof(vis));
    queue<posi_ghost>q;
    queue<posi_ghost>q1;

    q.push(init_state);
    q1.push(end_state);
    vis[init_state.encode()] = 1;
    vis[end_state.encode()] = 2;
    while(!q.empty()){
        posi_ghost now_state = q.front();
        q.pop();
        for(int i = 0;i < state_number;i++){
            posi_ghost new_posi = now_state;
            new_posi.step += 1;
            int flag = 0;
            int choose_mode = i;
            for(int j = 0;j < n;j++){
                new_posi.posi[j][0] += dir[choose_mode % 5][0];
                new_posi.posi[j][1] += dir[choose_mode % 5][1];
                choose_mode /= 5;
                if(!(0 <= new_posi.posi[j][0] && new_posi.posi[j][0] < h && 0 <= new_posi.posi[j][1] && new_posi.posi[j][1] < w))flag = 1;
                // new_posi.print();
                if(flag == 1)break;
                // new_posi.print();
                if(map[new_posi.posi[j][0]][new_posi.posi[j][1]] == '#')flag = 1;
                if(flag == 1)break;
                // new_posi.print();
            }
            if(flag == 1)continue;
            if(new_posi.check_clash(now_state))flag = 1;
            if(flag == 1)continue;
            if(vis[new_posi.encode()] == 1)continue;
            vis[new_posi.encode()] = 1;
            if(new_posi == end_state){
                cout<<new_posi.step<<endl;
                return ;
            }
            q.push(new_posi);
        }
    }
    cout<<-1<<endl;
}


int main()
{
    while(scanf("%d%d%d",&w,&h,&n) == 3 && w !=0 && h != 0){
        getchar();  // 收回回车符号！
        posi_ghost init_state(n);
        posi_ghost end_state(n);
        for(int i = 0;i < h;i++){
            fgets(map[i],20,stdin);
            printf("%s",map[i]);
            for(int j = 0;j < w;j++){
                if('a' <= map[i][j] && map[i][j] <= 'c'){
                    init_state.posi[map[i][j] - 'a'][0] = i;
                    init_state.posi[map[i][j] - 'a'][1] = j;
                    // cout<<(int)(map[i][j] - 'a')<<' '<<i<<' '<<j<<endl;

                }
                if('A' <= map[i][j] && map[i][j] <= 'C'){
                    end_state.posi[map[i][j] - 'A'][0] = i;
                    end_state.posi[map[i][j] - 'A'][1] = j;
                    // cout<<map[i][j]<<' '<<i<<' '<<j<<endl;
                }
                
            }
        }
        init_state.step = 0;
        bfs(init_state, end_state);
    }
    return 0;
}


/*
void bfs(posi_ghost init_state, posi_ghost end_state)
{
    queue<posi_ghost>q;
    q.push(init_state);
    vis[init_state.encode()] = 1;
    while(!q.empty()){
        posi_ghost now_state = q.front();
        q.pop();
        int new_posi[3][2];
        for(int i = 0;i < 3;i++){
            new_posi[i][0] = now_state.posi[i][0];
            new_posi[i][1] = now_state.posi[i][1];
        }
        for(int i = 0;i < 4;i++){
            for(int i = 1;i < 3;i++){
                new_posi[i][0] = now_state.posi[i][0];
                new_posi[i][1] = now_state.posi[i][1];
            }   
        
            new_posi[0][0] = now_state.posi[0][0] + dir[i][0]; 
            new_posi[0][1] = now_state.posi[0][1] + dir[i][1]; 
            if(check_out_posi(new_posi[0]))continue;
            if(map[new_posi[0][0]][new_posi[0][1]] == '#')continue;
            if(check_equal(now_state.n, new_posi))continue;
            for(int j = 0;j < 4;j++){
                if(now_state.n > 1){      // 多于两个元素触发
                    for(int i = 2;i < 3;i++){
                        new_posi[i][0] = now_state.posi[i][0];
                        new_posi[i][1] = now_state.posi[i][1];
                    }
                    new_posi[1][0] = now_state.posi[1][0] + dir[j][0]; 
                    new_posi[1][1] = now_state.posi[1][1] + dir[j][1]; 
                    if(check_out_posi(new_posi[1]))continue;
                    if(map[new_posi[1][0]][new_posi[1][1]] == '#')continue;
                    if(check_equal(now_state.n, new_posi))continue;
                }
                for(int k = 0;k < 4;k++){
                    if(now_state.n > 2){      //多余3个元素触发
                        new_posi[2][0] = now_state.posi[2][0] + dir[k][0];
                        new_posi[2][1] = now_state.posi[2][1] + dir[k][1];
                        if(check_out_posi(new_posi[2]))continue;
                        if(map[new_posi[2][0]][new_posi[2][1]] == '#')continue;
                        if(check_equal(now_state.n, new_posi))continue;         // 碰撞检测！！！！！！
                    }
                    posi_ghost new_state(now_state.n, new_posi, now_state.step + 1);
                    if(vis[new_state.encode()] == 1){
                        if(now_state.n <= 2)break;
                        else continue;
                    }
                    vis[new_state.encode()] = 1;
                    // 程序的处理位置！！
                    if(new_state == end_state){
                        printf("%d\n",new_state.step);
                        return ;
                    }
                    // new_state.print();
                    printf("\n");
                    q.push(new_state);

                    if(now_state.n <= 2)break;
                }
                if(now_state.n <= 1)break;
            }
        }
    }
}


*/