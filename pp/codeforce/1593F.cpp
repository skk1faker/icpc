

// 注意这个题目ans不能用string，不然慢的离谱！

#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int maxx = 45;
int dp[2][maxx][maxx][maxx];		// posi %A %B num_Red
int number[maxx];
short ans[2][maxx][maxx][maxx][maxx];
int main()
{
	int T;
	cin>>T;
	while(T--){
		int	n,A,B;
		scanf("%d%d%d",&n,&A,&B);		// A ->Red
		memset(dp,0,sizeof(dp));
		/*
		for(int i=0;i<n;i++){
			for(int modA =0; modA<A;modA++){
				for(int modB=0;modB<B;modB++){
					for(int num_red=0;num_red<=n;num_red++){
						dp[][][][]=0;
					}
				}
			}
		}
		*/

		for (int i=0 ;i<n ;i++){
			char temp;
			do{
				temp = getchar();
			}while(!isdigit(temp));
			number[i] = temp - '0';
		}
		
		dp[0][number[0]%A][0][1] = 1;
		dp[0][0][number[0]%B][0] = 1;
		ans[0][number[0]%A][0][1][0] = 0;	//0 - >R
		ans[0][0][number[0]%B][0][0] = 1;	//1 - >B
		
		for(int posi =1 ; posi < n;posi++){
			memset(dp[posi%2],0,sizeof(dp[posi%2]));
			for(int modA = 0;modA < A; modA++){
				for(int modB = 0;modB < B; modB++){
					for(int num_red = 0;num_red <= posi; num_red++){
						if(dp[(posi-1)%2][modA][modB][num_red] == 1){
							// color == Red
							dp[(posi)%2][(number[posi] +modA*10) % A][modB][num_red+1] = 1;
							for(int i=0;i<posi;i++){
								ans[posi%2][(number[posi] + modA*10) % A][modB][num_red+1][i] = ans[(posi-1)%2][modA][modB][num_red][i];
							}
							
							ans[posi%2][(number[posi] + modA*10) % A][modB][num_red+1][posi] = 0;
							// color == Black
							dp[posi%2][modA][(number[posi]+modB*10) % B][num_red] = 1;
							for(int i=0;i<posi;i++){
								ans[posi%2][modA][(number[posi]+modB*10) % B][num_red][i] = ans[(posi-1)%2][modA][modB][num_red][i];
							}

							ans[posi%2][modA][(number[posi]+modB*10) % B][num_red][posi] = 1;

						}

					}
				}
			}
		}
		

		//get ans
		char flag =false;
		for(int i=(n+1)/2;i>=1;i--){

			int num_red[2] = {i, n-i};
			char output[3]="RB";
			for(int p =0 ;p <2;p++)
				if(dp[(n-1)%2][0][0][num_red[p]] == 1){
					flag = true;
					//printf("%s\n",ans[n-1][0][0][num_red[p]].c_str());
					for(int i=0;i<n;i++){
						printf("%c",output[ans[(n-1)%2][0][0][num_red[p]][i]]);
					}
					printf("\n");
					break;
				}
			if(flag)break;

		}
		if(!flag){
			printf("-1\n");
		}
	


	}
	return 0;
}





















/*
/f[i][j][k][l]:计算到第i个数字，红色的余数j，黑色的余数k，目前的红色数m
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const short N=41;
short t,n,x,y,a[N];
char ch[N];
struct node {
    bool val;
    short ans[N];//1红，2黑
} f[N][N][N][N];
signed main() {
    cin>>t;
    while(t--) {
        cin>>n>>x>>y;
        scanf("%s",ch+1);
        For(i,1,n) a[i]=ch[i]-'0';
        memset(f,0,sizeof f);
        f[0][0][0][0].val=1;
        For(i,1,n) For(j,0,x-1) For(k,0,y-1) For(m,0,i-1) {
            if(f[i-1][j][k][m].val==1) {
                f[i][(j*10+a[i])%x][k][m+1].val=1;
                For(l,1,i-1) f[i][(j*10+a[i])%x][k][m+1].ans[l]=f[i-1][j][k][m].ans[l];
                f[i][(j*10+a[i])%x][k][m+1].ans[i]=1;
                f[i][j][(k*10+a[i])%y][m].val=1;
                For(l,1,i-1) f[i][j][(k*10+a[i])%y][m].ans[l]=f[i-1][j][k][m].ans[l];
                f[i][j][(k*10+a[i])%y][m].ans[i]=2;
            }
        }
        bool flag=0;
        for(int i=(n+1)/2;i>=1;i--) {
            if(f[n][0][0][i].ans[1]!=0) {
                flag=1;
                For(j,1,n) if(f[n][0][0][i].ans[j]==1) cout<<"R"; else cout<<"B";
                puts("");
                break;
            }
            if(f[n][0][0][n-i].ans[1]!=0) {
                flag=1;
                For(j,1,n) if(f[n][0][0][n-i].ans[j]==1) cout<<"R"; else cout<<"B";
                puts("");
                break;
            }
        }
        if(flag==0) puts("-1");
    }
    return 0;
}

*/
