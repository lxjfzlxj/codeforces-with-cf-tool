# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 200010
int f[N][1<<4],a[N];
void _() {
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",a+i);
    for(i=0;i<=n;i++) memset(f[i],63,sizeof(f[i]));
    f[0][0]=0;
    for(i=1;i<=n;i++) {
        int mn=2e9;
        for(j=0;j<16;j++) mn=std::min(mn,f[i-1][j]);
        f[i][0]=mn+(a[i]?1:0);
        if(a[i]<=4) {
            int tot=(1<<a[i])-1;
            for(j=0;j<16;j++) if(f[i-1][j]<1e9) {
                if((j&tot)==tot) f[i][0]=std::min(f[i][0],f[i-1][j]);
                if(((j|3)&tot)==tot) f[i][3]=std::min(f[i][3],f[i-1][j]+1);
                if(((j|6)&tot)==tot) f[i][6]=std::min(f[i][6],f[i-1][j]+1);
                if(((j|12)&tot)==tot) f[i][12]=std::min(f[i][12],f[i-1][j]+1);
                if(((j|15)&tot)==tot) f[i][15]=std::min(f[i][15],f[i-1][j]+2);
            }
        }
        // for(j=0;j<16;j++) printf("%d %d: %d\n",i,j,f[i][j]);
    }
    int ans=2e9;
    for(i=0;i<16;i++) ans=std::min(ans,f[n][i]);
    printf("%d\n",ans);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
