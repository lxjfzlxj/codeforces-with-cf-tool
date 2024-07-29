# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int a[N],t[N];
bool ok[N];
bool check(int a,int b,int c) {
    return a+b>c;
}
bool work(int *a,int n) {
    std::sort(a+1,a+n+1);
    int i,mn=2e9,mx=0;
    for(i=1;i+2<=n;i++) {
        ok[i]=check(a[i],a[i+1],a[i+2]);
        if(ok[i]) mn=std::min(mn,i), mx=std::max(mx,i);
    }
    if(mx-mn>=3) return true;
    for(i=1;i+5<=n;i++) {
        if(check(a[i],a[i+1],a[i+2]) && check(a[i+3],a[i+4],a[i+5])) return true;
        if(check(a[i],a[i+1],a[i+3]) && check(a[i+2],a[i+4],a[i+5])) return true;
        if(check(a[i],a[i+1],a[i+4]) && check(a[i+2],a[i+3],a[i+5])) return true;
        if(check(a[i],a[i+1],a[i+5]) && check(a[i+2],a[i+3],a[i+4])) return true;
        if(check(a[i],a[i+2],a[i+3]) && check(a[i+1],a[i+4],a[i+5])) return true;
        if(check(a[i],a[i+2],a[i+4]) && check(a[i+1],a[i+3],a[i+5])) return true;
        if(check(a[i],a[i+2],a[i+5]) && check(a[i+1],a[i+3],a[i+4])) return true;
        if(check(a[i],a[i+3],a[i+4]) && check(a[i+1],a[i+2],a[i+5])) return true;
        if(check(a[i],a[i+3],a[i+5]) && check(a[i+1],a[i+2],a[i+4])) return true;
        if(check(a[i],a[i+4],a[i+5]) && check(a[i+1],a[i+2],a[i+3])) return true;
    }
    return false;
}
void _() {
    int n,q,i,l,r;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) scanf("%d",a+i);
    while(q--) {
        scanf("%d%d",&l,&r);
        if(r-l+1>=300) puts("YES");
        else {
            for(i=l;i<=r;i++) t[i-l+1]=a[i];
            puts(work(t,r-l+1)?"YES":"NO");
        }
    }
}

int main() {
    int T=1;
    // scanf("%d",&T);
    while(T--) _();
    return 0;
}
