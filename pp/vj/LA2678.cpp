#include<iostream>

using namespace std;
int input[(int)1e6+7];
int main()
{
    int n;
    long long m;
    while(scanf("%d%lld",&n,&m) == 2){
        long long sum = 0;
        int ans = n+1, temp_ans = 0,first = 0;
        for(int i=0;i<n;i++){
            scanf("%d",&input[i]);
            sum += input[i];
            temp_ans += 1;
            while( sum >= m ){
                ans = min(ans, temp_ans);

                sum -= input[first];
                temp_ans -= 1;
                first++;
            }
        }
        printf("%d\n",ans == n+1 ? 0:ans);
    }
    return 0;
}