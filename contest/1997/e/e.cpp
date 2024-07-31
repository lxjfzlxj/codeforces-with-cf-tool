# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],rt[N],tot=0;
std::vector<int> e[N],veq[N];
bool ans[N];
struct node{
    int ls,rs,sum;
}tr[N*40];
struct query{
    int id,k;
}qu[N];
void build(int &x,int l,int r) {
    if(!x) x=++tot;
    if(l==r) return;
    int mid=l+r>>1;
    build(tr[x].ls,l,mid);
    build(tr[x].rs,mid+1,r);
}
void update(int &x,int y,int l,int r,int pos) {
    x=++tot; tr[x]=tr[y];
    if(l==r) {
        tr[x].sum=1;
        return;
    }
    int mid=l+r>>1;
    if(pos<=mid) update(tr[x].ls,tr[y].ls,l,mid,pos);
    else update(tr[x].rs,tr[y].rs,mid+1,r,pos);
    tr[x].sum=tr[tr[x].ls].sum+tr[tr[x].rs].sum;
}
int query(int x,int xl,int xr,int ql,int qr) {
    assert(x);
    if(ql>qr) return 0;
    if(ql<=xl && xr<=qr) return tr[x].sum;
    int mid=xl+xr>>1,ans=0;
    if(ql<=mid) ans+=query(tr[x].ls,xl,mid,ql,qr);
    if(qr>mid) ans+=query(tr[x].rs,mid+1,xr,ql,qr);
    return ans;
}
int binary(int x,int l,int r,int val) {
    if(l==r) {
        if(tr[x].sum>=val) return l;
        else return l+1;
    }
    int mid=l+r>>1;
    if(val<=tr[tr[x].ls].sum) return binary(tr[x].ls,l,mid,val);
    else return binary(tr[x].rs,mid+1,r,val-tr[tr[x].ls].sum);
}
std::vector<int> tm;
void _() {
    int n,q,i,k,las,now,level;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) {
        scanf("%d",a+i);
        e[a[i]].push_back(i);
    }
    build(rt[200001],1,n);
    for(i=200000;i>=1;i--) {
        las=rt[i]=rt[i+1];
        for(auto pos:e[i]) update(rt[i],las,1,n,pos), las=rt[i];
    }
    for(i=1;i<=q;i++) {
        scanf("%d%d",&qu[i].id,&qu[i].k);
        veq[qu[i].k].push_back(i);
    }
    for(k=1;k<=n;k++) {
        now=1; level=1;
        tm.clear(); tm.push_back(0);
        while(now<=n) {
            tm.push_back(now);
            int sumnow1=query(rt[level],1,n,1,now-1);
            now=binary(rt[level],1,n,sumnow1+k)+1;
            level++;
        }
        for(auto qid:veq[k]) {
            level=std::upper_bound(tm.begin(),tm.end(),qu[qid].id)-tm.begin()-1;
            ans[qid]=(a[qu[qid].id]>=level);
        }
    }
    for(i=1;i<=q;i++) puts(ans[i]?"YES":"NO");
}

int main() {
    int T=1;
    // scanf("%d",&T);
    while(T--) _();
    return 0;
}
