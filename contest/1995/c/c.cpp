# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int a[N],c[N],l2[1000010];
long long mul=1;
int pw(int x,int y) {
    int cc=0;
    mul=1;
    while(mul<y) mul*=x, cc++;
    return cc;
}
void _() {
    int n,i,x;
    long long ans=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",a+i);
    for(x=2;x<=1000000;x*=2) l2[x]=l2[x/2]+1;
    for(i=2;i<=n;i++) {
        if(a[i]==1 && a[i-1]>1) report("-1\n");
        if(a[i-1]==1) c[i]=0;
        else {
            if(a[i]==a[i-1]) c[i]=c[i-1];
            else if(a[i]<a[i-1]) {
                int cc=pw(a[i],a[i-1]);
                if(mul==a[i-1]) {
                    if(l2[cc]) c[i]=c[i-1]+l2[cc];
                    else c[i]=c[i-1]+(int)ceil(log2(cc));
                }
                else c[i]=c[i-1]+(int)ceil(log2(log(a[i-1])/log(a[i])));
            }
            else {
                int cc=pw(a[i-1],a[i]);
                if(mul==a[i]) {
                    if(l2[cc]) c[i]=c[i-1]-l2[cc];
                    else c[i]=c[i-1]-(int)floor(log2(cc));
                }
                else c[i]=c[i-1]-(int)floor(log2(log(a[i])/log(a[i-1])));
            }
        }
        c[i]=std::max(c[i],0);
        ans+=c[i];
        // printf("%d: %d\n",i,c[   i]);
    }
    printf("%lld\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
