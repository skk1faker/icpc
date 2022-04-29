

bool solve(int n,int k,int m)
{
	if(k-2<0)return false;
	if(n*(n-1)/2<m)return false;		//最终会产生重边！！
	

}

int main(){
	int n,m,k;
	int T;
	cin>>T;
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		if(solve(n,k,m))printf("YES");
		else printf("NO");

	}
	return 0;

}
