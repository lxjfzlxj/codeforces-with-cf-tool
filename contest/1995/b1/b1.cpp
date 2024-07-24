# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N];
void _() {
    int n,i,j;
    long long m,ans=0,sum=0;
    scanf("%d%lld",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",a+i);
    std::sort(a+1,a+n+1);
    for(i=j=1;i<=n;i++) {
        while(j<=n && a[j]-a[i]<=1 && sum+a[j]<=m) sum+=a[j], j++;
        ans=std::max(ans,sum);
        sum-=a[i];
    }
    printf("%lld\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
