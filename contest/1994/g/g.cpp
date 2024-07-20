# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
# define N 2000010
std::string s,a[N];
int n,cnt[N];
std::vector<bool> f[N],vis[N],fr[N];
void clr_resize(std::vector<bool> &vis,int k) {
    std::vector<bool> tp;
    std::swap(vis,tp);
    vis.resize(k);
}
bool solve(int now,int rest) {
    int i;
    if(now<0) return rest==0;
    if(vis[now][rest]) return f[now][rest];
    vis[now][rest]=true;
    bool ans=false;
    if(((rest&1)^(cnt[now]&1))==s[now]-'0' && solve(now-1,(rest+cnt[now])/2)) {
        ans=true; fr[now][rest]=0;
    }
    if(((rest&1)^((n-cnt[now])&1))==s[now]-'0' && solve(now-1,(rest+n-cnt[now])/2)) {
        ans=true; fr[now][rest]=1;
    }
    // printf("%d %d: %d\n",now,rest,ans);
    return f[now][rest]=ans;
}
void print(int now,int rest) {
    if(now<0) return;
    if(fr[now][rest]==0) {
        print(now-1,(rest+cnt[now])/2);
        putchar('0');
    } else {
        print(now-1,(rest+n-cnt[now])/2);
        putchar('1');
    }
}
void _() {
    int k,i,j;
    std::cin>>n>>k>>s;
    for(i=0;i<k;i++) cnt[i]=0;
    for(i=1;i<=n;i++) {
        std::cin>>a[i];
        for(j=0;j<k;j++) {
            if(a[i][j]=='1') cnt[j]++;
        }
    }
    for(i=0;i<k;i++) {
        f[i].resize(n+1);
        clr_resize(vis[i],n+1);
        fr[i].resize(n+1);
    }
    // for(i=0;i<k;i++) printf("%d ",cnt[i]); puts("");
    if(!solve(k-1,0)) puts("-1");
    else print(k-1,0), puts("");
}

int main() {
    int T=1;
    std::ios::sync_with_stdio(false);
    std::cin>>T;
    while(T--) _();
    return 0;
}