# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 500010
int deg[N],ans_n,e_n,fir[N],anse[N],ans[N],dfn[N],dfnn;
bool vis[N],ban[N];
struct edge{
    int fr,nex,to,c;
}e[N<<1];
void add(int x,int y,int c) {
    e[++e_n]=(edge){x,fir[x],y,c}; fir[x]=e_n;
    e[++e_n]=(edge){y,fir[y],x,c}; fir[y]=e_n;
}
void dfs(int x) {
    int i,anc=0,toanc;
    vis[x]=true; dfn[x]=++dfnn;
    for(i=fir[x];i;i=e[i].nex) if(!e[i].c) {
        if(!vis[e[i].to]) dfs(e[i].to);
        else if(dfn[e[i].to]<dfn[x]) {
            anc=e[i].to; toanc=i>>1;
        }
    }
    if((deg[x]&1) && anc) {
        deg[x]^=1; deg[anc]^=1;
        ban[toanc]=true;
    }
}
void euler(int x) {
    for(int &i=fir[x];i;i=e[i].nex) if(!ban[i>>1] && !vis[i>>1]) {
        vis[i>>1]=true;
        int tp=i;
        euler(e[i].to);
        anse[++ans_n]=tp;
    }
}
void _() {
    int n,m,i,x,y,c,st;
    scanf("%d%d",&n,&m);
    memset(deg,0,n+5<<2);
    memset(fir,0,n+5<<2); e_n=1;
    for(i=1;i<=m;i++) {
        scanf("%d%d%d",&x,&y,&c);
        add(x,y,c);
        deg[x]++; deg[y]++;
        if(c==1) st=x;
    }
    memset(vis,false,n+5);
    memset(ban,false,m+5);
    dfnn=0;
    for(i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i);
            if(deg[i]&1) report("NO\n");
        }
    }
    puts("YES");
    memset(vis,false,m+5);
    ans_n=0; euler(st);
    ans[0]=st;
    for(i=1;i<=ans_n;i++) {
        if(e[anse[i]].fr==ans[i-1]) ans[i]=e[anse[i]].to;
        else ans[i]=e[anse[i]].fr;
    }
    printf("%d\n",ans_n);
    for(i=0;i<=ans_n;i++) printf("%d ",ans[i]);
    puts("");
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
