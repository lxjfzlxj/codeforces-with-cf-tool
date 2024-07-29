# include <bits/stdc++.h>
# define report(args...) return printf(args), void()

void _() {
    int n,i,mx=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) {
        int x;
        scanf("%d",&x);
        if(i&1) mx=std::max(mx,x);
    }
    printf("%d\n",mx);
}

int main() {
    int T=1;
    scanf("%d",&T);
    while(T--) _();
    return 0;
}
