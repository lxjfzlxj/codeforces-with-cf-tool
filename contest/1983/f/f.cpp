# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
# define N 100010
int a[N],n,ch[N*40][2],val[N*40],cnt[N*40],xo[N*40],tot;
long long k;
void pushup(int dep,int x) {
    val[x]=2e9;
    if(dep<0 && cnt[x]>=2) val[x]=0;
    if(ch[x][0]) val[x]=std::min(val[x],val[ch[x][0]]);
    if(ch[x][1]) val[x]=std::min(val[x],val[ch[x][1]]);
    if(cnt[ch[x][0]]==1 && cnt[ch[x][1]]==1) val[x]=std::min(val[x],xo[ch[x][0]]^xo[ch[x][1]]);
}
void ins(int x,int dep,int v) {
    if(dep>=0) {
        int bit=(v>>dep)&1;
        if(!ch[x][bit]) ch[x][bit]=++tot;
        ins(ch[x][bit],dep-1,v);
    }
    cnt[x]++;
    xo[x]^=v;
    pushup(dep,x);
}
void del(int x,int dep,int v) {
    if(dep>=0) {
        int bit=(v>>dep)&1;
        del(ch[x][bit],dep-1,v);
        if(!cnt[ch[x][bit]]) ch[x][bit]=0;
    }
    cnt[x]--;
    xo[x]^=v;
    pushup(dep,x);
}
bool check(int mid) {
    int i,j;
    long long cnt=0;
    tot=1; val[1]=2e9;
    for(i=j=1;i<=n;i++) {
        while(j<=n && val[1]>mid) {
            ins(1,30,a[j]);
            j++;
        }
        // printf("%d:%d %d\n",i,j,val[1]);
        if(val[1]<=mid) cnt+=n-j+2;
        del(1,30,a[i]);
    }
    // printf("%d cnt:%lld\n",mid,cnt);
    return cnt>=k;
}
void _() {
    int i,r=0,l,mid;
    scanf("%d%lld",&n,&k);
    for(i=1;i<=n;i++) scanf("%d",a+i), r=std::max(r,a[i]);
    l=0; r<<=1;
    while(l<r) {
        mid=(0ll+l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    // check(4);
    printf("%d\n",l);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
