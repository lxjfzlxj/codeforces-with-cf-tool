# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
# define N 300010
long long a[N],f[N][30];
std::vector<int> e[N];
long long pre[30],suf[30];
void dfs(int x,int fa) {
    int i;
    for(i=0;i<=20;i++) f[x][i]=a[x]*i;
    for(auto v:e[x]) if(v!=fa) {
        dfs(v,x);
        for(i=0;i<=20;i++) f[x][i]+=f[v][i];
    }
    pre[0]=f[x][0]; suf[20]=f[x][20];
    for(i=1;i<=20;i++) pre[i]=std::min(pre[i-1],f[x][i]);
    for(i=19;i>=0;i--) suf[i]=std::min(suf[i+1],f[x][i]);
    f[x][0]=suf[1]; f[x][20]=pre[19];
    for(i=1;i<=19;i++) f[x][i]=std::min(pre[i-1],suf[i+1]);
}

void _() {
    int n,i,x,y;
    long long sum=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%lld",a+i), sum+=a[i], e[i].clear();
    for(i=1;i<n;i++) {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,0);
    long long ans=9e18;
    for(i=0;i<=20;i++) ans=std::min(ans,f[1][i]);
    printf("%lld\n",sum+ans); 
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}