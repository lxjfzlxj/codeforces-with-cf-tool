# include <bits/stdc++.h> 
# define report(args...) return printf(args), void()
# define N 5010
std::vector<int> e1[N],e2[N];
bool mark[N];
int B,f[N],fat[N],leaf;
void dfs(int x,int fa) {
    f[x]=1; fat[x]=fa;
    if(e1[x].size()==1 && x>1) leaf=x;
    for(auto v:e1[x]) if(v!=fa) {
        dfs(v,x);
        f[x]=std::max(f[x],f[v]+1);
    }
    if(f[x]>=B) mark[x]=true, f[x]=0;
}
void con(int x,int fa,int las) {
    if(x>1 && mark[x]) e2[las].push_back(x);
    if(mark[x]) las=x;
    for(auto v:e1[x]) if(v!=fa) {
        con(v,x,las);
    }
}
bool ask(int x) {
    printf("? %d\n",x); fflush(stdout);
    int ans;
    scanf("%d",&ans);
    return ans;
}
bool isfound;
void reply(int x) {
    printf("! %d\n",x); fflush(stdout);
    isfound=true;
}
void work(int x) {
    for(auto v:e2[x]) {
        if(isfound) return;
        if(ask(v)) work(v);
    }
    if(!isfound) {
        if(ask(leaf)) reply(leaf);
        else {
            int l,r,i,mid,siz;
            for(i=1;i<B;i++) ask(leaf);
            std::vector<int> t;
            while(x!=1) {
                t.push_back(fat[x]);
                x=fat[x];
            }
            siz=t.size();
            if(siz<=1) reply(1);
            else {
                l=0; r=siz-1;
                while(r-l>1) {
                    mid=l+r>>1;
                    if(ask(t[mid])) r=mid;
                    else {
                        l=mid+1;
                        r=std::min(r+1,siz-1);
                    }
                }
                if(l==r) reply(1);
                else {
                    if(ask(t[l])) reply(t[l]);
                    else reply(fat[t[r]]);
                }
            }
        }
    }
}
void _() {
    int n,i,x,y;
    scanf("%d",&n); B=sqrt(n);
    for(i=1;i<=n;i++) e1[i].clear(), e2[i].clear();
    for(i=1;i<n;i++) {
        scanf("%d%d",&x,&y);
        e1[x].push_back(y);
        e1[y].push_back(x);
    }
    memset(mark,false,n+5);
    dfs(1,1); mark[1]=true; con(1,1,0);
    isfound=false;
    work(1);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
