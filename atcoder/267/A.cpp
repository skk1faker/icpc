#include<iostream>
#include<cstring>
using namespace std;

const int max_num = 2e5+10;
int sum[max_num];
int p[max_num];
int main()
{
    char aim[max_num];
    scanf("%s",aim + 1);
    int n = strlen(aim+1);
    aim[0] = 0;
    long long ans = 0;
    sum[0] = 0;
    int k = 0;
    for(int i = 1;i <=n-1;i++){
        if(aim[i] == '(' && aim[i+1] == ')'){
            k++;
            p[k] = i;
            sum[k] = sum[k-1] + i;
        }
    }
    p[k+1] = n;
    for(int i = 1;i <= k;i++){
        ans += 2 * (sum[i]) * (p[i+1] - p[i]);
    }
    cout<<ans<<endl;
    return 0;
}