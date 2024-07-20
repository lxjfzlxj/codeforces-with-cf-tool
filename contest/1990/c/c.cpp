# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int n,a[N],buc[N],b[N];
long long sum[N];
long long work() {
    int i,mx=0;
    long long sum=0;
    for(i=1;i<=n;i++) {
        sum+=a[i];
        buc[a[i]]++;
        if(buc[a[i]]==2) mx=std::max(mx,a[i]);
        b[i]=mx;
    }
    for(i=1;i<=n;i++) buc[a[i]]--;
    for(i=1;i<=n;i++) a[i]=b[i];
    return sum;
}
void _() {
    int i;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",a+i);
    ans+=work(); ans+=work();
    // for(i=1;i<=n;i++) printf("%d ",a[i]); puts("");
    for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(i=1;i<=n;i++) ans+=sum[i];
    printf("%lld\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
