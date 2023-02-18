#include<cstdio>
#include<algorithm>
#include<iostream>

using namespace std;
const int maxx = (int)1e2+10;

int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int val_memory,n,k;
struct Memory_posi
{
    int posi[2];
    int memory;
    int dp;
    bool operator < (const Memory_posi & a){return this->memory > a.memory;}
    bool operator == (const Memory_posi &a){
        if(this->memory == a.memory)return false;
        if(this->posi[0] == a.posi[0] || this->posi[1] == a.posi[1]){
            if(this->posi[0] == a.posi[0]){
                return abs(this->posi[1] -  a.posi[1]) <= k;
            }
            else {
                return abs(this->posi[0] - a.posi[0]) <= k;
            }
        }
        return false;
    }
}memory_posi[(int)1e4+10];
int main()
{
    while(scanf("%d%d",&n,&k) == 2){
        if(k == -1)break;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                scanf("%d",&val_memory);
                memory_posi[i*n+j].posi[0] = i;
                memory_posi[i*n+j].posi[1] = j;
                memory_posi[i*n+j].memory = val_memory;
                memory_posi[i*n+j].dp = 0;
            }
        }
        std::sort(memory_posi,memory_posi+(n*n));
        // memory_posi[0].dp = 
        for(int i = 0;i < n*n;i++){
            // cout<<memory_posi[i].memory<<endl;
            memory_posi[i].dp = 0;
            for(int j = i - 1; j >= 0; j--){
                if(memory_posi[i] == memory_posi[j]){
                // if((memory_posi[i].posi[0] == memory_posi[j].posi[0]) || (memory_posi[i].posi[1] == memory_posi[j].posi[1])){
                    memory_posi[i].dp = max(memory_posi[i].dp, memory_posi[j].dp);
                }
            }
            memory_posi[i].dp += memory_posi[i].memory;
            // cout<<memory_posi[i].posi[0]<<' '<<memory_posi[i].posi[1]<<' '<<memory_posi[i].dp<<endl;
            if(memory_posi[i].posi[0] == 0 && memory_posi[i].posi[1] == 0){
                cout<<memory_posi[i].dp<<endl;
                break;
            }
        }
    }    
    return 0;
}