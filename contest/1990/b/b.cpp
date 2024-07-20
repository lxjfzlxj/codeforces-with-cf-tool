# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 100010
int ans[N];
void _() {
    int n,i,x,y,v;
    scanf("%d%d%d",&n,&x,&y);
    for(i=y-1,v=-1;i>=1;i--,v=-v) ans[i]=v;
    for(i=y;i<=x;i++) ans[i]=1;
    for(i=x+1,v=-1;i<=n;i++,v=-v) ans[i]=v;
    for(i=1;i<=n;i++) printf("%d ",ans[i]);
    puts("");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
