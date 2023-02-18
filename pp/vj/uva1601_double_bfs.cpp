// 双向bfs
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

char map_ghost[20][20];
int map_dir[5][20][20][2];
int map_dir_num[20][20];
int dir[5][2] = {{1,0},{-1,0},{0,1},{0,-1},{0,0}};

int vis_state[16777216 + 100];
int step_state[16777216 + 100];
int pre_state[16777216 + 100];
int ghost_name[3];

bool check_clash(int new_state,int pre_state)
{
    int new_[3], pre_[3];
    for(int i = 0;i < 3;i++){
        new_[i] = new_state % 256;
        pre_[i] = pre_state % 256;
        new_state /= 256;
        pre_state /= 256;
    }
    for(int i = 0;i < 3;i++){
        for(int j = i + 1;j < 3;j++){
            if(ghost_name[i] == 1 && ghost_name[j] == 1 && new_[i] == pre_[j] &&pre_[i] == new_[j])return true;
            if(ghost_name[i] == 1 && ghost_name[j] == 1 && new_[i] == new_[j])return true;

        }
    }
    return false;
}

int encode(int a,int b,int c){return a + 256 * b + 256 * 256 * c;}
void print(int code)
{
    int a[3] = {code%256, (code/256)%256, (code/(256*256)) };
    printf("a: %d %d\nb: %d %d\nc: %d %d\n\n", a[0]/16,a[0]%16,a[1]/16,a[1]%16,a[2]/16,a[2]%16);
}
void bfs(int init_state,int end_state)
{
    queue<int>q;
    memset(vis_state,0,sizeof(vis_state));
    memset(pre_state,-1,sizeof(pre_state));
    q.push(init_state);
    // q.push(end_state);
    vis_state[init_state] = 1;
    vis_state[end_state] = 2;
    step_state[init_state] = 0;
    step_state[end_state] = 0;
    while(!q.empty())   // 缺点是无解搜索时间翻倍，
    {
        int now_state = q.front();
        // printf("%d",vis_state[now_state]);
        q.pop();
        int scale[3] = {0};
        int a[3] = {now_state %256, (now_state/256)%256, (now_state/(256*256))%256};
        for(int i = 0;i < 3;i++){
            if(ghost_name[i] == 0)scale[i] = 1;
            else scale[i] = map_dir_num[a[i]/16][a[i]%16];
        }
        int i[3] ={0,0,0};
        for(i[0] = 0;i[0] < scale[0];i[0]++){
            for(i[1] = 0;i[1] < scale[1];i[1]++){
                for(i[2] = 0;i[2] < scale[2];i[2]++){
                    int new_state = 0;
                    for(int l = 2;l >= 0;l--){
                        new_state *= 256;
                        if(ghost_name[l] == 1)new_state += map_dir[i[l]][a[l]/16][a[l]%16][0] * 16 + map_dir[i[l]][a[l]/16][a[l]%16][1];
                    }
                    if(vis_state[new_state] == 0){
                        if(check_clash(new_state, now_state))continue;
                        vis_state[new_state] = vis_state[now_state];
                        step_state[new_state] = step_state[now_state] + 1;
                        pre_state[new_state] = now_state;
                        q.push(new_state);
                    }
                    else {
                        if(vis_state[new_state] == vis_state[now_state])continue;
                        else {
                            if(check_clash(new_state, now_state))continue;
                            cout<< step_state[new_state] + step_state[now_state] + 1 <<endl;
                            // print(new_state);
                            // while(!(now_state == -1)){
                            //     print(now_state);
                            //     now_state = pre_state[now_state];

                            // }
                            return ;
                        }
                    }
                    
                }
            }
        }
    }
    cout<<-1<<endl;
    return ;
}

int main()
{
    int w,h,n;
    while(scanf("%d%d%d",&w,&h,&n) == 3 && !(w == 0 && h == 0 && n == 0)){
        getchar();
        memset(ghost_name,0,sizeof(ghost_name));
        memset(map_dir_num,0,sizeof(map_dir_num));
        int init_state = 0,end_state = 0;
        for(int i = 0;i < h;i++){
            fgets(map_ghost[i],20,stdin);
            // printf("%s",map_ghost[i]);
            for(int j = 0;j < w;j++){
                if(isalpha(map_ghost[i][j])){
                    if('a' <= map_ghost[i][j] && map_ghost[i][j] <= 'c'){
                        if(map_ghost[i][j] - 'a' == 0)  init_state += (i * 16 + j);
                        if(map_ghost[i][j] - 'a' == 1)  init_state += (i * 16 + j) * 256;
                        if(map_ghost[i][j] - 'a' == 2)  init_state += (i * 16 + j) * 256 *256;
                        ghost_name[map_ghost[i][j] - 'a'] = 1;      // 用到了那个鬼鬼
                    }
                    if('A' <= map_ghost[i][j] && map_ghost[i][j] <= 'C'){
                        if(map_ghost[i][j] - 'A' == 0)  end_state += (i * 16 + j);
                        if(map_ghost[i][j] - 'A' == 1)  end_state += (i * 16 + j) * 256;
                        if(map_ghost[i][j] - 'A' == 2)  end_state += (i * 16 + j) * 256 * 256;
                    }
                }
            }
        }

        for(int i = 0;i < h;i++){
            for(int j = 0;j < w;j++){
                if(map_ghost[i][j] != '#'){
                    int cnt = 0;
                    for(int k = 0;k < 5;k++){
                        if(!(0 <= i + dir[k][0] && i + dir[k][0] < h && 0 <= j + dir[k][1] && j + dir[k][1] < w))continue;
                        if(map_ghost[i + dir[k][0]][j + dir[k][1]] != '#'){
                            map_dir[cnt][i][j][0] = i + dir[k][0];
                            map_dir[cnt][i][j][1] = j + dir[k][1];                            
                            cnt++;
                        }
                    }
                    map_dir_num[i][j] = cnt;

                }
                // cout << map_dir_num[i][j] << ' ';
            }
            // cout<<endl;
        }
        bfs(init_state, end_state);
    }
    return 0;
}

// void bfs(int init_state,int end_state)      // 双向bfs实际上可以使用一个队列！
// {
//     // state : a + b *256 + c * 256 * 256, a = a.y + a.x * 16;
//     queue<int>q1,q2;
//     memset(vis_state,0,sizeof(vis_state));
//     q1.push(init_state);
//     q2.push(end_state);
//     vis_state[init_state] = 1;
//     vis_state[end_state] = 2;
//     step_state[init_state] = 0;
//     step_state[end_state] = 0;
//     int now_step_1 = 0, now_step_2 = 0;
//     while(!(q1.empty()||q2.empty())){
//         while(!q1.empty()){   // 遍历q1
//             int now_state = q1.front();
//             if(step_state[now_state] == now_step_1 + 1){
//                 now_step_1++;
//                 break;
//             }
//             q1.pop();
//             int a[3] = {now_state % 256, (now_state/256) %256 ,(now_state/(256*256))};
//             // printf("a: %d %d\nb: %d %d\nc: %d %d\n\n",a[0]/16,a[0]%16, a[1]/16, a[1]%16,a[2]/16,a[2]%16);
//             int scale[3] = {0};
//             for(int i = 0;i < 3;i++){
//                 if(ghost_name[i] == 0)scale[i] = 1;
//                 else scale[i] = map_dir_num[a[i]/16][a[i]%16];
//             }
//             // printf("%d %d %d\n",scale[0],scale[1],scale[2]);
//             for(int i = 0;i < scale[0];i++){
//                 for(int j = 0;j < scale[1]; j++){
//                     for(int k = 0;k < scale[2];k++){
//                         int new_state = ghost_name[0] * (map_dir[i][a[0]/16][a[0]%16][0] * 16 + map_dir[i][a[0]/16][a[0]%16][1]) +\
//                                         ghost_name[1] * (map_dir[j][a[1]/16][a[1]%16][0] * 16 + map_dir[j][a[1]/16][a[1]%16][1]) * 256  +\
//                                         ghost_name[2] * (map_dir[k][a[2]/16][a[2]%16][0] * 16 + map_dir[k][a[2]/16][a[2]%16][1]) * 256 * 256;
//                         if(vis_state[new_state] == 2){

//                             cout<<step_state[new_state] << ' '<< step_state[now_state]+1 <<endl;
//                             return;
//                         }
//                         /*
//                             2. 检查访问过没
//                             1. 碰撞检测
//                         */
//                         if(vis_state[new_state] == 1)continue;
//                         if(check_clash(new_state,now_state))continue;   
//                         vis_state[new_state] = 1;
//                         step_state[new_state] = now_step_1 + 1;
//                         q1.push(new_state);
//                     }
//                 }
//             }
//         }
//         while(!q2.empty()){
//             int now_state = q2.front();
//             if(step_state[now_state] == now_step_2 + 1){
//                 now_step_2++;
//                 break;
//             }
//             q2.pop();
//             int a[3] = {now_state % 256, (now_state/256) %256 ,(now_state/(256*256))};
//             int scale[3] = {0};
//             for(int i = 0;i < 3;i++){
//                 if(ghost_name[i] == 0)scale[i] = 1;
//                 else scale[i] = map_dir_num[a[i]/16][a[i]%16];
//             }
//             for(int i = 0;i < scale[0];i++){
//                 for(int j = 0;j < scale[1]; j++){
//                     for(int k = 0;k < scale[2];k++){
//                         int new_state = ghost_name[0] * (map_dir[i][a[0]/16][a[0]%16][0] * 16 + map_dir[i][a[0]/16][a[0]%16][1]) +\
//                                         ghost_name[1] * (map_dir[j][a[1]/16][a[1]%16][0] * 16 + map_dir[j][a[1]/16][a[1]%16][1]) * 256  +\
//                                         ghost_name[2] * (map_dir[k][a[2]/16][a[2]%16][0] * 16 + map_dir[k][a[2]/16][a[2]%16][1]) * 256 * 256;
//                         if(vis_state[new_state] == 1){
//                             cout<<step_state[new_state] + step_state[now_state] + 1<<endl;
//                             return;
//                         }
//                         /*
//                             2. 检查访问过没
//                             1. 碰撞检测
//                         */
//                         if(vis_state[new_state] == 2)continue;
//                         if(check_clash(new_state,now_state))continue;   
//                         vis_state[new_state] = 2;
//                         step_state[new_state] = now_step_2 + 1;
//                         q2.push(new_state);
//                     }
//                 }
//             }
//         }
//     }
//     cout<<-1<<endl;
//     return;
// }
