/*
1. 反向bfs，从终点bfs，就可以解决多个源点一个终点的问题
2. 康托展开，实际上就是一个字典序的问题，可以看刘汝佳第十章的编码和解码的那个问题
*/
#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>

using namespace std;
const int maxx = 362880;

int f[9];
int state[9];
int vis[maxx];
int move_dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};    //udrl
const char Move[5] = "dulr";
int last_posi[maxx];
int last_to_now_move[maxx];


int cantor(int state[]){    // 编码 
    int ans = 0;    
    for(int i = 0; i < 9; i++){ //从最高位开始
        int cnt = 0;
        for(int j = i+1;j < 9;j++)if(state[i] > state[j])cnt++;
        ans += cnt * f[8 - i];
    }
    return ans;
}

void decantor(int code,int state[]){

    int used[9] = {};
    for(int i=0; i<=8; i++){
        int temp = code / f[8 - i];
        for(int j = 0;j < 9;j++){
            if(used[j] == 0){
                if(temp == 0){
                    state[i] = j;
                    used[j] = 1;
                    break;      //跳出单层循环使用break,多层循环使用goto A;A:;
                }
                temp--;
            }
        }
        code = code % f[8 - i];
    }

}
const int max_queue = 30000;
int que[max_queue];


void bfs(){
    memset(vis,0,sizeof(vis));
    int aim[9] = {1,2,3,4,5,6,7,8,0};
    int st = cantor(aim);
    int front,rear;
    front = 0;
    rear = 0;
    que[front] = st;
    front = (front + 1) % max_queue;
    vis[st] = 1;    // 表示已经加入队列
    last_posi[st] = -1;
    last_to_now_move[st] = -1;
    while(front != rear){
        st = que[rear];
        rear = (rear + 1) % max_queue;
        decantor(st,aim);
        int x,y;
        for(int i=0;i<9;i++){
            if(aim[i] == 0){
                x = i / 3;
                y = i % 3;
            }
        }

        for(int i = 0; i<4;i++){
            int nx = x + move_dir[i][0];
            int ny = y + move_dir[i][1];

            if (!(nx<=2&&nx>=0&&ny<=2&&ny>=0))continue;
            swap(aim[nx * 3 + ny],aim[x * 3 + y]);

            int nowposi = cantor(aim);
            if(vis[nowposi] == 0){
                que[front] = nowposi;
                front = (front + 1) % max_queue;
                vis[nowposi] = 1;
                last_posi[nowposi] = st;
                last_to_now_move[nowposi] = i;
            }
            swap(aim[nx * 3 + ny],aim[x * 3 + y]);
        }
    }
    return ;
}

void input(char s[],int state[]){

    int length = strlen(s);
    int cnt = 0;
    for(int i=0;i<length;i++){
        if(s[i]>='1' && s[i] <= '8'){
            state[cnt++] = s[i] -'0';
        }
        else if(s[i] == 'x'){
            state[cnt++] = 0;
        }
        if(cnt == 9)break;
    }
}

void init(){
    f[0] = 1;
    for(int i=1;i<=8;i++)f[i] = f[i-1] * i;
}

int main()
{
    init();
    bfs();
    char a;
    while(cin>>a){
        if(a == 'x')state[0] = 0;
        else state[0] = a - '0';
        for(int i=1;i<9;i++){
            cin>>a;
            if(a == 'x')state[i] = 0;
            else state[i] = a - '0';
        }
        // input(a,state);

        int ans = cantor(state);
        if(vis[ans] == 1){
            while(!(last_posi[ans] == -1)){
                    cout<<Move[last_to_now_move[ans]];
                ans = last_posi[ans];
            }
            cout<<endl;
        }
        else cout<<"unsolvable"<<endl;


    }
    return 0;
}