# include <bits/stdc++.h>
# define report (args...) return printf(args), void()
// # define N 1010
// int f[N];
void _() {
    int n,k;
    scanf("%d%d",&n,&k);
    // f[1]=0;
    // for(i=2;i<=n;i++) f[i]=(k-i%k)*f[i/k]+(i%k)*f[(i+k-1)/k]+1;
    printf("%d\n",(n+k-3)/(k-1));
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
