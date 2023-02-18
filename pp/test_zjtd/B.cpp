#include<iostream>
#include<string.h>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

const int maxx = (int)1e5+10;
int raw[maxx];
int sort_finish[maxx];
int temp_sort[maxx];

char get_input(int &ans)
{
    ans = 0;
    char a = '\0';
    do{
        a = getchar();
        ans *=10;
        ans += a - '0';

    }while(!(a <= '9' && a >= '0' ));
    return a;
}
bool row_end(int i, int length_all){
    if(i > length_all - 1)return true;
    return raw[i] > raw[i+1];
}

int main()
{
    char temp_char[2] = {0};
    int length_all = 0;
    while(!(temp_char[0] == '[' && temp_char[1] == '[')){
        temp_char[1] = temp_char[0];
        temp_char[0] = get_input(raw[length_all]);
        ++length_all;
    }
    int start,end, finish_length = 0,row_start_posi = 0;
    cin>>start>>end;

    while(length_all-1 >= row_start_posi){
        sort_finish[finish_length] = raw[row_start_posi];
        finish_length++;
        row_start_posi++;
        if(row_end(row_start_posi,length_all))break;
    }

    while(lenght_all-1 >= row_start_posi ){
        int start_finish = 0;
        do{
            
        }while(!(row_end(row_start_posi,length_all)||start_finish == finish_length - 1));
        if()
    }


}