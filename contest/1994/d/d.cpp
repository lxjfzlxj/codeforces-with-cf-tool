# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
# define N 2010
int fa[N],ansx[N],ansy[N];
struct pair{
    int id,x;
}a[N];
int fin(int x) {
    return x==fa[x]?x:fa[x]=fin(fa[x]);
}
void _() {
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i].x), a[i].id=i, fa[i]=i;
    for(i=n-1;i>=1;i--) {
        std::sort(a+1,a+n+1,[&](const pair &ii,const pair &jj){return ii.x%i<jj.x%i;});
        for(j=1;j<n;j++) {
            if(a[j].x%i==a[j+1].x%i) {
                int fu=fin(a[j].id),fv=fin(a[j+1].id);
                if(fu!=fv) {
                    ansx[i]=a[j].id;
                    ansy[i]=a[j+1].id;
                    fa[fu]=fv;
                    break;
                }
            }
        }
    }
    puts("YES");
    for(i=1;i<n;i++) printf("%d %d\n",ansx[i],ansy[i]);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
