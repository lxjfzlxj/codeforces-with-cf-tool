# include <bits/stdc++.h>
# define report(args...) return printf(args), void()
# define N 20
int a[N][N];
void _() {
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) scanf("%d",a[i]+j);
    }
    if(n==1 && m==1) report("-1\n");
    for(i=1;i<=n;i++) {
        for(j=1;j<=m;j++) printf("%d ",a[i%n+1][j%m+1]);
        puts("");
    }
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
