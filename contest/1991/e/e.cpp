# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 10010
std::vector<int> e[N],cc[3];
bool vis[N],col[N],no;
void print(int x,int y) {
    printf("%d %d\n",x,y);
    fflush(stdout);
}
void dfs(int x,int c) {
    vis[x]=true; col[x]=c;
    cc[c+1].push_back(x);
    // printf("%d:%d\n",c+1,x); 
    if(no) return;
    for(auto v:e[x]) {
        if(!vis[v]) dfs(v,c^1);
        else if(col[v]==col[x]) no=true;
    }
}
void _() {
    int n,m,i,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) e[i].clear();
    for(i=1;i<=m;i++) {
        scanf("%d%d",&x,&y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    memset(vis,false,n+5);
    no=false;
    cc[1].clear(); cc[2].clear();
    for(i=1;i<=n && !no;i++) {
        if(!vis[i]) dfs(i,0);
    }
    if(no) {
        puts("Alice"); fflush(stdout);
        for(i=1;i<=n;i++) print(1,2), scanf("%*d%*d");
    } else {
        puts("Bob"); fflush(stdout);
        for(i=1;i<=n;i++) {
            scanf("%d%d",&x,&y);
            if((x==1 || y==1) && !cc[1].empty()) print(cc[1].back(),1), cc[1].pop_back();
            else if((x==2 || y==2) && !cc[2].empty()) print(cc[2].back(),2), cc[2].pop_back();
            else {
                if(!cc[1].empty()) print(cc[1].back(),3), cc[1].pop_back();
                else print(cc[2].back(),3), cc[2].pop_back();
            }
        }
    }
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
