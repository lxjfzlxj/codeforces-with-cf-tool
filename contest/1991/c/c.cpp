# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int n,a[N],ans[111],ans_n;
bool iszero() {
    int i;
    for(i=1;i<=n && a[i]==0;i++);
    // printf("iszero:%d\n",i>n);
    return i>n;
}
int get() {
    int i,mx=0,mn=2e9;
    for(i=1;i<=n;i++) mx=std::max(mx,a[i]), mn=std::min(mn,a[i]);
    int ans=(mx+mn)/2;
    for(i=1;i<=n;i++) a[i]=std::abs(a[i]-ans);
    return ans;
}
void _() {
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",a+i);
    ans_n=0;
    while(!iszero()) {
        ans[++ans_n]=get();
        if(ans[ans_n]==0) report("-1\n");
    }
    printf("%d\n",ans_n);
    for(i=1;i<=ans_n;i++) printf("%d ",ans[i]);
    puts("");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
