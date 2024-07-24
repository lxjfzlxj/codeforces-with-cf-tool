// # include <bits/stdc++.h>
// # define report(args...) return printf(args), void()
// # define N 200010
// struct pair{
//     int p,cnt;
// }a[N];
// void _() {
//     int n,i;
//     long long m,ans=0;
//     scanf("%d%lld",&n,&m);
//     for(i=1;i<=n;i++) scanf("%d",&a[i].p);
//     for(i=1;i<=n;i++) scanf("%d",&a[i].cnt);
//     std::sort(a+1,a+n+1,[](const pair &i,const pair &j){return i.p<j.p;});
//     for(i=1;i<=n;i++) {
//         ans=std::max(ans,std::min(m/a[i].p,1ll*a[i].cnt)*a[i].p);
//     }
//     for(i=1;i<n;i++) if(a[i+1].p<=a[i].p+1) {
//         long long xc,yc;
//         xc=std::min(1ll*a[i].cnt,m/a[i].p);
//         yc=std::min(1ll*a[i+1].cnt,(m-xc*a[i].p)/a[i+1].p);
        
//         // printf("%d: %lld %lld\n",i,xc,yc);
//         long long cj=m-xc*a[i].p-yc*a[i+1].p;
//         if(yc+cj<=a[i+1].cnt && xc>=cj) report("%lld\n",m);
//         else ans=std::max(ans,m-cj+std::min(a[i+1].cnt-yc,xc));
//     }
//     printf("%lld\n",ans);
// }

// int main() {
//     int T=1;
//     scanf("%d",&T);
//     while(T--) _();
//     return 0;
// }
# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
struct pair{
    int p,cnt;
}a[N];
void _() {
    int n,i;
    long long m,ans=0;
    scanf("%d%lld",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i].p);
    for(i=1;i<=n;i++) scanf("%d",&a[i].cnt);
    std::sort(a+1,a+n+1,[](const pair &i,const pair &j){return i.p<j.p;});
    for(i=1;i<=n;i++) {
        ans=std::max(ans,std::min(m/a[i].p,1ll*a[i].cnt)*a[i].p);
    }
    for(i=1;i<n;i++) if(a[i+1].p<=a[i].p+1) {
        long long xc,yc;
        xc=std::min(1ll*a[i].cnt,m/a[i].p);
        yc=std::min(1ll*a[i+1].cnt,(m-xc*a[i].p)/a[i+1].p);
        
        // printf("%d: %lld %lld\n",i,xc,yc);
        long long cj=m-xc*a[i].p-yc*a[i+1].p;
        int mn=std::min(a[i+1].cnt-yc,xc);
        printf("%d:%d %d:%d\n",a[i].p,xc-mn,a[i+1].p,yc+mn);
        if(yc+cj<=a[i+1].cnt && xc>=cj) report("%lld\n",m);
        else ans=std::max(ans,m-cj+std::min(a[i+1].cnt-yc,xc));
        if(ans==10000) puts("--");
    }
    printf("%lld\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
