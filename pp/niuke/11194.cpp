#include <bits/stdc++.h>
#define LL __int128
using namespace std;
void output(LL x)
{
    if(x<0)putchar('-'),x=-x;
    if(x>9)output(x/10);
    putchar(x%10+'0');
}
LL sum2(LL x)
{
    return x*x*(x-1)-(x-1)*x*(2*x-1)/6;
}
LL int128pow(LL x , int k)
{
    LL ans = 1;
    LL temp = x;
    while(k){
        if(k%2){
            ans*=temp;
        }
        k/=2;
        temp *= temp;
    }
    return ans;
}
int main()
{
    long long temp_l,temp_r,k;
    while(scanf("%lld%lld%lld",&temp_l,&temp_r,&k) == 3){
        LL l,r;
        l = temp_l;
        r = temp_r;
        if(k==1){
            output((l+r)*(r-l+1)/2);
            putchar('\n');
        }
        else if(k == 2){//实际上这里是在计算空白区域
            LL sql,sqr;
            sql = pow(temp_l,0.5);
            sqr = pow(temp_r,0.5);
            LL ans = sum2(sqr)-sum2(sql);
            ans += (r-(sqr*sqr)+1)*sqr;
            ans -= (l-1-(sql*sql)+1)*sql;
            output(ans);
            cout<<endl;
        }
        else {
            LL sql,sqr,ans=0;
            sql = (float)pow(temp_l,1.0/k);
            sqr = (float)pow(temp_r,1.0/k);
            for(LL i=sql ;i<sqr;i++){
                ans += i*(int128pow(i+1,k)-int128pow(i,k));
            }
            ans += (r-(int128pow(sqr,k))+1)*sqr;
            ans -= (l-int128pow(sql,k))*sql;
            output(ans);
            cout<<endl;

        }
    }
}



















/*


#include <bits/stdc++.h>
 
using namespace std;
typedef __int128 LL;
 
const int N = 1e5+5;
 
LL sum1(LL x)
{
    return (x+1) * x/2;
}
 
LL sum2(long long n) {
    LL x = sqrt((long long)n);
    return x * (x - 1) * (2 * x - 1) / 3 + x * (x - 1) / 2 + x * (n - x * x + 1);
}
 
void print(LL x)
{
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
 
LL pow1(LL a, LL b)
{
    LL tmp = a;
    for(int i = 1; i < b; i ++)
    {
        a = a * tmp;
    }
    return a;
}
 
int main()
{
    long long l, r, k;
    scanf("%lld%lld%lld", &l, &r, &k);
     
    if(k == 1)
    {
        print(sum1(r) - sum1(l-1));
    }
    else if(k == 2)
    {
        print(sum2(r) - sum2(l-1));
    }
    else
    {
        LL ans = 0;
        LL L = pow(l, 1.0/k);
		cout<<"shuchu "<<endl;
		print(L);
		cout<<endl;
        for(L; pow1(L+1, k) < r; L ++)
        {
            LL next = pow1(L+1, k);
//          cout << "next = ";
//          print(next);
//          cout << "val = ";
//          print((next-l)*L);
//          cout << endl;
             
            ans += (next - l) * L;
            l = next;
        }
        LL num = (r - l + 1) * (LL)pow(r, 1.0/k);
        ans += num;
        print(ans);
    }
     
    return 0;
}



/*
#include<iostream>
#include<cmath>
#define LL __int128 
using namespace std;
LL int_pow(LL a,int k)
{
	//calculate a^k
	LL ans = 1;
	LL temp = a;
	while(k)
	{
		if(k%2){
			ans *= temp;
		}
		temp*=temp;
		k/=2;
	}
}
void print(LL x)
{
	if(x<0){
		printf("-");
		x=-x;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
}
int main()
{
	LL l,r;
	int k;
	while(1){
		long long temp_l,temp_r;
		cin>>temp_l>>temp_r>>k;
		l=temp_l;
		r=temp_r;
		float temp = 1/(float)k;
		LL s = (LL)pow(l,temp); 
		LL e = (LL)pow(r,temp);
		LL ans =0;
		if(e==s){
			ans = (r-l+1)*e;
			print(ans);
		}
		else{

			for(LL i = s; i<=e ;i++)
				ans += (int_pow(i+1,k)-int_pow(i,k))*i;
			print(ans-(l-int_pow(s,k))*s-(int_pow(e+1,k)-r-1)*e);
			printf("\n");
		}		

	}
	return 0;
}




/*
//A


#include<iostream>
#include<cstring>
using namespace std;
const int maxx = 300000+5;
int sum[maxx];
char s[maxx];
int main()
{
	int n;
	scanf("%d",&n);
	memset(sum,0,sizeof(sum));
	scanf("%s",s);
	sum[0]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(s[i-1]=='1');
	}
	int ans=0;
	if (sum[n]%2==1){
		cout<<0<<endl;
		return 0;
	}
	for(int S=1;S<=n/2;S++){
		int E=S+n/2-1;
		if((sum[E]-sum[S-1]) == sum[n]/2)ans+=2;

	}
	cout<<ans<<endl;
	
	return 0;
}*/
