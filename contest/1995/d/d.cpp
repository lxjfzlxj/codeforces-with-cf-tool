# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N ((1<<18)|10)
# define C 20
char s[N];
std::vector<int> vec[C];
int n,dis[N],f[N],lg2[N],ppcnt[N],pre[N][C],suf[N][C],g[N];
struct pair{
    int c,pos;
};
void _() {
    int c,k,i,j,tot,ans=2e9;
    scanf("%d%d%d%s",&n,&c,&k,s+1); tot=1<<c;
    for(i=1;i<=c;i++) vec[i].clear();
    for(i=1;i<=n;i++) vec[s[i]-'A'+1].push_back(i);
    for(i=2;i<tot;i++) lg2[i]=lg2[i>>1]+1;
    for(i=1;i<tot;i++) ppcnt[i]=ppcnt[i>>1]+(i&1);
    for(i=1;i<=n;i++) {
        memcpy(pre[i],pre[i-1],sizeof(pre[i]));
        pre[i][s[i]-'A'+1]=i;
    }
    for(j=1;j<=c;j++) suf[n+1][j]=n+1;
    for(i=n;i>=1;i--) {
        memcpy(suf[i],suf[i+1],sizeof(suf[i]));
        suf[i][s[i]-'A'+1]=i;
    }
    for(i=0;i<tot;i++) g[i]=0;
    for(i=1;i<=n;i++) g[1<<s[i]-'A']=1;
    for(i=1;i<n;i++) {
        pair lp[C],rp[C];
        for(j=1;j<=c;j++) {
            lp[j]=(pair){j,pre[i][j]};
            rp[j]=(pair){j,suf[i+1][j]};
        }
        std::sort(lp+1,lp+c+1,[](const pair &i,const pair &j){return i.pos<j.pos;});
        std::sort(rp+1,rp+c+1,[](const pair &i,const pair &j){return i.pos<j.pos;});
        int zt1=0,zt2;
        lp[0].pos=0; rp[c+1].pos=n+1;
        for(j=c;j>=1 && lp[j].pos;j--) {
            zt1|=1<<lp[j].c-1; zt2=zt1;
            for(int l=1;l<=c && rp[l].pos!=n+1;l++) {
                zt2|=1<<rp[l].c-1;
                g[zt1|zt2]=std::max(g[zt1|zt2],rp[l+1].pos-lp[j-1].pos-1);
            } 
        }
    }
    for(i=1;i<tot;i++) {
        for(j=1;j<=c;j++) if((i>>j-1)&1) {
            g[i]=std::max(g[i],g[i^(1<<j-1)]);
        }
    }
    for(i=1;i<tot;i++) if((i>>(s[n]-'A'))&1) {
        f[i]=g[(tot-1)^i]+1;
    }
    for(i=1;i<tot;i++) if((i>>(s[n]-'A'))&1) {
        if(f[i]<=k) ans=std::min(ans,ppcnt[i]);
    }
    printf("%d\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
