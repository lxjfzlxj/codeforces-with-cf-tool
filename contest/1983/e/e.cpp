# include <bits/stdc++.h>
# define MOD 1000000007
# define N 400010
int a[N];
int qpow(int x,int p) {
	int res=1;
	while(p) {
		if(p&1) res=1ll*res*x%MOD;
		x=1ll*x*x%MOD; p>>=1;
	}
	return res;
}
void _() {
	int n,k,i,pq,ans=0,pq2,sum=0;
	scanf("%d%d",&n,&k); pq=1ll*((n-k+1)/2)*qpow(n-k,MOD-2)%MOD;
	pq2=1ll*((n-k+2)/2)*qpow(n-k+1,MOD-2)%MOD;
	for(i=1;i<=n;i++) scanf("%d",a+i), sum=(sum+a[i])%MOD;
	for(i=1;i<=k;i++) {
		ans=(1ll*pq2*a[i]+ans)%MOD;
	} 
	for(i=k+1;i<=n;i++) {
		ans=(1ll*pq*a[i]+ans)%MOD;
	}
	printf("%d %d\n",ans,(sum-ans+MOD)%MOD);
}

int main() {
	int T=1;
	scanf("%d",&T);
	while(T--) _();
	return 0;
}   