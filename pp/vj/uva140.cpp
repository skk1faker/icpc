#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

vector<int> gra[26];
int vis[26];   // 本轮出现那些字符
int char_set[26];
int char_number = 0;

int vis_char[26];
int ans[11];
int temp_ans[11];
int ans_posi[26];
int band_width = 100;

void dfs(int step, int now_ans)
{
    if(now_ans >= band_width)return ;
    if(step == char_number){
        band_width = now_ans;
        for(int i = 0;i < step;i++){
            ans[i] = temp_ans[i];
        }
        return ;
    }
    for(int i = 0;i < char_number;i++){
        if(vis_char[char_set[i]] == 0){
            vis_char[char_set[i]] = 1;
            temp_ans[step] = char_set[i];
            ans_posi[char_set[i]] = step;

            for(auto iter = gra[char_set[i]].begin();iter != gra[char_set[i]].end();iter++){
                if(vis_char[*iter] == 0)continue;
                now_ans = max(now_ans, abs(step - ans_posi[*iter]));
            }
            
            dfs(step + 1 ,now_ans);
            vis_char[char_set[i]] = 0;
        }
    }
}

int main()
{
    char c[1000];
    while(!(fgets(c,1000,stdin)==NULL||c[0] == '#'))
    {
        memset(vis,0,sizeof(vis));
        char_number = 0;
        band_width = 100;
        for(int i = 0;i < 26;i++)gra[i].clear();
        int i = 0;
        while(i < strlen(c)){   // 注意自己判断一下开头和结尾的问题
            int g_point1 , colon_char_posi;

            for(;i < strlen(c);i++){
                // cout<<i<<endl;
                if('A'<=c[i] && c[i] <='Z' && vis[(int)(c[i] - 'A')] == 0){
                    vis[(int)(c[i] - 'A')] = 1;
                    char_set[char_number] = c[i] - 'A';
                    char_number++;
                    // printf("%d %d\n",char_number, vis[int(c[i] - 'A')]);
                }
                if(c[i] == ':'){
                    g_point1 = c[i-1] - 'A';
                    colon_char_posi = i + 1;
                }
                if(c[i] == ';'){
                    i++;
                    break;
                }
            }
            for(;colon_char_posi < i;colon_char_posi++){
                if(!('A' <= c[colon_char_posi] && c[colon_char_posi] <= 'Z'))break;
                gra[c[colon_char_posi] - 'A'].push_back(g_point1);
                gra[g_point1].push_back(c[colon_char_posi] - 'A');
                // printf("%d %d\n",g_point1, c[colon_char_posi] - 'A');
            }

        }
        sort(char_set, char_set + char_number);
        dfs(0,0);
        // printf("%d",band_width);
        for(int i = 0;i < char_number;i++){
            printf("%c ",ans[i] + 'A');
        }
        printf("-> %d\n",band_width);
        // printf("%s",c);

    }
    return 0;
}