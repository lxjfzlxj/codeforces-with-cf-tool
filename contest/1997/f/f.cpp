# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 1010
# define MOD 998244353
int fib[30],f[N][55*N],g[55*N];
void inc(int &x,int y) {(x+=y)>=MOD?x-=MOD:0;}
void _() {
    int n,x,m,i,j,k,ans=0,mx;
    scanf("%d%d%d",&n,&x,&m);
    fib[1]=fib[2]=1;
    for(i=3;i<=25;i++) fib[i]=fib[i-1]+fib[i-2];
    mx=fib[x]*n;
    f[0][0]=1;
    for(i=1;i<=x;i++) {
        for(j=1;j<=n;j++) {
            for(k=fib[i];k<=n*fib[i];k++) inc(f[j][k],f[j-1][k-fib[i]]);
        }
    }
    memset(g,63,sizeof(g));
    g[0]=0;
    for(i=0;i<mx;i++) {
        for(j=1;i+fib[j]<=mx;j++) g[i+fib[j]]=std::min(g[i+fib[j]],g[i]+1);
    }
    for(j=0;j<=n*fib[x];j++) {
        if(g[j]==m) inc(ans,f[n][j]);
    }
    printf("%d\n",ans);
}

int main() {
    int T=1;
    // scanf("%d",&T);
    while(T--) _();
    return 0;
}
