# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],f[N];
std::vector<int> e[N];
void dfs(int x) {
    if(e[x].empty()) {
        f[x]=a[x];
        return;
    }
    int mn=2e9;
    for(auto v:e[x]) {
        dfs(v);
        mn=std::min(mn,f[v]);
    }
    if(a[x]>=mn) f[x]=mn;
    else f[x]=(a[x]+mn)/2;
    if(x==1) printf("%d\n",a[1]+mn);
}
void _() {
    int n,i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",a+i), e[i].clear();
    for(i=2;i<=n;i++) {
        scanf("%d",&x);
        e[x].push_back(i);
    }
    dfs(1);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
