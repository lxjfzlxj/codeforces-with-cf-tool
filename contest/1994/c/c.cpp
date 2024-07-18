# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
# define N 200010
int a[N],to[N],f[N];
long long sum[N];
void _() {
    int n,m,i;
    long long ans=0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",a+i), sum[i]=sum[i-1]+a[i];
    for(i=0;i<=n;i++) {
        to[i]=std::upper_bound(sum,sum+n+1,sum[i]+m)-sum;
    }
    f[n+1]=0;
    for(i=n;i>=0;i--) f[i]=f[to[i]]+1;
    for(i=0;i<n;i++) ans+=n-i-f[i]+1;
    printf("%lld\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
